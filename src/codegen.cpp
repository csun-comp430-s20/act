#include <stdexcept>
#include "codegen.hpp"
	

namespace act {

struct genExpr {
    String operator()(VarExpr const& e) {
        return e.name;
    }

    String operator()(BinOpExpr const& e) {
        return gen_expr(*e.left) +
                opString(e.op) +
                gen_expr(*e.right);
    }

    String operator()(IntExpr const& e) {
        return to_string(e.value);
    }

    String operator()(StrExpr const& e) {
        return e.value;
    }

    String operator()(BoolExpr const& e) {
        return e.value ? "true" : "false";
    }
};

struct genStmt {
    GenEnv env;

    void operator()(WhileStmt const& s) {
        env << "while(" <<
            gen_expr(s.cond) <<
            ") {\n";

        env << CodeTabIn();
        for(auto & stmt: s.block.stmts) {
            gen_stmt(env, stmt);
        }
        env << CodeTabOut() << CodeTabs() << "}\n";
    }

    void operator()(IfStmt const& s) {
        if(s.conds.size() > 1) {
            if(s.has_else) {
                bool first = true;
                unsigned ctr = 0;
                for(auto & b: s.blocks) {
                    if(first) {
                        env << "if(" <<
                            gen_expr(s.conds[ctr]) <<
                            ") {\n";
                        
                        env << CodeTabIn();
                        for(auto & stmt: b.stmts) {
                            gen_stmt(env, stmt);
                        }
                        env << CodeTabOut() << CodeTabs() << "} ";

                        first = false;
                        ctr++;
                    } else {
                        if(ctr < s.blocks.size()-1) {
                            env << "else if(" <<
                                gen_expr(s.conds[ctr]) <<
                                ") {\n";
                            
                            env << CodeTabIn();
                            for(auto & stmt: b.stmts) {
                                gen_stmt(env, stmt);
                            }
                            env << CodeTabOut() << CodeTabs() << "} ";

                            ctr++;
                        } else {
                            env << "else {\n";
                            env << CodeTabIn() << CodeTabs();
                            for(auto & stmt: b.stmts) {
                                gen_stmt(env, stmt);
                            }
                            env << CodeTabOut() << CodeTabs() << "}\n";
                        }
                    }
                }
            } else {
                bool first = true;
                unsigned ctr = 0;
                for(auto & b: s.blocks) {
                    if(first) {
                        env << "if(" <<
                            gen_expr(s.conds[ctr]) <<
                            ") {\n";
                        
                        env << CodeTabIn();
                        for(auto & stmt: b.stmts) {
                            gen_stmt(env, stmt);
                        }
                        env << CodeTabOut() << CodeTabs() << "} ";

                        first = false;
                        ctr++;
                    } else {
                        env << "else if(" <<
                            gen_expr(s.conds[ctr]) <<
                            ") {\n";
                        
                        env << CodeTabIn() << CodeTabs();
                        for(auto & stmt: b.stmts) {
                            gen_stmt(env, stmt);
                        }
                        env << CodeTabOut() << CodeTabs() << "}";

                        ctr++;
                    }
                }

                env << "\n";
            }
        } else {
            if(s.has_else) {
                env << "if(" <<
                    gen_expr(s.conds[0]) <<
                    ") {\n";
                
                env << CodeTabIn();
                for(auto & stmt: s.blocks[0].stmts) {
                    gen_stmt(env, stmt);
                }
                env << CodeTabOut() << CodeTabs() << "} ";
                
                env << "else {\n";
                env << CodeTabIn();
                for(auto & stmt: s.blocks[1].stmts) {
                    gen_stmt(env, stmt);
                }
                env << CodeTabOut() << CodeTabs() << "}\n";
            } else {
                env << "if(" <<
                    gen_expr(s.conds[0]) <<
                    ") {\n";
                
                env << CodeTabIn();
                for(auto & stmt: s.blocks[0].stmts) {
                    gen_stmt(env, stmt);
                }
                env << CodeTabOut() << CodeTabs() << "}\n";
            }
        }
    }
    
    void operator()(DecStmt const& s) {
        env << CodeTabs() << s.type.toString() <<
                " " <<
                s.name <<
                " = " <<
                gen_expr(s.expr) <<
                ";\n";

    }

    void operator()(AssignStmt const& s) {
        env << CodeTabs() << s.name <<
                " = " <<
                gen_expr(s.expr) <<
                ";\n";
    }
};

String gen_expr(Expr const& expr) {
    return std::visit(genExpr{}, expr);
}
void gen_stmt(GenEnv& env, Stmt const& stmt) {
    std::visit(genStmt{ std::move(env) }, stmt);
}

String gen_code(Program const& program) {
    GenEnv env;
    
    // env << CodeTabIn();
    // for (Stmt const& stmt : program.stmts) {
    //     env << CodeTabs() << stmt;
    // }
    // env << CodeTabOut();

    return env.prolog() + "\n" + env.epilog();
}

GenEnv::GenEnv() {}

std::stringstream& GenEnv::write() {
    return _codeDef;
}
GenEnv& GenEnv::operator<<(String const& str) {
    write() << str;
    return *this;
}
GenEnv& GenEnv::operator<<(CodeTabs const&) {
    write() << String(_tabs, '\t');
    return *this;
}
GenEnv& GenEnv::operator<<(CodeTabIn const&) {
    _tabs++;
    return *this;
}
GenEnv& GenEnv::operator<<(CodeTabOut const&) {
    if(_tabs == 0) {
        throw std::logic_error("tabed below zero");
    }

    --_tabs;
    return *this;
}

GenEnv& GenEnv::operator<<(Expr const& e) {
    write() << gen_expr(e);
    return *this;
}

String GenEnv::prolog() const {
    String s = R"(
#include <string>

using namespace std;

)";

    return s;
}
String GenEnv::epilog() const
{
    String s;

    s = s
      + "int main() {\n"
      + _codeDef.str()
      + "\n\treturn 0;\n"
      + "}\n";

    return s;
}

} // namespace act
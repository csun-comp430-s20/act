#include <stdexcept>
#include <iostream>
#include "codegen.hpp"
	

namespace act {

struct genExpr {
    String operator()(VarExpr const& e) {
        return "g_" + e.name;
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

    void operator()(ExitStmt const& s) {
        env << CodeTabs() << "exit(" <<
            gen_expr(s.value) << ");";
    }

    void operator()(WhileStmt const& s) {
        env << CodeTabs() << "while(" <<
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
                        env << CodeTabs() << "if(" <<
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
                            env << CodeTabs() << "else if(" <<
                                gen_expr(s.conds[ctr]) <<
                                ") {\n";
                            
                            env << CodeTabIn();
                            for(auto & stmt: b.stmts) {
                                gen_stmt(env, stmt);
                            }
                            env << CodeTabOut() << CodeTabs() << "} ";

                            ctr++;
                        } else {
                            env << CodeTabs() << "else {\n";
                            env << CodeTabIn();
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
                        env << CodeTabs() << "if(" <<
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
                        
                        env << CodeTabIn();
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
                " g_" <<
                s.name <<
                " = " <<
                gen_expr(s.expr) <<
                ";\n";

    }

    void operator()(AssignStmt const& s) {
        env << CodeTabs() << "g_" << s.name <<
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
void gen_goifstmt(GenEnv& env, GoIfStmt const& s) {
    env << CodeTabs() << "if(";

    bool first = true;
    unsigned ctr = 0;
    if(!s.has_else) {
        for(auto & b: s.blocks) {
            if(first) { // print if statement
                env << gen_expr(s.conds[ctr])
                    << ") {\n";
                
                env << CodeTabIn();
                for(auto & stmt: b.stmts) {
                    gen_stmt(env, stmt);
                }

                env << CodeTabIn() << CodeTabs() << "return make_unique<" <<
                    s.names[ctr] << ">(o_" << s.names[ctr] << ");\n";

                env << CodeTabOut() << CodeTabs() << "}";

                first = false;
                ctr++;
            } else {
                env << " else if("
                    << gen_expr(s.conds[ctr])
                    << ") {\n";
                
                env << CodeTabIn();
                for(auto & stmt: b.stmts) {
                    gen_stmt(env, stmt);
                }

                env << CodeTabIn() << CodeTabs() << "return make_unique<" <<
                    s.names[ctr] << ">(o_" << s.names[ctr] << ");\n";

                env << CodeTabOut() << CodeTabs() << "}";
                ctr++;
            }
        }
    } else {
        for(unsigned b_ctr = 0; b_ctr < s.blocks.size(); b_ctr++) {
            if(b_ctr != s.blocks.size()-1) {
                if(first) {
                    env << gen_expr(s.conds[ctr])
                        + ") {\n";
                    
                    env << CodeTabIn();
                    for(auto & stmt: s.blocks[b_ctr].stmts) {
                        gen_stmt(env, stmt);
                    }

                    env << CodeTabIn() << CodeTabs() << "return make_unique<" <<
                        s.names[ctr] << ">(o_" << s.names[ctr] << ");\n";

                    env << CodeTabOut() << CodeTabs() << "}";
                    first = false;
                    ctr++;
                } else {
                    env << " else if("
                        << gen_expr(s.conds[ctr])
                        << ") {\n";
                    
                    env << CodeTabIn();
                    for(auto & stmt: s.blocks[b_ctr].stmts) {
                        gen_stmt(env, stmt);
                    }

                    env << CodeTabIn() << CodeTabs() << "return make_unique<" <<
                        s.names[ctr] << ">(o_" << s.names[ctr] << ");\n";

                    env << CodeTabOut() << CodeTabs() << "}";
                    ctr++;
                }
            } else { // print else statement
                env << " else {\n";
                
                env << CodeTabIn();
                for(auto & stmt: s.blocks[b_ctr].stmts) {
                    gen_stmt(env, stmt);
                }

                env << CodeTabIn() << CodeTabs() << "return make_unique<" <<
                    s.names[ctr] << ">(o_" << s.names[ctr] << ");\n";

                env << CodeTabOut() << CodeTabs() << "}";
            }
        }
    }

    env << "\n";
}
void gen_onstmt(GenEnv& env, OnStmt const& stmt) {
    env << CodeTabIn();
    gen_goifstmt(env, stmt.gostmt);
}
void gen_statestmt(GenEnv& env, StateStmt const& stmt) {
    env << "unique_ptr<State> " << stmt.name <<
        "::nextState() {\n";
    
    if(stmt.onstmts.size() != 1) {
        throw std::logic_error("Each state should only have one on statement");
    }

    gen_onstmt(env, stmt.onstmts[0]);

    env << CodeTabOut() << CodeTabs() << "}\n";

    for(auto const& s: stmt.states) {
        gen_statestmt(env, s);
    }
}

String gen_code(TypeEnv const& typenv, Program const& program) {
    GenEnv env(typenv);

    gen_statestmt(env, program.main_state);

    return env.prolog() + env.static_decs() + env.concat() + env.epilog();
}

GenEnv::GenEnv(TypeEnv const& typeEnv)
    : _env(typeEnv) {}

std::stringstream GenEnv::_codeDef;

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
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class State {
    public:
    virtual unique_ptr<State> nextState() {
        return make_unique<State>(*this);
    }
};

)";

    return s;
}
String GenEnv::static_decs() const {
    String s = "";

    for(auto & state: _env.states) {
        s += "class " + state + ": public State {\n" +
            "\tpublic:\n\tunique_ptr<State> nextState();\n" +
            "};\n";
    }

    s += "\n";

    for(auto & state: _env.states) {
        s += "static " + state + " o_" + state + ";\n";
    }

    s += "\n";

    for(auto const& x: _env.varMap) {
        s += "static " + x.first.type.name() + " " +
            "g_" + x.first.name + " = " + x.second + ";\n";
    }

    return s + "\n";
}
String GenEnv::concat() const {
    return _codeDef.str();
}
String GenEnv::epilog() const {
    String s = R"(
int main() {
    unique_ptr<State> state = make_unique<life>(o_life);

    while(true) {
        state = state->nextState();
    }

    return 0;
}

)";

    return s;
}

} // namespace act
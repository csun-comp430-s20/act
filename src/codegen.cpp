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
        env << CodeTabOut();
    }

    String operator()(IfStmt const& s) {

    }
    
    String operator()(DecStmt const& s) {
        env << s.type.toString() <<
                " " <<
                s.name <<
                " = " <<
                gen_expr(*s.exprs) <<
                ";\n";

    }

    String operator()(AssignStmt const& s) {
        env << s.name <<
                " = " <<
                gen_expr(*s.exprs) <<
                ";\n";
    }
};

String gen_expr(Expr const& expr) {
    return std::visit(genExpr{}, expr);
}
void gen_stmt(GenEnv const& env, Stmt const& stmt) {
    std::visit(genStmt{ env }, stmt);
}

String gen_code(Program const& program, TypeEnv const& typeEnv) {
    GenEnv env(typeEnv);
    
    env << CodeTabIn();
    for (Stmt const& stmt : program.stmts) {
        env << CodeTabs() << stmt;
    }
    env << CodeTabOut();

    return env.prolog() + "\n" + env.epilog();
}

GenEnv::GenEnv(TypeEnv const& typeEnv) {}

std::stringstream& GenEnv::write() {
    return _codeDef;
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
GenEnv& GenEnv::operator<<(Stmt const& s) {
    write() << gen_stmt(s);
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
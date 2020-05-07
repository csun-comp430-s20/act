#include <stdexcept>
#include "codegen.hpp"
	

namespace act {

struct genExpr {
    String operator()(BinOpExpr const& e) {
        return gen_expr(*e.left) +
                opString(e.op) +
                gen_expr(*e.right);
    }

    String operator()(IntExpr const& e) {
        return e.code;
    }

    String operator()(StrExpr const& e) {
        return e.code;
    }

    String operator()(BoolExpr const& e) {
        return e.code;
    }
};

struct genStmt {
    String operator()(DefEvent const& s) {
        return "";
    }

    String operator()(CallEvent const& s) {
        return "";
    }
    
    String operator()(DecStmt const& s) {
        return s.type.toString() +
                " " +
                s.name +
                " = " +
                gen_expr(*s.exprs) +
                ";\n";

    }

    String operator()(AssignStmt const& s) {
        return s.name +
                " = " +
                gen_expr(*s.exprs) +
                ";\n";
    }
};

String gen_expr(Expr const& expr) {
    return std::visit(genExpr{}, expr);
}
String gen_stmt(Stmt const& stmt) {
    return std::visit(genStmt{}, stmt);
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

// void GenEnv::declareLocal(String const& name, ValueType const& type)
// {
//     // if (!_curMethod)
//     // {
//     //     throw std::logic_error("declareLocal with no curMethod");
//     // }

//     _scopes.declLocal(name, type);
// }

// ValueType const& GenEnv::getLocalType(String const& name) const {
//     Decl const* decl = _scopes.lookup(name);

//     if (!decl)
//     {
//         throw std::logic_error("no local with name '" + name + "'");
//     }

//     if (decl->declType != DeclType::local)
//     {
//         throw std::logic_error("decl '" + name + "' is not a local");
//     }

//     return decl->type;
// }
// ValueType const* GenEnv::lookupLocalType(String const& name) const {
//     Decl const* decl = _scopes.lookup(name);

//     if (!decl)
//     {
//         return nullptr;
//     }

//     if (decl->declType != DeclType::local)
//     {
//         return nullptr;
//     }

//     return &decl->type;
// }

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
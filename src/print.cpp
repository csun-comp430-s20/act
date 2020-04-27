#include "print.hpp"

namespace act {

struct GetId {
    template <typename T>
    Id operator()(T const& t) { return t.tid; }
};

struct GetStr {
    template <typename T>
    String operator()(T const& t) { return t.to_string(); }
};

struct GetTypeStr {
    template <typename T>
    String operator()(T const& t) { return t.toString(); }
};

struct PrintStmt {
    String operator()(DecStmt const& s) {
        String str;
        str = "("
            + print_type(s.type) 
            + " (" 
            + s.name
            + ") (=) ";
        
        str += print_expr(*s.exprs);

        return str + ")";
    }

    String operator()(AssignStmt const& s) {
        String str;
        str = "("
            + s.name
            + " = ";
        
        str += print_expr(*s.exprs);

        return str + ")";
    }
};

struct PrintExpr {
    String operator()(BinOpExpr const& e) {
        return "("
            + print_expr(*e.left)
            + " "
            + print_op(e.op)
            + " "
            + print_expr(*e.right)
            + ")";
    }

    String operator()(IntExpr const& e) {
        return "(" + to_string(e.value) + ")";
    }

    String operator()(StrExpr const& e) {
        return "(" + e.value + ")";
    }

    String operator()(BoolExpr const& e) {
        return "(" + to_string(e.value) + ")";
    }
};

String print_type(Type const& t) {
    return "(" + std::visit(GetTypeStr{}, t) + ")";
}

String print_op(BinOp const& op) {
    String str;

    switch (op) {
        case BinOp::opPlus: str = "+"; break;
        case BinOp::opLess: str = "<"; break;
        case BinOp::opGreater: str = ">"; break;
        case BinOp::opEqual: str = "=="; break;
    }

    return "(" + str + ")";
}

String print_id(Id const& i) {
    return "[" + to_string(static_cast<int>(i)) + "]";
}

String print_token(Token const& token) {
    return std::visit(GetStr{}, token);
}

String print_fancy_token(Token const& token) {
    return print_id(std::visit(GetId{}, token))
            + std::visit(GetStr{}, token);
}

String print_expr(Expr const& expr) {
    return std::visit(PrintExpr{}, expr);
}

String print_stmt(Stmt const& stmt) {
    return std::visit(PrintStmt{}, stmt);
}

String print_program(Program const& program) {
    String result;

    for (Stmt const& expr : program.stmts) {
        result += print_stmt(expr) + "\n";
    }

    return result;
}

} // namespace act

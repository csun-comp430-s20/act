#include "print.hpp"

namespace act {

struct GetId {
    Id operator()(TokenLPar const& t)       { return t.tid; }
    Id operator()(TokenRPar const& t)       { return t.tid; }
    Id operator()(TokenComma const& t)      { return t.tid; }
    Id operator()(TokenSemi const& t)       { return t.tid; }
    Id operator()(TokenAssign const& t)     { return t.tid; }
    Id operator()(TokenPlus const& t)       { return t.tid; }
    Id operator()(TokenLess const& t)       { return t.tid; }
    Id operator()(TokenGreater const& t)    { return t.tid; }
    Id operator()(TokenEqual const& t)      { return t.tid; }
    Id operator()(TokenIf const& t)         { return t.tid; }
    Id operator()(TokenElse const& t)       { return t.tid; }
    Id operator()(TokenIntType const& t)    { return t.tid; }
    Id operator()(TokenBoolType const& t)   { return t.tid; }
    Id operator()(TokenStringType const& t) { return t.tid; }
    Id operator()(TokenName const& t)       { return t.tid; }
    Id operator()(TokenIntVal const& t)     { return t.tid; }
    Id operator()(TokenStringVal const& t)  { return t.tid; }
    Id operator()(TokenTrue const& t)       { return t.tid; }
    Id operator()(TokenFalse const& t)      { return t.tid; }
};

struct GetStr {
    String operator()(TokenLPar const& t)       { return t.to_string(); }
    String operator()(TokenRPar const& t)       { return t.to_string(); }
    String operator()(TokenComma const& t)      { return t.to_string(); }
    String operator()(TokenSemi const& t)       { return t.to_string(); }
    String operator()(TokenAssign const& t)     { return t.to_string(); }
    String operator()(TokenPlus const& t)       { return t.to_string(); }
    String operator()(TokenLess const& t)       { return t.to_string(); }
    String operator()(TokenGreater const& t)    { return t.to_string(); }
    String operator()(TokenEqual const& t)      { return t.to_string(); }
    String operator()(TokenIf const& t)         { return t.to_string(); }
    String operator()(TokenElse const& t)       { return t.to_string(); }
    String operator()(TokenIntType const& t)    { return t.to_string(); }
    String operator()(TokenBoolType const& t)   { return t.to_string(); }
    String operator()(TokenStringType const& t) { return t.to_string(); }
    String operator()(TokenName const& t)       { return t.to_string(); }
    String operator()(TokenIntVal const& t)     { return t.to_string(); }
    String operator()(TokenStringVal const& t)  { return t.to_string(); }
    String operator()(TokenTrue const& t)       { return t.to_string(); }
    String operator()(TokenFalse const& t)      { return t.to_string(); }
};

struct PrintStmt {
    String operator()(DecStmt const& s) {
        String str;
        str = "("
            + print_type(s.type) 
            + " (" 
            + s.name
            + ") (=) ";
        
        for(auto&& expr : *s.exprs) {
            str += print_expr(*expr);
        }

        return str + ")";
    }

    String operator()(AssignStmt const& s) {
        String str;
        str = "("
            + s.name
            + " = ";
        
        for(auto&& expr : *s.exprs) {
            str += print_expr(*expr);
        }

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
    String str;

    switch (t) {
        case Type::integer: str = "int"; break;
        case Type::boolean: str = "bool"; break;
        case Type::string: str = "string"; break;
    }

    return "(" + str + ")";
}

String print_op(BinOp const& op) {
    String str;

    switch (op) {
        case BinOp::add: str = "+"; break;
        case BinOp::less: str = ">"; break;
        case BinOp::greater: str = "<"; break;
        case BinOp::equal: str = "=="; break;
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

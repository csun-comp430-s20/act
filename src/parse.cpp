#include "parse.hpp"

namespace act {

// Program: Stmt*
Parsed<Program> parse_program(Input& input) {
    Vector<Stmt> stmts;

    while (!input.at_end()) {
        TRY(stmt, parse_stmt(input));
        stmts.push_back(std::move(stmt));
    }

    return Program{
        std::move(stmts)
    };
}
// Stmt: DecStmt | AssignStmt
Parsed<Stmt> parse_stmt(Input& input) {
    return any(input, "expected stmt",
        parse_decstmt,
        parse_assignstmt
    );
}
// DecStmt: Type Name '=' Expr* ';'
Parsed<Stmt> parse_decstmt(Input& input) {
    auto rollback = input.mark_rollback();
    // Vector<std::unique_ptr<Expr>> exprs;

    TRY(type, parse_type(input));
    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenAssign>());
    TRY(expr, parse_expr(input));
    TRY_(input.expect<TokenSemi>());

    rollback.cancel();
    return DecStmt{
        type,
        name.value,
        into_ptr(expr)
    };
}
// AssignStmt: Name '=' Expr* ';'
Parsed<Stmt> parse_assignstmt(Input& input) {
    auto rollback = input.mark_rollback();
    // Vector<std::unique_ptr<Expr>> exprs;

    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenAssign>());
    TRY(expr, parse_expr(input));
    TRY_(input.expect<TokenSemi>());

    rollback.cancel();
    return AssignStmt{
        name.value,
        into_ptr(expr)
    };
}
Parsed<Type> parse_type(Input& input) {
    if (input.match<TokenIntType>()) {
        return intType;
    }
    else if (input.match<TokenBoolType>()) {
        return boolType;
    }
    else if (input.match<TokenStringType>()) {
        return stringType;
    }
    else {
        return ParseError{ "expected type" };
    }
}
// Expr: Val | Val BinOp Expr
Parsed<Expr> parse_expr(Input& input) {
    return any(input, "expected expr",
        parse_binexpr,
        parse_val
    );
}
// Using right recursion here
Parsed<Expr> parse_binexpr(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(left,  parse_val(input));
    TRY(op,    parse_binop(input));
    TRY(right, parse_expr(input));

    rollback.cancel();
    return BinOpExpr{
        into_ptr<Expr>(left),
        op,
        into_ptr<Expr>(right)
    };
}
// BinOp: '+' | '<' | '>' | '=='
Parsed<BinOp> parse_binop(Input& input) {
    if (input.match<TokenPlus>()) {
        return BinOp::opPlus;
    }
    else if (input.match<TokenLess>()) {
        return BinOp::opLess;
    }
    else if (input.match<TokenGreater>()) {
        return BinOp::opGreater;
    }
    else if (input.match<TokenEqual>()) {
        return BinOp::opEqual;
    }
    else {
        return ParseError{ "expected binop" };
    }
}
// Val: int | string | 'true' | 'false' | '(' Expr ')'
Parsed<Expr> parse_val(Input& input) {
    return any(input, "value expr",
        parse_paren,
        parse_false,
        parse_true,
        parse_str,
        parse_int
    );
}
Parsed<Expr> parse_paren(Input& input) {
    auto rollback = input.mark_rollback();

    TRY_(input.expect<TokenLPar>());
    TRY(expr, parse_expr(input));
    TRY_(input.expect<TokenRPar>());

    rollback.cancel();
    return expr;
}
Parsed<Expr> parse_false(Input& input) {
    auto rollback = input.mark_rollback();

    TRY_(input.expect<TokenFalse>());

    rollback.cancel();
    return BoolExpr{ false };
}
Parsed<Expr> parse_true(Input& input) {
    auto rollback = input.mark_rollback();

    TRY_(input.expect<TokenTrue>());

    rollback.cancel();
    return BoolExpr{ true };
}
Parsed<Expr> parse_str(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(str, input.get<TokenStringVal>());

    rollback.cancel();
    return StrExpr{ str.value };
}
Parsed<Expr> parse_int(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(num, input.get<TokenIntVal>());

    rollback.cancel();
    return IntExpr{ num.value };
}

} // namespace act
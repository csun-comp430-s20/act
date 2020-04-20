#pragma once

#include "ast.hpp"
#include "parse_input.hpp"
#include "parse_result.hpp"
#include "misc.hpp"

/*
Grammar
    Program     : Stmt*
    Stmt        : DecStmt | AssignStmt
    DecStmt     : Type Name '=' Expr* ';'
    AssignStmt  : Name '=' Expr* ';'
    Expr        : Val | Val BinOp Val
    BinOp       : '+' | '<' | '>' | '=='
    Val         : int | string | 'true' | 'false' | '(' Expr ')'
*/

namespace act {

Parsed<Program> parse_program(Input&);
Parsed<Stmt> parse_stmt(Input&);
Parsed<Stmt> parse_decstmt(Input&);
Parsed<Stmt> parse_assignstmt(Input&);
Parsed<Type> parse_type(Input&);
Parsed<Expr> parse_expr(Input&);
Parsed<Expr> parse_binexpr(Input&);
Parsed<BinOp> parse_binop(Input&);
Parsed<Expr> parse_val(Input&);
Parsed<Expr> parse_paren(Input&);
Parsed<Expr> parse_false(Input&);
Parsed<Expr> parse_true(Input&);
Parsed<Expr> parse_str(Input&);
Parsed<Expr> parse_int(Input&);

template <typename T>
using Parser = Parsed<T>(*)(Input&);

// Returns the result of the first parser that succeeds.
// If none succeed, rolls back and returns an error from the "expecting" argument.
template <typename T, typename... Ts>
auto any(Input& input, char const* expecting, Parser<T> first, Ts... rest) -> Parsed<T> {
    auto rollback = input.mark_rollback();
    
    // Put all the arguments in an array so they can be iterated over normally.
    Parser<T> fns[] = { first, rest... };

    for (auto f : fns) {
        Parsed<T> p = f(input);

        if (p) {
            rollback.cancel();
            return p;
        }
    }

    return ParseError{ String("expected ") + expecting };
}

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
    Vector<std::unique_ptr<Expr>> exprs;

    TRY(type, parse_type(input));
    TRY(name, input.get<TokenName>());
    if (!input.match<TokenAssign>()) {
        return ParseError{ "expected assign" };
    }

    do {
        TRY(expr, parse_expr(input));
        exprs.push_back(into_ptr<Expr>(expr));
    } while(!input.match<TokenSemi>() && !input.at_end());

    rollback.cancel();
    return DecStmt{
        type,
        name.value,
        into_ptr<Vector<std::unique_ptr<Expr>>>(exprs)
    };
}
// AssignStmt: Name '=' Expr* ';'
Parsed<Stmt> parse_assignstmt(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<std::unique_ptr<Expr>> exprs;

    TRY(name, input.get<TokenName>());
    if (!input.match<TokenAssign>()) {
        return ParseError{ "expected assign" };
    }

    do {
        TRY(expr, parse_expr(input));
        exprs.push_back(into_ptr<Expr>(expr));
    } while(!input.match<TokenSemi>() && !input.at_end());

    rollback.cancel();
    return AssignStmt{
        name.value,
        into_ptr<Vector<std::unique_ptr<Expr>>>(exprs)
    };
}
Parsed<Type> parse_type(Input& input) {
    if (input.match<TokenIntType>()) {
        return Type::integer;
    }
    else if (input.match<TokenBoolType>()) {
        return Type::boolean;
    }
    else if (input.match<TokenStringType>()) {
        return Type::string;
    }
    else {
        return ParseError{ "expected type" };
    }
}
// Expr: Val | Val BinOp Val
Parsed<Expr> parse_expr(Input& input) {
    return any(input, "expected expr",
        parse_binexpr,
        parse_val
    );
}
Parsed<Expr> parse_binexpr(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(left,  parse_val(input));
    TRY(op,    parse_binop(input));
    TRY(right, parse_val(input));

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
        return BinOp::add;
    }
    else if (input.match<TokenLess>()) {
        return BinOp::less;
    }
    else if (input.match<TokenGreater>()) {
        return BinOp::greater;
    }
    else if (input.match<TokenEqual>()) {
        return BinOp::equal;
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
#pragma once

#include "ast.hpp"
#include "parse_input.hpp"
#include "parse_result.hpp"
#include "misc.hpp"

/*
Grammar
    Program     : Stmt*
    Stmt        : DecStmt | AssignStmt
    DecStmt     : Type Name '=' Expr+ ';'
    AssignStmt  : Name '=' Expr+ ';'
    Expr        : Val | Val BinOp Expr
    BinOp       : '+' | '<' | '>' | '=='
    Val         : int | string | 'true' | 'false' | '(' Expr ')'
*/

namespace act {

Parsed<Program> parse_program(Input&);
Parsed<StateStmt> parse_statestmt(Input&);
Parsed<OnStmt> parse_onstmt(Input&);
Parsed<GoIfStmt> parse_goifstmt(Input&);
Parsed<DefEvent> parse_defevent(Input&);
Parsed<DecStmt> parse_decstmt_only(Input&);
Parsed<Stmt> parse_base_stmt(Input&);
Parsed<Stmt> parse_ifstmt(Input&);
Parsed<Stmt> parse_whilestmt(Input&);
Parsed<Stmt> parse_exitstmt(Input&);
Parsed<Stmt> parse_decstmt(Input&);
Parsed<Stmt> parse_assignstmt(Input&);
Parsed<ValueType> parse_value_type(Input&);
Parsed<Expr> parse_expr(Input&);
Parsed<Expr> parse_binexpr(Input&);
Parsed<BinOp> parse_binop(Input&);
Parsed<Expr> parse_var(Input&);
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

    return ParseError{ expecting };
}

} // namespace act
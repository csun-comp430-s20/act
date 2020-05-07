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

Parsed<Stmt> parse_stmt(Input& input) {
    return any(input, "expected stmt",
        parse_decstmt,
        parse_assignstmt,
        parse_defevent,
        parse_callevent,
        parse_ifstmt,
        parse_whilestmt
    );
}

Parsed<Stmt> parse_goifstmt(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<Expr> conds;
    Vector<String> names;
    Vector<Block> blocks;
    Vector<Stmt> stmts;
    bool has_else = false;

    TRY_(input.expect<TokenGoIf>());
    TRY_(input.expect<TokenLPar>());
    TRY(exprif, parse_expr(input));
    conds.push_back(std::move(exprif));
    TRY_(input.expect<TokenRPar>());
    TRY(nameif, input.get<TokenName>());
    names.push_back(nameif);
    TRY_(input.expect<TokenLBrace>());

    while(!input.expect<TokenRBrace>()) {
        TRY(stmt, parse_stmt(input));
        stmts.push_back(std::move(stmt));
    }

    blocks.push_back(std::move(Block{ std::move(stmts) }));

    while(input.expect<TokenGoElIf>()) {
        TRY_(input.expect<TokenLPar>());
        TRY(exprelif, parse_expr(input));
        conds.push_back(std::move(exprelif));
        TRY_(input.expect<TokenRPar>());
        TRY(nameelif, input.get<TokenName>());
        names.push_back(nameelif);
        TRY_(input.expect<TokenLBrace>());

        stmts.clear();
        while(!input.expect<TokenRBrace>()) {
            TRY(stmt, parse_stmt(input));
            stmts.push_back(std::move(stmt));
        }

        blocks.push_back(std::move(Block{ std::move(stmts) }));
    }

    if(input.expect<TokenGoElse>()) {
        has_else = true;
        TRY(nameelseif, input.get<TokenName>());
        names.push_back(nameelseif);
        TRY_(input.expect<TokenLBrace>());

        stmts.clear();
        while(!input.expect<TokenRBrace>()) {
            TRY(stmt, parse_stmt(input));
            stmts.push_back(std::move(stmt));
        }
        
        blocks.push_back(std::move(Block{ std::move(stmts) }));
    }

        rollback.cancel();
        return GoIfStmt{
            std::move(conds),
            std::move(names),
            std::move(blocks),
            has_else
    };
}
Parsed<Stmt> parse_ifstmt(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<Expr> conds;
    Vector<Block> blocks;
    Vector<Stmt> stmts;
    bool has_else = false;

    TRY_(input.expect<TokenIf>());
    TRY_(input.expect<TokenLPar>());
    TRY(exprif, parse_expr(input));
    conds.push_back(std::move(exprif));
    TRY_(input.expect<TokenRPar>());
    TRY_(input.expect<TokenLBrace>());

    while(!input.expect<TokenRBrace>()) {
        TRY(stmt, parse_stmt(input));
        stmts.push_back(std::move(stmt));
    }

    blocks.push_back(std::move(Block{ std::move(stmts) }));

    while(input.expect<TokenElIf>()) {
        TRY_(input.expect<TokenLPar>());
        TRY(exprelif, parse_expr(input));
        conds.push_back(std::move(exprelif));
        TRY_(input.expect<TokenRPar>());
        TRY_(input.expect<TokenLBrace>());

        stmts.clear();
        while(!input.expect<TokenRBrace>()) {
            TRY(stmt, parse_stmt(input));
            stmts.push_back(std::move(stmt));
        }

        blocks.push_back(std::move(Block{ std::move(stmts) }));
    }

    if(input.expect<TokenElse>()) {
        has_else = true;
       TRY_(input.expect<TokenLBrace>());

       stmts.clear();
       while(!input.expect<TokenRBrace>()) {
            TRY(stmt, parse_stmt(input));
            stmts.push_back(std::move(stmt));
        }

        blocks.push_back(std::move(Block{ std::move(stmts) }));
    }

    rollback.cancel();
    return IfStmt{
        std::move(conds),
        std::move(blocks),
        has_else
    };
}
Parsed<Stmt> parse_whilestmt(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<Stmt> stmts;

    TRY_(input.expect<TokenWhile>());
    TRY_(input.expect<TokenLPar>());
    TRY(cond, parse_expr(input));
    TRY_(input.expect<TokenRPar>());
    TRY_(input.expect<TokenLBrace>());

    while(!input.expect<TokenRBrace>()) {
        TRY(stmt, parse_stmt(input));
        stmts.push_back(std::move(stmt));
    }

    rollback.cancel();
    return WhileStmt{
        std::move(cond),
        Block{ std::move(stmts) }
    };
}
// DecStmt: Type Name '=' Expr* ';'
Parsed<Stmt> parse_decstmt(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(type, parse_value_type(input));
    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenAssign>());
    TRY(expr, parse_expr(input));
    TRY_(input.expect<TokenSemi>());

    rollback.cancel();
    return DecStmt{
        type,
        name.value,
        std::move(expr)
    };
}
// AssignStmt: Name '=' Expr* ';'
Parsed<Stmt> parse_assignstmt(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenAssign>());
    TRY(expr, parse_expr(input));
    TRY_(input.expect<TokenSemi>());

    rollback.cancel();
    return AssignStmt{
        name.value,
        std::move(expr)
    };
}
Parsed<Stmt> parse_defevent(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<ValueType> types;

    TRY_(input.expect<TokenDefEvent>());
    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenLPar>());

    if(!input.check_done<TokenRPar>()) {
        TRY(type_temp, parse_value_type(input));
        types.push_back(std::move(type_temp));
    }

    while(!input.check_done<TokenRPar>()) {
        TRY_(input.expect<TokenComma>());
        TRY(type_temp, parse_value_type(input));
        types.push_back(std::move(type_temp));
    }

    TRY_(input.expect<TokenRPar>());
    TRY_(input.expect<TokenSemi>());
    
    rollback.cancel();
    return DefEvent{
        name.value,
        std::move(types)
    };
}
Parsed<Stmt> parse_callevent(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<Expr> exprs;

    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenLPar>());

    if(!input.check_done<TokenRPar>()) {
        TRY(expr, parse_expr(input));
        exprs.push_back(std::move(expr));
    }

    while(!input.check_done<TokenRPar>()) {
        TRY_(input.expect<TokenComma>());
        TRY(expr, parse_expr(input));
        exprs.push_back(std::move(expr));
    }

    TRY_(input.expect<TokenRPar>());
    
    rollback.cancel();
    return CallEvent{
        name.value,
        std::move(exprs)
    };
}

Parsed<ValueType> parse_value_type(Input& input) {
    if (input.match<TokenIntType>()) {
        return intType;
    }
    else if (input.match<TokenBoolType>()) {
        return boolType;
    }
    else if (input.match<TokenStringType>()) {
        return strType;
    }
    else {
        return ParseError{ "expected value type" };
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
        parse_var,
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
    return BoolExpr(false);
}
Parsed<Expr> parse_true(Input& input) {
    auto rollback = input.mark_rollback();

    TRY_(input.expect<TokenTrue>());

    rollback.cancel();
    return BoolExpr(true);
}
Parsed<Expr> parse_var(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(var, input.get<TokenName>());

    rollback.cancel();
    return StrExpr(var.value);
}
Parsed<Expr> parse_str(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(str, input.get<TokenStringVal>());

    rollback.cancel();
    return StrExpr(str.value);
}
Parsed<Expr> parse_int(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(num, input.get<TokenIntVal>());

    rollback.cancel();
    return IntExpr(num.value);
}

} // namespace act
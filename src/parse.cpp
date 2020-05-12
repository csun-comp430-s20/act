#include "parse.hpp"

namespace act {

// Program: Stmt*
Parsed<Program> parse_program(Input& input) {
    Vector<DefEvent> events;

    while(!input.check_done<TokenState>()) {
        TRY(event, parse_defevent(input));
        events.push_back(std::move(event));
    }

    TRY(state, parse_statestmt(input));

    if(input.at_end()) {
        return Program{
            std::move(events),
            std::move(state)
        };
    } else {
        return ParseError{ "Not at end of file" };
    }
}

Parsed<StateStmt> parse_statestmt(Input& input) {
    auto rollback = input.mark_rollback();

    StateStmt state = StateStmt{
        "",
        Vector<Stmt>(),
        Vector<OnStmt>(),
        Vector<StateStmt>()
    };

    TRY_(input.expect<TokenState>());
    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenLBrace>());

    state.name = name.value;

    while(!input.expect<TokenRBrace>()) {
        if(input.check_token<TokenState>()) {
            TRY(new_state, parse_statestmt(input));
            state.states.push_back(std::move(new_state));
        } else if(input.check_token<TokenOn>()) {
            TRY(on_stmt, parse_onstmt(input));
            state.onstmts.push_back(std::move(on_stmt));
        } else if(!input.check_token<TokenRBrace>()) {
            TRY(stmt, parse_base_stmt(input));
            state.stmts.push_back(std::move(stmt));
        } else {
            TRY_(input.expect<TokenRBrace>());
            break;
        }
    }

    rollback.cancel();
    return state;
}

Parsed<OnStmt> parse_onstmt(Input& input) {
    auto rollback = input.mark_rollback();
    TRY_(input.expect<TokenOn>());
    TRY(name, input.get<TokenName>());

    TRY_(input.expect<TokenLBrace>())
    TRY(gostmt, parse_goifstmt(input));
    TRY_(input.expect<TokenRBrace>())

    rollback.cancel();
    return OnStmt{
        name.value,
        std::move(gostmt)
    };
}
Parsed<GoIfStmt> parse_goifstmt(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<Expr> conds;
    Vector<String> names;
    Vector<Block> blocks;
    Vector<Stmt> stmts;
    bool has_else = false;

    if(input.check_token<TokenRBrace>()) {
        rollback.cancel();
        return GoIfStmt{
            std::move(conds),
            std::move(names),
            std::move(blocks),
            has_else
        };
    }

    TRY_(input.expect<TokenGoIf>());
    TRY_(input.expect<TokenLPar>());
    TRY(exprif, parse_expr(input));
    conds.push_back(std::move(exprif));
    TRY_(input.expect<TokenRPar>());
    TRY(nameif, input.get<TokenName>());
    names.push_back(nameif.value);
    TRY_(input.expect<TokenLBrace>());

    while(!input.expect<TokenRBrace>()) {
        TRY(stmt, parse_base_stmt(input));
        stmts.push_back(std::move(stmt));
    }

    blocks.push_back(std::move(Block{ std::move(stmts) }));

    while(input.expect<TokenGoElIf>()) {
        TRY_(input.expect<TokenLPar>());
        TRY(exprelif, parse_expr(input));
        conds.push_back(std::move(exprelif));
        TRY_(input.expect<TokenRPar>());
        TRY(nameelif, input.get<TokenName>());
        names.push_back(nameelif.value);
        TRY_(input.expect<TokenLBrace>());

        stmts.clear();
        while(!input.expect<TokenRBrace>()) {
            TRY(stmt, parse_base_stmt(input));
            stmts.push_back(std::move(stmt));
        }

        blocks.push_back(std::move(Block{ std::move(stmts) }));
    }

    if(input.expect<TokenGoElse>()) {
        has_else = true;
        TRY(nameelseif, input.get<TokenName>());
        names.push_back(nameelseif.value);
        TRY_(input.expect<TokenLBrace>());

        stmts.clear();
        while(!input.expect<TokenRBrace>()) {
            TRY(stmt, parse_base_stmt(input));
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
Parsed<DefEvent> parse_defevent(Input& input) {
    auto rollback = input.mark_rollback();
    Vector<DecStmt> decstmts;

    TRY_(input.expect<TokenDefEvent>());
    TRY(name, input.get<TokenName>());
    TRY_(input.expect<TokenLBrace>());

    if(!input.check_done<TokenRBrace>()) {
        TRY(stmt_temp_init, parse_decstmt(input));
        decstmts.push_back(std::move(stmt_temp_init));
    }

    while(!input.check_done<TokenRBrace>()) {
        TRY_(input.expect<TokenComma>());
        TRY(stmt_temp, parse_decstmt(input));
        decstmts.push_back(std::move(stmt_temp));
    }

    TRY_(input.expect<TokenRBrace>());
    TRY_(input.expect<TokenSemi>());
    
    rollback.cancel();
    return DefEvent{
        name.value,
        std::move(decstmts)
    };
}

Parsed<Stmt> parse_base_stmt(Input& input) {
    return any(input, "expected base stmt",
        parse_decstmt,
        parse_assignstmt,
        parse_ifstmt,
        parse_whilestmt
    );
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
        TRY(stmt, parse_base_stmt(input));
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
            TRY(stmt, parse_base_stmt(input));
            stmts.push_back(std::move(stmt));
        }

        blocks.push_back(std::move(Block{ std::move(stmts) }));
    }

    if(input.expect<TokenElse>()) {
        has_else = true;
       TRY_(input.expect<TokenLBrace>());

       stmts.clear();
       while(!input.expect<TokenRBrace>()) {
            TRY(stmt, parse_base_stmt(input));
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
        TRY(stmt, parse_base_stmt(input));
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
    return BoolExpr{ false };
}
Parsed<Expr> parse_true(Input& input) {
    auto rollback = input.mark_rollback();

    TRY_(input.expect<TokenTrue>());

    rollback.cancel();
    return BoolExpr{ true };
}
Parsed<Expr> parse_var(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(var, input.get<TokenName>());

    rollback.cancel();
    return StrExpr{ var.value };
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
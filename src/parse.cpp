#include "parse.hpp"

//  Grammar
//      Program :: Expr*
//      Expr    :: Add
//      Add     :: Add' | Mul
//      Add'    :: Mul AddOp Mul
//      Mul     :: Mul' | Factor
//      Mul'    :: Factor MulOp Factor
//      Factor  :: Parens | Num
//      AddOp   :: '+' | '-'
//      MulOp   :: '*' | '/'
//      Parens  :: '(' Expr ')'
//      Num     :: number

Parsed<Expr> parse_expr(Input&);

// AddOp :: '+' | '-'
Parsed<BinOp> parse_add_op(Input& input) {
    if (input.match<TAdd>()) {
        return BinOp::add;
    }
    else if (input.match<TSub>()) {
        return BinOp::sub;
    }
    else {
        return ParseError{ "expected add op" };
    }
}

// MulOp :: '*' | '/'
Parsed<BinOp> parse_mul_op(Input& input) {
    if (input.match<TMul>()) {
        return BinOp::mul;
    }
    else if (input.match<TDiv>()) {
        return BinOp::div;
    }
    else {
        return ParseError{ "expected mul op" };
    }
}

// Num :: number
Parsed<Expr> parse_num_expr(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(num, input.get<TNum>());

    rollback.cancel();
    return Expr(NumExpr{ num.value });
}

// Parens :: '(' Expr ')'
Parsed<Expr> parse_parens_expr(Input& input) {
    auto rollback = input.mark_rollback();

    TRY_(input.expect<TLPar>());
    TRY(expr, parse_expr(input));
    TRY_(input.expect<TRPar>());

    rollback.cancel();
    return expr;
}

// Factor :: Parens | Num
Parsed<Expr> parse_factor(Input& input) {
    return any(input, "factor expr",
        parse_parens_expr,
        parse_num_expr
    );
}

// Mul' :: Factor MulOp Factor
Parsed<Expr> parse_mul_expr_impl(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(left,  parse_factor(input));
    TRY(op,    parse_mul_op(input));
    TRY(right, parse_factor(input));

    rollback.cancel();
    return Expr(BinOpExpr{
       into_ptr(left),
       op,
       into_ptr(right)
    });
}

// Mul :: Mul' | Factor
Parsed<Expr> parse_mul_expr(Input& input) {
    return any(input, "mul expr",
        parse_mul_expr_impl,
        parse_factor
    );
}

// Add' :: Mul AddOp Mul
Parsed<Expr> parse_add_expr_impl(Input& input) {
    auto rollback = input.mark_rollback();

    TRY(left,  parse_mul_expr(input));
    TRY(op,    parse_add_op(input));
    TRY(right, parse_mul_expr(input));

    rollback.cancel();
    return Expr(BinOpExpr{
        into_ptr(left),
        op,
        into_ptr(right)
    });
}

// Add :: Add' | Mul
Parsed<Expr> parse_add_expr(Input& input) {
    return any(input, "add expr",
        parse_add_expr_impl,
        parse_mul_expr
    );
}

// Expr :: Add
Parsed<Expr> parse_expr(Input& input) {
    return parse_add_expr(input);
}

// Program :: Expr*
Parsed<Program> parse_program(Input& input) {
    std::vector<Expr> exprs;

    while (!input.at_end()) {
        TRY(expr, parse_expr(input));
        exprs.push_back(std::move(expr));
    }

    return Program{
        std::move(exprs)
    };
}

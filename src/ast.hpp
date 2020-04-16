#pragma once

#include <variant>
#include <vector>
#include <memory>

// Binary operators.
enum class BinOp {
    add,
    sub,
    mul,
    div
};


////////////////////////////////
// Expr

struct BinOpExpr;
struct NumExpr;

using Expr = std::variant<
    BinOpExpr,
    NumExpr
>;

// The Expr members create a recursive type. This has to be broken by
// making them dynamically allocated somehow.
struct BinOpExpr {
    std::unique_ptr<Expr> left;
    BinOp op;
    std::unique_ptr<Expr> right;
};

struct NumExpr {
    int value;
};


////////////////////////////////
// Program

struct Program {
    std::vector<Expr> exprs;
};


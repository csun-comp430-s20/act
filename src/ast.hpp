#pragma once

#include <memory>
#include "variant.hpp"
#include "vector.hpp"
#include "string.hpp"
#include "type.hpp"

namespace act{

// Binary operators.
enum class BinOp {
    opPlus,
    opLess,
    opGreater,
    opEqual
};

struct BinOpExpr;
struct IntExpr;
struct StrExpr;
struct BoolExpr;

using Expr = Variant<
    BinOpExpr,
    IntExpr,
    StrExpr,
    BoolExpr
>;

// The Expr members create a recursive type. This has to be broken by
// making them dynamically allocated somehow.
struct BinOpExpr {
    std::unique_ptr<Expr> left;
    BinOp op;
    std::unique_ptr<Expr> right;
};
struct IntExpr {
    int value;
};
struct StrExpr {
    String value;
};
struct BoolExpr {
    bool value;
};

struct DecStmt {
    Type type;
    String name;
    std::unique_ptr<Expr> exprs;
};

struct AssignStmt {
    String name;
    std::unique_ptr<Expr> exprs;
};

using Stmt = Variant<
    DecStmt,
    AssignStmt
>;

// Program
struct Program {
    Vector<Stmt> stmts;
};

String opString(BinOp const& op) {
    String str;

    switch (op) {
        case BinOp::opPlus: str = "+"; break;
        case BinOp::opLess: str = "<"; break;
        case BinOp::opGreater: str = ">"; break;
        case BinOp::opEqual: str = "=="; break;
    }

    return str;
}

} // namespace act
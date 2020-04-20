#pragma once

#include "variant.hpp"
#include "vector.hpp"
#include "string.hpp"
#include <memory>

namespace act{

// Binary operators.
enum class BinOp {
    add,
    less,
    greater,
    equal
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

enum class Type {
    integer,
    boolean,
    string
};

struct DecStmt {
    Type type;
    String name;
    Vector<Expr> exprs;
};

struct AssignStmt {
    String name;
    Vector<Expr> exprs;
};

using Stmt = Variant<
    DecStmt,
    AssignStmt
>;

// Program
struct Program {
    Vector<Stmt> stmts;
};

} // namespace act
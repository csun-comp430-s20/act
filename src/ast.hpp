#pragma once

#include <memory>
#include "variant.hpp"
#include "vector.hpp"
#include "string.hpp"
#include "type.hpp"

namespace act {

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
    const ValueType type;
    const String code;

    explicit IntExpr(int const& value_)
        : value(value_), type(intType), 
        code(to_string(value_)) {}
};
struct StrExpr {
    String value;
    const ValueType type;
    const String code;

    explicit StrExpr(String const& value_)
        : value(value_), type(strType),
        code(value_) {}
};
struct BoolExpr {
    bool value;
    const ValueType type;
    const String code;

    explicit StrExpr(bool const& value_)
        : value(value_), type(boolType),
        code(value_ ? "true" : "false") {}
};

struct DecStmt {
    ValueType type;
    String name;
    std::unique_ptr<Expr> exprs;
};
struct AssignStmt {
    String name;
    std::unique_ptr<Expr> exprs;
};
struct DefEvent {
    String name;
    Vector<ValueType> types;
};
struct CallEvent {
    String name;
    Vector<Expr> args;
};
using Stmt = Variant<
    DecStmt,
    AssignStmt,
    DefEvent,
    CallEvent
>;

// Program
struct Program {
    Vector<Stmt> stmts;
};

} // namespace act
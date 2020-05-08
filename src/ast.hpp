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

    explicit BoolExpr(bool const& value_)
        : value(value_), type(boolType),
        code(value_ ? "true" : "false") {}
};

struct StateStmt;
struct OnStmt;
struct GoIfStmt;
struct DecStmt;
struct AssignStmt;
struct DefEvent;
struct CallEvent;
struct IfStmt;
struct WhileStmt;
struct Block;

using Stmt = Variant<
    DecStmt,
    AssignStmt,
    IfStmt,
    WhileStmt
>;

struct DecStmt {
    ValueType type;
    String name;
    Expr expr;
};
struct AssignStmt {
    String name;
    Expr expr;
};
struct Block {
    Vector<Stmt> stmts;
};
struct IfStmt {
    Vector<Expr> conds;
    Vector<Block> blocks;
    bool has_else;
};
struct WhileStmt {
    Expr cond;
    Block block;
};

struct DefEvent {
    String name;
    Vector<ValueType> types;
};
struct CallEvent {
    String name;
    Vector<Expr> args;
};
struct GoIfStmt {
    Vector<Expr> conds;
    Vector<String> names; // state names
    Vector<Block> blocks;
    bool has_else;
};
struct OnStmt {
    CallEvent event;
    GoIfStmt gostmt;
};
struct StateStmt {
    String name;
    Vector<OnStmt> onstmts;
    Vector<StateStmt> states;
    std::shared_ptr<StateStmt> parent;
};

// Program
struct Program {
    Vector<DefEvent> events;
    StateStmt main_state;
};

} // namespace act
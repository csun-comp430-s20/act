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

struct VarExpr;
struct BinOpExpr;
struct IntExpr;
struct StrExpr;
struct BoolExpr;
using Expr = Variant<
    VarExpr,
    BinOpExpr,
    IntExpr,
    StrExpr,
    BoolExpr
>;

struct VarExpr {
    String name;
};
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

struct StateStmt;
struct OnStmt;
struct GoIfStmt;
struct DecStmt;
struct AssignStmt;
struct DefEvent;
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

struct DefState {
    String name;
};
struct DefEvent {
    String name;
    Vector<DecStmt> decs;
};
struct GoIfStmt {
    Vector<Expr> conds;
    Vector<String> names; // state names
    Vector<Block> blocks;
    bool has_else;
};
struct OnStmt {
    String event;
    GoIfStmt gostmt;
};
struct StateStmt {
    String name;
    Vector<Stmt> stmts;
    Vector<OnStmt> onstmts;
    Vector<StateStmt> states;
};

// Program
struct Program {
    Vector <DefState> defstates;
    Vector<DefEvent> defevents;
    StateStmt main_state;
};

} // namespace act
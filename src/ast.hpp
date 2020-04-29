#pragma once

#include <memory>
#include "variant.hpp"
#include "vector.hpp"
#include "string.hpp"
#include "type.hpp"
#include "map.hpp"

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

struct GetExprType {
    template<typename T>
    ValueType operator()(T const& t) {
        return t.type();
    }
};

ValueType get_expr_type(Expr const& expr) {
    return std::visit(GetExprType{}, expr);
}

// The Expr members create a recursive type. This has to be broken by
// making them dynamically allocated somehow.
struct BinOpExpr {
    std::unique_ptr<Expr> left;
    BinOp op;
    std::unique_ptr<Expr> right;

    ValueType type() const {
        return undefinedType;
    }
};
struct IntExpr {
    int value;

    ValueType type() const {
        return intType;
    }
};
struct StrExpr {
    String value;

    ValueType type() const {
        return strType;
    }
};
struct BoolExpr {
    bool value;

    ValueType type() const {
        return boolType;
    }
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

using Stmt = Variant<
    DecStmt,
    AssignStmt
>;

// Program
struct Program {
    Vector<Stmt> stmts;
};

} // namespace act
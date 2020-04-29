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
struct GetExprType;

using Expr = Variant<
    BinOpExpr,
    IntExpr,
    StrExpr,
    BoolExpr
>;

ValueType get_expr_type(Expr const&);
ValueType lookupbinOpRuleValueType(String const&);

static
const Map<String,ValueType> binOpRules {
    // { (op, lhs, rhs), return }
    { "+(int,int)", intType },
    { "+(string,string)", strType },
    { "<(int,int)", boolType },
    { "<(string,string)", boolType },
    { ">(int,int)", boolType },
    { ">(string,string)", boolType },
    { "==(int,int)", boolType },
    { "==(string,string)", boolType },
    { "==(bool,bool)", boolType },
};

struct GetExprType {
    template<typename T>
    ValueType operator()(T const& t) { return t.type(); }
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
// The Expr members create a recursive type. This has to be broken by
// making them dynamically allocated somehow.
struct BinOpExpr {
    std::unique_ptr<Expr> left;
    BinOp op;
    std::unique_ptr<Expr> right;

    String opString() const {
        String str = "";

        switch (op) {
            case BinOp::opPlus: str = "+"; break;
            case BinOp::opLess: str = "<"; break;
            case BinOp::opGreater: str = ">"; break;
            case BinOp::opEqual: str = "=="; break;
        }

        return str;
    }

    String toString() const {
        return opString() + "(" +
                get_expr_type(*left).name() +
                "," + get_expr_type(*right).name() + ")";
    }

    ValueType type() const {
        return lookupbinOpRuleValueType(toString());
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
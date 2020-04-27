#pragma once

#include <memory>
#include "variant.hpp"
#include "vector.hpp"
#include "string.hpp"
#include "type.hpp"
#include "canonname.hpp"
#include "result.hpp"
#include "map.hpp"

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

struct TypeError {
    String what;
};

using TypeResult = Result<Type, TypeError>;

class TypeEnv {

    public:
    TypeEnv();

    TypeResult lookupRuleType(CanonName const&) const;

    private:
    void initialize();
    String opString(BinOp const&);

    Map<CanonName,Type> _rules;
};

} // namespace act
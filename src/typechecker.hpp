#pragma once

#include "ast.hpp"
#include "canonname.hpp"

namespace act {

class TypeEnv {

    public:
    TypeEnv();
    String opString(BinOp const&);
    ValueTyped lookupRuleValueType(CanonName const&) const;
    ValueTyped lookupDecValue(String const&) const;
    
    Map<String,ValueType> declmap;

    private:
    void initialize();

    Map<CanonName,ValueType> _rules;
};

struct TypeCheckExpr;
struct TypeCheckStmt;

ValueTyped type_check_stmt(TypeEnv&, Stmt const&);
TypeEnv typeCheck(Program const&);

} // namespace act
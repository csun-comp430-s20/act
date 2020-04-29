#pragma once

#include "ast.hpp"
// #include "canonname.hpp"

namespace act {

class TypeEnv {

    public:
    // TypeEnv();
    ValueTyped lookupDecValue(String const&) const;
    
    Map<String,ValueType> declmap;
};

struct TypeCheckExpr;
struct TypeCheckStmt;

ValueTyped type_check_stmt(TypeEnv&, Stmt const&);
TypeEnv typeCheck(Program const&);

} // namespace act
#pragma once

#include "ast.hpp"
#include "typechecker_tools.hpp"

namespace act {

struct TypeCheckExpr;
struct TypeCheckStmt;

Typed<ValueType> type_check_expr(TypeEnv&, Expr const&);
Typed<Type> type_check_stmt(TypeEnv&, Stmt const&);
TypeEnv type_check_program(Program const&);

} // namespace act
#pragma once

#include "typechecker_tools.hpp"

namespace act {

struct TypeCheckExpr;
struct TypeCheckStmt;

Typed<ValueType> type_check_expr(TypeEnv&, Expr const&);
Typed<ValueType> type_check_stmt(TypeEnv&, Stmt const&);
Typed<ValueType> type_check_event_decstmt(TypeEnv&, DecStmt const&);
Typed<ValueType> type_check_defevent(TypeEnv&, DefEvent const&);
Typed<ValueType> type_check_goifstmt(TypeEnv&, GoIfStmt const&);
Typed<ValueType> type_check_onstmt(TypeEnv&, OnStmt const&);
TypeEnv type_check_program(Program const&);

} // namespace act
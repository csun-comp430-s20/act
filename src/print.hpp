#pragma once

#include "token.hpp"
#include "ast.hpp"

namespace act {

String opString(BinOp const&);
String print_id(Id const&);
String print_token(Token const&);
String print_fancy_token(Token const&);
String print_value_type(ValueType const&);
String print_op(BinOp const&);
String print_expr(Expr const&);
String print_stmt(Stmt const&);
String print_program(Program const&);

} // namespace act
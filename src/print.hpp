#pragma once

#include "token.hpp"
// #include "ast.hpp"

namespace act {

String print_id(Id const&);
String print_token(Token const&);
String print_fancy_token(Token const&);
// String print_op(BinOp const&);
// String print_expr(Expr const&);
// String print_program(Program const&);

} // namespace act
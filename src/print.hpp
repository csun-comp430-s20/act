#pragma once

#include "token.hpp"
// #include "ast.hpp"

namespace act {

std::string print_token(Token const&);
std::string print_fancy_token(Token const&);
// std::string print_op(BinOp const&);
// std::string print_expr(Expr const&);
// std::string print_program(Program const&);

} // namespace act
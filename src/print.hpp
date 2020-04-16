#pragma once

#include "token.hpp"
#include "ast.hpp"

std::string print_op(BinOp const& op);
std::string print_expr(Expr const&);
std::string print_program(Program const&);

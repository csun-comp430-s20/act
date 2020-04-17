#include "print.hpp"

namespace act {

struct PrintToken {
    std::string operator()(Token const& t) {
        return t.to_string();
    }
};
struct PrintFancyToken {
    std::string operator()(Token const& t) {
        return id_to_string(t.tid)
            + t.to_string()
            + id_to_string(Id::off);
    }
};
// struct PrintExpr {
//     std::string operator()(BinOpExpr const& e) {
//         return "("
//              + print_expr(*e.left)
//              + " "
//              + print_op(e.op)
//              + " "
//              + print_expr(*e.right)
//              + ")";
//     }

//     std::string operator()(NumExpr const& e) {
//         return std::to_string(e.value);
//     }
// };

// std::string print_op(BinOp const& op) {
//     std::string str;

//     switch (op) {
//         case BinOp::add: str = "+"; break;
//         case BinOp::sub: str = "-"; break;
//         case BinOp::mul: str = "*"; break;
//         case BinOp::div: str = "/"; break;
//     }

//     return str;
// }

std::string print_token(Token const& token) {
    return std::visit(PrintToken{}, token);
}

std::string print_fancy_token(Token const& token) {
    return std::visit(PrintFancyToken{}, token);
}

// std::string print_expr(Expr const& expr) {
//     return std::visit(PrintExpr{}, expr);
// }

// std::string print_program(Program const& program) {
//     std::string result;

//     for (Expr const& expr : program.exprs) {
//         result += print_expr(expr) + "\n";
//     }

//     return result;
// }

} // namespace act

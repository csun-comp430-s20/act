#include "print.hpp"

namespace act {

struct GetId {
    Id operator()(TokenLPar const& t)       { return t.tid; }
    Id operator()(TokenRPar const& t)       { return t.tid; }
    Id operator()(TokenComma const& t)      { return t.tid; }
    Id operator()(TokenSemi const& t)       { return t.tid; }
    Id operator()(TokenAssign const& t)     { return t.tid; }
    Id operator()(TokenPlus const& t)       { return t.tid; }
    Id operator()(TokenLess const& t)       { return t.tid; }
    Id operator()(TokenGreater const& t)    { return t.tid; }
    Id operator()(TokenEqual const& t)      { return t.tid; }
    Id operator()(TokenIf const& t)         { return t.tid; }
    Id operator()(TokenElse const& t)       { return t.tid; }
    Id operator()(TokenIntType const& t)    { return t.tid; }
    Id operator()(TokenBoolType const& t)   { return t.tid; }
    Id operator()(TokenStringType const& t) { return t.tid; }
    Id operator()(TokenName const& t)       { return t.tid; }
    Id operator()(TokenIntVal const& t)     { return t.tid; }
    Id operator()(TokenStringVal const& t)  { return t.tid; }
    Id operator()(TokenTrue const& t)       { return t.tid; }
    Id operator()(TokenFalse const& t)      { return t.tid; }
};

struct GetStr {
    String operator()(TokenLPar const& t)       { return t.to_string(); }
    String operator()(TokenRPar const& t)       { return t.to_string(); }
    String operator()(TokenComma const& t)      { return t.to_string(); }
    String operator()(TokenSemi const& t)       { return t.to_string(); }
    String operator()(TokenAssign const& t)     { return t.to_string(); }
    String operator()(TokenPlus const& t)       { return t.to_string(); }
    String operator()(TokenLess const& t)       { return t.to_string(); }
    String operator()(TokenGreater const& t)    { return t.to_string(); }
    String operator()(TokenEqual const& t)      { return t.to_string(); }
    String operator()(TokenIf const& t)         { return t.to_string(); }
    String operator()(TokenElse const& t)       { return t.to_string(); }
    String operator()(TokenIntType const& t)    { return t.to_string(); }
    String operator()(TokenBoolType const& t)   { return t.to_string(); }
    String operator()(TokenStringType const& t) { return t.to_string(); }
    String operator()(TokenName const& t)       { return t.to_string(); }
    String operator()(TokenIntVal const& t)     { return t.to_string(); }
    String operator()(TokenStringVal const& t)  { return t.to_string(); }
    String operator()(TokenTrue const& t)       { return t.to_string(); }
    String operator()(TokenFalse const& t)      { return t.to_string(); }
};

// struct PrintExpr {
//     String operator()(BinOpExpr const& e) {
//         return "("
//              + print_expr(*e.left)
//              + " "
//              + print_op(e.op)
//              + " "
//              + print_expr(*e.right)
//              + ")";
//     }

//     String operator()(NumExpr const& e) {
//         return std::to_string(e.value);
//     }
// };

// String print_op(BinOp const& op) {
//     String str;

//     switch (op) {
//         case BinOp::add: str = "+"; break;
//         case BinOp::sub: str = "-"; break;
//         case BinOp::mul: str = "*"; break;
//         case BinOp::div: str = "/"; break;
//     }

//     return str;
// }

String print_id(Id const& i) {
    return "[" + std::to_string(static_cast<int>(i)) + "]";
}

String print_token(Token const& token) {
    return std::visit(GetStr{}, token);
}

String print_fancy_token(Token const& token) {
    return print_id(std::visit(GetId{}, token))
            + std::visit(GetStr{}, token);
}

// String print_expr(Expr const& expr) {
//     return std::visit(PrintExpr{}, expr);
// }

// String print_program(Program const& program) {
//     String result;

//     for (Expr const& expr : program.exprs) {
//         result += print_expr(expr) + "\n";
//     }

//     return result;
// }

} // namespace act

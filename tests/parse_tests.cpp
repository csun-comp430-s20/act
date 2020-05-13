#include "catch2/catch.hpp"
#include "lexer.hpp"
#include "parse.hpp"
#include "print.hpp"

using namespace act;

namespace act {

std::unique_ptr<Input> ret_input(String const& str) {
    if(LexerResult lex_result = lexify(str)) {
        return std::make_unique<Input>(lex_result.value());
    } else {
        return nullptr;
    }
}

template <typename T>
bool parse_input(Parsed<T> (*f)(Input&), std::unique_ptr<Input> input) {
    if(!input) {
        return false;
    }

    if(auto ret = f(*input)) {
        return true;
    } else {
        return false;
    }
}

} // namespace act

TEST_CASE("Parser produces correct output", "[parser]") {

    // Exprs
    REQUIRE(parse_input<Expr>(parse_expr, ret_input("5")));
    REQUIRE(parse_input<Expr>(parse_expr, ret_input("5 + 6 + 7")));
    REQUIRE(parse_input<Expr>(parse_expr, ret_input("5 > 4")));
    REQUIRE(parse_input<Expr>(parse_expr, ret_input("5 > 4")));
    REQUIRE(parse_input<Expr>(parse_expr, ret_input("5 == 5")));
    REQUIRE(parse_input<Expr>(parse_expr, ret_input("\"Hello\" == \"Hello\"")));

    // Stmts
    REQUIRE(parse_input<Stmt>(parse_base_stmt, ret_input("int var = 5;")));
    REQUIRE(parse_input<Stmt>(parse_base_stmt, ret_input("int var = 5 + 10 + 4;")));
    REQUIRE(parse_input<Stmt>(parse_base_stmt, ret_input("string var = \"Hello\";")));
    REQUIRE(parse_input<Stmt>(parse_base_stmt, ret_input("var = true;")));
    REQUIRE(parse_input<Stmt>(parse_base_stmt, ret_input("if(5 == 5) {};")));
    REQUIRE(parse_input<Stmt>(parse_base_stmt, ret_input("while(5 == 5) {};")));

    // Special Stmts
    REQUIRE(parse_input<DecStmt>(parse_decstmt_only, ret_input("int var = 5;")));
    REQUIRE(parse_input<DefEvent>(parse_defevent, ret_input("defevent NAME {};")));
    REQUIRE(parse_input<GoIfStmt>(parse_goifstmt, ret_input("goif(5 == 5) new_state {}")));
    REQUIRE(parse_input<GoIfStmt>(parse_goifstmt, 
            ret_input("goif(5 == 5) other_state {} goelif (4 == 4) final_state {}")));
    REQUIRE(parse_input<GoIfStmt>(parse_goifstmt, 
            ret_input("goif(5 == 5) one_state {} goelif (4 == 4) two_state {} goelse three_state {}")));
    REQUIRE(parse_input<OnStmt>(parse_onstmt, ret_input("on EVENT { goif(5 == 5) new_state {} }")));
    REQUIRE(parse_input<StateStmt>(parse_statestmt, 
            ret_input("state life { on EVENT { goif(5 == 5) new_state {} } }")));
    REQUIRE(parse_input<StateStmt>(parse_statestmt, 
            ret_input("state life { on EVENT { goif(5 == 5) new_state {} } "
                    "state new_state { on EVENT2 { goif(4 == 4) life {} } } }")));
    REQUIRE(parse_input<Program>(parse_program, 
            ret_input("defevent HELLO {}; state life { on EVENT { goif(5 == 5) new_state {} } "
                    "state new_state { on EVENT2 { goif(4 == 4) life {} } } }")));
}

TEST_CASE("Parser properly produces error", "[parser]") {

    REQUIRE(!parse_input<Expr>(parse_expr, ret_input("if(")));
    REQUIRE(!parse_input<Stmt>(parse_base_stmt, ret_input("5")));
    REQUIRE(!parse_input<DecStmt>(parse_decstmt_only, ret_input("int var = 5")));
    REQUIRE(!parse_input<OnStmt>(parse_onstmt, ret_input("EVENT { goif(5 == 5) new_state {} }")));
}
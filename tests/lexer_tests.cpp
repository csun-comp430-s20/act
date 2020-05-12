#include "catch2/catch.hpp"
#include "lexer.hpp"
#include "print.hpp"

using namespace act;

namespace act {

template <typename... Ts>
Vector<Token> tokens(Ts&&... in) {
    Vector<Token> out;
    (out.push_back(std::make_unique<Ts>(in)), ...);
    return out;
}

bool operator==(Token const& a, Token const& b) {
    return print_token(a) == print_token(b);
}

bool operator==(LexerResult const& a, Vector<Token> const& b) {
    if(a) {
        return a.value() == b;
    } else {
        return false;
    }
}

}

TEST_CASE("Lexer produces correct output", "[lexer]") {

    // Empty input
    REQUIRE(lexify("") == tokens());
}
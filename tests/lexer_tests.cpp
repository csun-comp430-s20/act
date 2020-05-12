#include "catch2/catch.hpp"
#include "lexer.hpp"
#include "print.hpp"

using namespace act;

namespace act {

bool operator==(Token const& a, Token const& b) {
    return print_token(a) == print_token(b);
}

// bool operator==(LexerResult const& a, LexerResult const& b) {

// }

}

// TEST_CASE("Lexer produces correct output", "[lexer]") {

// }
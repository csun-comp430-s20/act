#include "catch2/catch.hpp"
#include "lexer.hpp"
#include "print.hpp"

using namespace act;

namespace act {

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

bool operator!=(LexerResult const& a, Vector<Token> const& b) {
    return !(a == b);
}

Vector<Token> tokens(Vector<Token> vec) {
    return vec;
}

} // namespace act

TEST_CASE("Lexer produces correct output", "[lexer]") {

    // Empty input
    REQUIRE(lexify("") == tokens({}));
    
    // Single Tokens
    REQUIRE(lexify("1") == tokens({TokenIntVal(1)}));
    REQUIRE(lexify("\"Hello\"") == tokens({TokenStringVal("Hello")}));
    REQUIRE(lexify("false") == tokens({TokenFalse()}));
    REQUIRE(lexify("true") == tokens({TokenTrue()}));
    REQUIRE(lexify("int") == tokens({TokenIntType()}));
    REQUIRE(lexify("{") == tokens({TokenLBrace()}));

    // Multi Tokens
    REQUIRE(lexify("state {}") == tokens({TokenState(),
                                    TokenLBrace(),
                                    TokenRBrace()}));
    REQUIRE(lexify("state { bool var = true; }") == tokens({TokenState(),
                                                TokenLBrace(),
                                                TokenBoolType(),
                                                TokenName("var"),
                                                TokenAssign(),
                                                TokenTrue(),
                                                TokenSemi(),
                                                TokenRBrace()}));
    REQUIRE(lexify("state { while(34 < 54) {} }") == tokens({TokenState(),
                                                TokenLBrace(),
                                                TokenWhile(),
                                                TokenLPar(),
                                                TokenIntVal(34),
                                                TokenLess(),
                                                TokenIntVal(54),
                                                TokenRPar(),
                                                TokenLBrace(),
                                                TokenRBrace(),
                                                TokenRBrace()}));
    REQUIRE(lexify("state { if(34 < 54) {} elif(45 > 34) {} }") == tokens({TokenState(),
                                                TokenLBrace(),
                                                TokenIf(),
                                                TokenLPar(),
                                                TokenIntVal(34),
                                                TokenLess(),
                                                TokenIntVal(54),
                                                TokenRPar(),
                                                TokenLBrace(),
                                                TokenRBrace(),
                                                TokenElIf(),
                                                TokenLPar(),
                                                TokenIntVal(45),
                                                TokenGreater(),
                                                TokenIntVal(34),
                                                TokenRPar(),
                                                TokenLBrace(),
                                                TokenRBrace(),
                                                TokenRBrace()}));
}

TEST_CASE("Lexer properly produces error", "[lexer]") {

    // Tests for Lexer error
    REQUIRE(lexify("1") != tokens({TokenIntVal(34)}));
    REQUIRE(lexify("true") != tokens({TokenFalse()}));
    REQUIRE(lexify("on") != tokens({TokenState()}));
}
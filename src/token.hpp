#pragma once

#include "string.hpp"
#include "variant.hpp"

namespace act {

struct TokenLPar {};
struct TokenRPar {};
struct TokenComma {};
struct TokenIf {};
struct TokenElse {};

struct TokenName { 
    String value; 

    explicit TokenName(String const& value_)
        : value(value_)
    {}
};

struct TokenNum { 
    int value; 
   
    explicit TokenNum(int value_) 
        : value(value_) 
    {} 
};

struct TokenStr {
    String value;

    explicit TokenStr(String const& value_)
        : value(value_)
    {}
};

using Token = Variant<
    TokenLPar, 
    TokenRPar, 
    TokenComma,
    TokenIf,
    TokenElse,
    TokenName, 
    TokenNum,
    TokenStr
>;

String to_string(Token const&);
String to_fancy_string(Token const&);

} // namespace act

#pragma once

#include <variant>
#include <string>

namespace act {

struct TokenLPar {};
struct TokenRPar {};
struct TokenComma {};
struct TokenIf {};
struct TokenElse {};
struct TokenPlus {};

struct TokenName { 
    std::string value; 

    explicit TokenName(std::string const& value_)
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
    std::string value;

    explicit TokenStr(std::string const& value_)
        : value(value_)
    {}
};

using Token = std::variant<
    TokenLPar,
    TokenRPar,
    TokenComma,
    TokenIf,
    TokenElse,
    TokenPlus,
    TokenName,
    TokenNum,
    TokenStr
>;



std::string to_string(Token const&);
std::string to_fancy_string(Token const&);

} // namespace act

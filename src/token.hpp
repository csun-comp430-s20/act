#pragma once

#include <variant>
#include <string>
#include "id.hpp"

using namespace std::literals::string_literals;

namespace act {

struct TokenLPar {
    Id tid = Id::symbol;

    std::string to_string() {
        return "(LPar)"s;
    }
};
struct TokenRPar {
    Id tid = Id::symbol;

    std::string to_string() {
        return "(RPar)"s;
    }
};
struct TokenComma {
    Id tid = Id::symbol;
    
    std::string to_string() {
        return "(Comma)"s;
    }
};
struct TokenPlus {
    Id tid = Id::symbol;
    
    std::string to_string() {
        return "(Plus)"s;
    }
};
struct TokenIf {
    Id tid = Id::keyword;

    std::string to_string() {
        return "(If)"s;
    }
};
struct TokenElse {
    Id tid = Id::keyword;

    std::string to_string() {
        return "(Else)"s;
    }
};

struct TokenName { 
    std::string value;
    Id tid = Id::name;

    explicit TokenName(std::string const& value_)
        : value(value_)
    {}

    std::string to_string() {
        return "(Name " + value + ")";
    }
};

struct TokenNum { 
    int value;
    Id tid = Id::literal;
   
    explicit TokenNum(int value_) 
        : value(value_) 
    {}

    std::string to_string() {
        return "(Num " + std::to_string(value) + ")";
    }
};

struct TokenStr {
    std::string value;
    Id tid = Id::literal;

    explicit TokenStr(std::string const& value_)
        : value(value_)
    {}

    std::string to_string() {
        return "(Str " + value + ")";
    }
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

} // namespace act

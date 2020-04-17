#pragma once

#include <variant>
#include "string.hpp"
#include "id.hpp"

namespace act {

struct TokenLPar {
    Id tid = Id::symbol;

    String to_string() const {
        return "(LPar)"s;
    }
};
struct TokenRPar {
    Id tid = Id::symbol;

    String to_string() const {
        return "(RPar)"s;
    }
};
struct TokenComma {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Comma)"s;
    }
};
struct TokenPlus {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Plus)"s;
    }
};
struct TokenIf {
    Id tid = Id::keyword;

    String to_string() const {
        return "(If)"s;
    }
};
struct TokenElse {
    Id tid = Id::keyword;

    String to_string() const {
        return "(Else)"s;
    }
};

struct TokenName { 
    String value;
    Id tid = Id::name;

    explicit TokenName(String const& value_)
        : value(value_)
    {}

    String to_string() const {
        return "(Name " + value + ")";
    }
};

struct TokenNum { 
    int value;
    Id tid = Id::literal;
   
    explicit TokenNum(int value_) 
        : value(value_) 
    {}

    String to_string() const {
        return "(Num " + std::to_string(value) + ")";
    }
};

struct TokenStr {
    String value;
    Id tid = Id::literal;

    explicit TokenStr(String const& value_)
        : value(value_)
    {}

    String to_string() const {
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

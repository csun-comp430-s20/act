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
struct TokenSemi {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Semi)"s;
    }
};
struct TokenAssign {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Assign)"s;
    }
};
struct TokenPlus {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Plus)"s;
    }
};
struct TokenLess {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Less)"s;
    }
};
struct TokenGreater {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Greater)"s;
    }
};
struct TokenEqual {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(Equal)"s;
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
struct TokenIntType {
    Id tid = Id::keyword;

    String to_string() const {
        return "(Int)"s;
    }
};
struct TokenStringType {
    Id tid = Id::keyword;

    String to_string() const {
        return "(String)"s;
    }
};
struct TokenBoolType {
    Id tid = Id::keyword;

    String to_string() const {
        return "(Bool)"s;
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

struct TokenIntVal { 
    int value;
    Id tid = Id::literal;
   
    explicit TokenIntVal(int value_) 
        : value(value_) 
    {}

    String to_string() const {
        return "(Num " + std::to_string(value) + ")";
    }
};
struct TokenStringVal {
    String value;
    Id tid = Id::literal;

    explicit TokenStringVal(String const& value_)
        : value(value_)
    {}

    String to_string() const {
        return "(Str " + value + ")";
    }
};
struct TokenTrue {
    Id tid = Id::literal;

    String to_string() const {
        return "(True)"s;
    }
};
struct TokenFalse {
    Id tid = Id::literal;

    String to_string() const {
        return "(False)"s;
    }
};

using Token = std::variant<
    TokenLPar,
    TokenRPar,
    TokenComma,
    TokenSemi,
    TokenAssign,
    TokenPlus,
    TokenLess,
    TokenGreater,
    TokenEqual,
    TokenIf,
    TokenElse,
    TokenIntType,
    TokenBoolType,
    TokenStringType,
    TokenName,
    TokenIntVal,
    TokenStringVal,
    TokenTrue,
    TokenFalse
>;

} // namespace act

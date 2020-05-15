#pragma once

#include "variant.hpp"
#include "string.hpp"

namespace act {

enum class Id {
    off      = 0,
    symbol   = 30,
    keyword  = 31,
    literal  = 32,
    name     = 33,
    type     = 34,
};

struct TokenLBrace {
    Id tid = Id::symbol;

    String to_string() const {
        return "(LBrace)"s;
    }
};
struct TokenRBrace {
    Id tid = Id::symbol;

    String to_string() const {
        return "(RBrace)"s;
    }
};
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
struct TokenAnd {
    Id tid = Id::symbol;
    
    String to_string() const {
        return "(And)"s;
    }
};

struct TokenExit {
    Id tid = Id::keyword;

    String to_string() const {
        return "(Exit)"s;
    }
};
struct TokenState {
    Id tid = Id::keyword;

    String to_string() const {
        return "(State)"s;
    }
};
struct TokenOn {
    Id tid = Id::keyword;

    String to_string() const {
        return "(On)"s;
    }
};
struct TokenGoIf {
    Id tid = Id::keyword;

    String to_string() const {
        return "(GoIf)"s;
    }
};
struct TokenGoElIf {
    Id tid = Id::keyword;

    String to_string() const {
        return "(GoElIf)"s;
    }
};
struct TokenGoElse {
    Id tid = Id::keyword;

    String to_string() const {
        return "(GoElse)"s;
    }
};
struct TokenWhile {
    Id tid = Id::keyword;

    String to_string() const {
        return "(While)"s;
    }
};
struct TokenIf {
    Id tid = Id::keyword;

    String to_string() const {
        return "(If)"s;
    }
};
struct TokenElIf {
    Id tid = Id::keyword;

    String to_string() const {
        return "(Elif)"s;
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
struct TokenDefEvent {
    Id tid = Id::keyword;

    String to_string() const {
        return "(defevent)"s;
    }
};

struct TokenName { 
    String value;
    Id tid = Id::name;

    explicit TokenName(String const& value_)
        : value(value_) {}

    String to_string() const {
        return "(Name " + value + ")";
    }
};

struct TokenIntVal { 
    int value;
    Id tid = Id::literal;
   
    explicit TokenIntVal(int value_) 
        : value(value_) {}

    String to_string() const {
        return "(Num " + std::to_string(value) + ")";
    }
};
struct TokenStringVal {
    String value;
    Id tid = Id::literal;

    explicit TokenStringVal(String const& value_)
        : value(value_) {}

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

using Token = Variant<
    TokenLBrace,
    TokenRBrace,
    TokenLPar,
    TokenRPar,
    TokenComma,
    TokenSemi,
    TokenAssign,
    TokenPlus,
    TokenLess,
    TokenGreater,
    TokenAnd,
    TokenEqual,
    TokenExit,
    TokenState,
    TokenOn,
    TokenGoIf,
    TokenGoElIf,
    TokenGoElse,
    TokenWhile,
    TokenIf,
    TokenElIf,
    TokenElse,
    TokenIntType,
    TokenBoolType,
    TokenStringType,
    TokenDefEvent,
    TokenName,
    TokenIntVal,
    TokenStringVal,
    TokenTrue,
    TokenFalse
>;

} // namespace act

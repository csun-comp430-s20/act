#include "token.hpp"
#include "color.hpp"

namespace act {

std::string to_string(Token const& t) {
    return t.match(
        [](TokenLPar) { 
            return "(LPar)"s; 
        },
        [](TokenRPar) { 
            return "(RPar)"s; 
        },
        [](TokenComma) { 
            return "(Comma)"s; 
        },
        [](TokenIf)   { 
            return "(If)"s; 
        },
        [](TokenElse) { 
            return "(Else)"s; 
        },
        [](TokenPlus) {
            return "(Plus)"s;
        },
        [](TokenName const& name) {
            return "(Name " + name.value + ")";
        },
        [](TokenNum const& num) {
            return "(Num " + to_string(num.value) + ")";
        },
        [](TokenStr const& str) {
            return "(Str " + str.value + ")";
        });
}

static
Color token_color(Token const& t) {
    constexpr auto col_op   = Color::yellow;
    constexpr auto col_name = Color::cyan;
    constexpr auto col_lit  = Color::red;
    
    return t.match(
        [](TokenLPar)  { return col_op; },
        [](TokenRPar)  { return col_op; },
        [](TokenComma) { return col_op; },
        [](TokenIf)    { return col_op; },
        [](TokenElse)  { return col_op; },
        [](TokenPlus)  { return col_op; },
        [](TokenName)  { return col_name; },
        [](TokenNum)   { return col_lit; },
        [](TokenStr)   { return col_lit; }
        );
}

std::string to_fancy_string(Token const& t) {
    return to_string(token_color(t)) 
         + to_string(t) 
         + to_string(Color::off);
}

} // namespace act

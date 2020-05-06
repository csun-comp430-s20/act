#pragma once

#include <unordered_map>
#include "token.hpp"
#include "lexercore.hpp"
#include "result.hpp"
#include "vector.hpp"

namespace act {

struct LexerError {
    size_t where;
    String what;
};

using MapKeywords = std::unordered_map<String, Token>;
using LexerToken = Result<Token, LexerError>;
using LexerResult = Result<Vector<Token>, LexerError>;
LexerResult lex(String const&);

static 
const MapKeywords keywords {
    { "if",   TokenIf() },
    { "else", TokenElse() },
    { "int", TokenIntType() },
    { "string", TokenStringType() },
    { "bool", TokenBoolType() },
    { "true", TokenTrue() },
    { "false", TokenFalse() },
    { "defevent", TokenDefEvent() },
};

Token lookup_keyword(MapKeywords const& map, String const& key);
char escape(char c);

class Lexer : private LexerCore {
    public:
    explicit Lexer(String const& input)
        : LexerCore(input)
    {}

    LexerResult run();
};

LexerResult lex(String const& input);

} // namespace act

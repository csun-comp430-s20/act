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
    { "state",      TokenState() },
    { "on",         TokenOn() },
    { "goif",       TokenGoIf() },
    { "goelif",     TokenGoElIf() },
    { "goelse",     TokenGoElse() },
    { "while",      TokenWhile() },
    { "if",         TokenIf() },
    { "elif",       TokenElIf() },
    { "else",       TokenElse() },
    { "int",        TokenIntType() },
    { "string",     TokenStringType() },
    { "bool",       TokenBoolType() },
    { "true",       TokenTrue() },
    { "false",      TokenFalse() },
    { "defevent",   TokenDefEvent() },
    { "defstate",   TokenDefState() },
    { "exit",       TokenExit() },
};

Token lookup_keyword(MapKeywords const&, String const&);
char escape(char);

class Lexer : private LexerCore {
    public:
    explicit Lexer(String const& input)
        : LexerCore(input)
    {}

    LexerResult run();
};

LexerResult lex(String const&);
LexerResult lexify(String const&);

} // namespace act

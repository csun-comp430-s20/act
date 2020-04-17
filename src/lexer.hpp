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

} // namespace act

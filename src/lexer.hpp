#pragma once

#include "token.hpp"
#include "lexercore.hpp"
#include "result.hpp"

namespace act {

struct LexerError {
    size_t where;
    String what;
};

using LexerResult = Result<Vector<Token>, LexerError>;

LexerResult lex(String const&);

} // namespace act

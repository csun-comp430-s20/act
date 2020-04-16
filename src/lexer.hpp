#pragma once

#include "token.hpp"
#include "lexercore.hpp"
#include "result.hpp"

namespace act {

struct LexerError {
    size_t where;
    std::string what;
};

using LexerResult = Result<Vector<Token>, LexerError>;

LexerResult lex(std::string const&);

} // namespace act

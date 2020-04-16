#pragma once

#include "result.hpp"

struct ParseError {
    std::string what;
};

template <typename T>
using Parsed = Result<T, ParseError>;

using Parsed_ = Result_<ParseError>;

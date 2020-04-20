#pragma once

#include "result.hpp"

namespace act {

struct ParseError {
    String what;
};

template <typename T>
using Parsed = Result<T, ParseError>;

using Parsed_ = Result_<ParseError>;

} // namespace act
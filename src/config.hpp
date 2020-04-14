#pragma once

#include "type.hpp"

namespace act::config {

    inline bool traceParse = false;
    inline bool traceTypeCheck = false;
    inline unsigned traceIndent = 2;

    inline String thisName("this");
    inline String consName("#cons"); // Must not be legal identifier.

} // namespace act::config
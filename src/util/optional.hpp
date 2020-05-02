#pragma once

#include <optional>

namespace dflat {

template <typename T>
using Optional = std::optional<T>;

using std::nullopt;

} //dflat

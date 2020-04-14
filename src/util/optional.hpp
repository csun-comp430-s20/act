#pragma once

#include <optional>

namespace act {

template <typename T>
using Optional = std::optional<T>;

using std::nullopt;

} //act

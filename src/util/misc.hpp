#pragma once

#include <memory>
#include "variant.hpp"

namespace act {

// template<class T>
// std::unique_ptr<T> make_unique(T&& t) {
//     return std::unique_ptr<T>(new T(std::forward<T>(t)));
// }

template <typename T>
T into_value(T& t) {
    return std::get<T>(std::move(t));
}
// Convenience for moving a T to the heap.
// The argument must not be used after calling this on it.
template <typename T>
std::unique_ptr<T> into_ptr(T& t) {
    return std::make_unique<T>(std::move(t));
}

} // namespace act

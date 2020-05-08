#pragma once

#include <memory>

namespace act {

// Convenience for moving a T to the heap.
// The argument must not be used after calling this on it.
template <typename T>
std::unique_ptr<T> into_ptr(T& t) {
    return std::make_unique<T>(std::move(t));
}

template <typename T>
std::shared_ptr<T> into_sptr(T& t) {
    return std::make_shared<T>(std::move(t));
}

} // namespace act

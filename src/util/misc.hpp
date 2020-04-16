#pragma once

#include <memory>

// Convenience for moving a T to the heap.
// The argument must not be used after calling this on it.
template <typename T>
std::unique_ptr<T> into_ptr(T& t) {
    return std::make_unique<T>(std::move(t));
}

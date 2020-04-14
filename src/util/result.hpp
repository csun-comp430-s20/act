#pragma once

#include "outcome/outcome.hpp"
#include "vector.hpp"

#define TRY OUTCOME_TRY
#define TRY_ OUTCOME_TRYV

namespace act {

namespace outcome = OUTCOME_V2_NAMESPACE;

struct Fail {};
Fail const failure;

struct Void {};

using outcome::success;

template <typename T, typename E>
using Result = outcome::checked<T,E>;

template <typename E>
using Result_ = outcome::checked<void, E>;

template <typename T>
using Optional = outcome::checked<T,Fail>;

template <typename T, typename E>
T& operator*(outcome::checked<T,E>& o) {
    return o.value();
}

template <typename T, typename E>
T const& operator*(outcome::checked<T, E> const& o) {
    return o.value();
}

template <typename T, typename E>
Vector<T> result_to_vector(Result<T,E> const& r) {
    if (r) {
        return {r.value()};
    }
    else {
        return {};
    }
}

#define LOOP_TRY(a,b) \
    auto a##__ = b; \
    if (!a##__) { continue; } \
    auto&& a = a##__.value()

} //act

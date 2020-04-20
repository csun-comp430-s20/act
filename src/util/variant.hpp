#pragma once

#include <variant>

namespace act {

template <typename... Ts>
using Variant = std::variant<Ts...>;

// template <typename T, typename... Fs>
// void match_each(T&& ts, Fs&&... fs) {
//     for (auto&& t : ts) {
//         t.match(std::forward<Fs>(fs)...);
//     }
// }

} // namespace act

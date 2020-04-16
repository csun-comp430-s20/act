#pragma once

#include <optional>
#include <unordered_map>
#include <utility>

namespace act {

template <typename K, typename V>
using Map = std::unordered_map<K,V>;

template <typename K, typename V>
std::optional<V> lookup(Map<K,V> const& map, K const& key) {
    auto it = map.find(key);

    // Have to be explicit here. std::optional<any> didn't work.
    if (it == map.end()) {
        return std::optional<V>(std::in_place_type_t<Fail>());
    }
    else {
        return std::optional<V>(std::in_place_type_t<V>(), it->second);
    }
}

} //act

#pragma once

#include <unordered_map>
#include <utility>
#include "result.hpp"

namespace act {

template <typename K, typename V>
using Map = std::unordered_map<K,V>;

template <typename K, typename V>
V lookup(Map<K,V> const& map, K const& key) {
    auto it = map.find(key);

    // Have to be explicit here. std::optional<any> didn't work.
    if (it == map.end()) {
        return Result_::ok();
    }
    else {
        return it->second;
    }
}

} //act

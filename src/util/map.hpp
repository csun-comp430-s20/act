#pragma once

#include <unordered_map>
#include <utility>
#include "result.hpp"

namespace act {

template <typename K, typename V>
using Map = std::unordered_map<K,V>;

template <typename K, typename V>
V const* lookup(Map<K,V> const& map, K const& key) {
    auto it = map.find(key);

    if (it == map.end()) {
        return nullptr;
    }
    else {
        return &it->second;
    }
}

template <typename K, typename V>
V* lookup(Map<K,V>& map, K const& key) {
    auto it = map.find(key);

    if (it == map.end()) {
        return nullptr;
    }
    else {
        return &it->second;
    }
}

} //act

#pragma once

#include <vector>
#include <algorithm>

namespace act {

template <typename T>
using Vector = std::vector<T>;
    
template <typename T>
void move_append(Vector<T>& to, Vector<T>&& from) {
    std::move(from.begin(), from.end(), std::back_inserter(to));
}

template <typename T, typename P>
bool erase_if(Vector<T>& v, P&& p) {
    auto it = std::remove_if(std::begin(v), std::end(v), p);

    if (it == end(v)) {
        return false;
    }
    else {
        v.erase(it, end(v));
        return true;
    }
}


} //act

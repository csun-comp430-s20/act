#pragma once

#include <unordered_set>
#include <utility>

namespace act
{

template <typename K>
using Set = std::unordered_set<K>;

template <typename K>
K const* lookup(Set<K> const& set, K const& key)
{
    auto it = set.find(key);

    if (it == set.end())
    {
        return nullptr;
    }
    else
    {
        return &*it;
    }
}

template <typename K, typename P>
void erase_if(Set<K>& set, P const& pred)
{
    for (auto i = set.begin(), last = set.end(); i != last; ) 
    {
        if (pred(*i)) 
        {
            i = set.erase(i);
        } 
        else 
        {
            ++i;
        }
    }
}

} //act

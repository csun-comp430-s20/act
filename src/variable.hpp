#pragma once

#include "string.hpp"
#include "type.hpp"

namespace act {

struct Variable {

    ValueType type;
    String name;

    Variable(ValueType const&, String const&);

    String toString() const;
};

bool operator==(Variable const&, Variable const&);
bool operator!=(Variable const&, Variable const&);

} // namespace act

namespace std {

template <>
struct hash<act::Variable>
{
    size_t operator()(act::Variable const& x) const
    {
        return std::hash<act::String>{}(x.name);
    }
};

} // namespace std
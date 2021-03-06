#pragma once

#include "string.hpp"
#include "vector.hpp"
#include "variant.hpp"
#include "result.hpp"

namespace act {

// A simple type consisting only of a name.
// Can be used as a key in a Set or Map.
class ValueType {
    private:
    String _name;

    public:
    explicit ValueType(String const&);
    
    String const& name() const;
    String toString() const; // Identical to name().
    bool operator==(ValueType const&) const;
    bool operator!=(ValueType const&) const;
    bool operator<(ValueType const&) const;
};

// Builtin types
ValueType const intType("int");
ValueType const boolType("bool");
ValueType const strType("string");

struct TypeError {
    String what;
};

template <typename T>
using Typed = Result<T, TypeError>;

bool isBuiltinType(ValueType const&);
// char const* translateBuiltinType(ValueType const&);

} // namespace act

// std::hash overloads.
namespace std
{

template <>
struct hash<act::ValueType> {
    size_t operator()(act::ValueType const& x) const {
        return std::hash<act::String>{}(x.name());
    }
};

} // namespace std

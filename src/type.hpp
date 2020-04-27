#pragma once

#include "string.hpp"
#include "vector.hpp"
#include "variant.hpp"
#include "map.hpp"
#include "result.hpp"

namespace act {

using TypeName = String;

// A simple type consisting only of a name.
// Can be used as a key in a Set or Map.
class ValueType
{
    private:
        TypeName _name;

    public:
        explicit ValueType(TypeName const&);
        
        TypeName const& name() const;
        String toString() const; // Identical to name().
        bool operator==(ValueType const&) const;
        bool operator!=(ValueType const&) const;
        bool operator<(ValueType const&) const;
};

// A complex type consisting of a return type and argument types.
// Its types are themselves ValueTypes.
class MethodType
{
    private:
        ValueType _ret;
        Vector<ValueType> _args;

    public:
        MethodType(ValueType const&, Vector<ValueType> const&);
        void addArgType(ValueType const&);
       
        ValueType const& ret() const;
        Vector<ValueType> const& args() const;
        String toString() const;
        bool operator==(MethodType const&) const;
        bool operator!=(MethodType const&) const;
};

// Type that can't be used.
ValueType const undefinedType("undefined");

// Builtin types
ValueType const intType("int");
ValueType const boolType("bool");
ValueType const stringType("string");

using Type = Variant<ValueType, MethodType>;

bool isBuiltinType(ValueType const&);
char const* translateBuiltinType(ValueType const&);

} // namespace act

// std::hash overloads.
namespace std
{

template <>
struct hash<act::ValueType>
{
    size_t operator()(act::ValueType const& x) const
    {
        return std::hash<act::TypeName>{}(x.name());
    }
};

} // namespace std

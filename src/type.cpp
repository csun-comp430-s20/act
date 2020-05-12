#include "type.hpp"
#include "map.hpp"
// #include <stdexcept>

namespace act
{

ValueType::ValueType(String const& name)
    : _name(name) {}

String const& ValueType::name() const {
    return _name;
}

String ValueType::toString() const {
    return _name;
}

bool ValueType::operator==(ValueType const& other) const {
    return _name == other._name;
}

bool ValueType::operator!=(ValueType const& other) const {
    return !(*this == other);
}

bool ValueType::operator<(ValueType const& other) const {
    return _name < other._name;
}

// Builtin types
namespace  {
struct BuiltinType {
    char const* translation;
};

const Map<ValueType, BuiltinType> s_builtinTypes {
    { intType, {"int"} },
    { boolType, {"bool"} },
    { strType, {"string"} },
};
}

bool isBuiltinType(ValueType const& type) {
    return s_builtinTypes.count(type) != 0;
}

// char const* translateBuiltinType(ValueType const& type)
// {
//     BuiltinType const* bt = lookup(s_builtinTypes, type);

//     if (!bt)
//     {
//         throw std::logic_error("No builtin type '" + type.toString() + "'");
//     }
    
//     return bt->translation;
// }

} // namespace act

#include "type.hpp"
#include "map.hpp"
#include <stdexcept>

namespace act
{

ValueType::ValueType(TypeName const& name)
    : _name(name)
{}

TypeName const& ValueType::name() const
{
    return _name;
}

String ValueType::toString() const
{
    return _name;
}

bool ValueType::operator==(ValueType const& other) const
{
    return _name == other._name;
}

bool ValueType::operator!=(ValueType const& other) const
{
    return !(*this == other);
}

bool ValueType::operator<(ValueType const& other) const
{
    return _name < other._name;
}


MethodType::MethodType(ValueType const& ret, Vector<ValueType> const& args)
    : _ret(ret)
    , _args(args)
{}

String MethodType::toString() const
{
    String s = _ret.name() + "(";
    bool first = true;

    for (ValueType const& arg : _args)
    {
        if (first) 
        {
            first = false;
        }
        else
        {
            s += ",";
        }

        s += arg.name();
    }

    s += ")";
    return s;
}

void MethodType::addArgType(ValueType const& typeName)
{
    _args.push_back(typeName);
}

ValueType const& MethodType::ret() const
{
    return _ret;
}

Vector<ValueType> const& MethodType::args() const
{
    return _args;
}

bool MethodType::operator==(MethodType const& other) const
{
    return _ret  == other._ret
        && _args == other._args;
}

bool MethodType::operator!=(MethodType const& other) const
{
    return !(*this == other);
}


// Builtin types
namespace 
{
    struct BuiltinType
    {
        char const* translation;
    };

    const Map<ValueType, BuiltinType> s_builtinTypes
    {
        { intType, {"int"} },
        { boolType, {"bool"} },
        { strType, {"string"} },
    };
}

bool isBuiltinType(ValueType const& type)
{
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

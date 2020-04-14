#include "type.hpp"
#include "map.hpp"
#include <stdexcept>

namespace act
{

Type::Type(ValueType const& value)
    : Base(value)
{}

Type::Type(MethodType const& method)
    : Base(method)
{}

void Type::assertValue() const
{
    if (!isValue())
    {
        throw std::logic_error("Type '" + toString() + "' is not ValueType");
    }
}

void Type::assertMethod() const
{
    if (!isMethod())
    {
        throw std::logic_error("Type '" + toString() + "' is not MethodType");
    }
}

ValueType const& Type::value() const
{
    assertValue();
    return get_unchecked<ValueType>();
}

ValueType& Type::value()
{
    assertValue();
    return get_unchecked<ValueType>();
}

MethodType const& Type::method() const
{
    assertMethod();
    return get_unchecked<MethodType>();
}

MethodType& Type::method()
{
    assertMethod();
    return get_unchecked<MethodType>();
}

bool Type::isValue() const
{
    return is<ValueType>();
}

bool Type::isMethod() const
{
    return is<MethodType>();
}

String Type::toString() const
{
    return this->match([](auto const& t)
    {
        return t.toString();
    });
}

bool Type::operator==(Type const& other) const
{
    return static_cast<Base const&>(*this)
        == static_cast<Base const&>(other);
}

bool Type::operator!=(Type const& other) const
{
    return !(*this == other);
}


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
        { boolType, {"int"} },
        { voidType, {"void"} },
    };
}

bool isBuiltinType(ValueType const& type)
{
    return s_builtinTypes.count(type) != 0;
}

char const* translateBuiltinType(ValueType const& type)
{
    BuiltinType const* bt = lookup(s_builtinTypes, type);

    if (!bt)
    {
        throw std::logic_error("No builtin type '" + type.toString() + "'");
    }
    
    return bt->translation;
}

} // namespace act

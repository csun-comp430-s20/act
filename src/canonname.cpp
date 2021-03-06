#include "canonname.hpp"
#include <iostream>

namespace act {

static
String mkCanonName(String const& base, Vector<ValueType> const& types)
{
    String s = base + "(";
    bool first = true;

    for (ValueType const& t : types)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            s += ",";
        }

        s += t.toString();
    }

    s += ")";
    return s;
}

CanonName::CanonName(String base, Vector<ValueType> const& type)
    : _baseName(std::move(base))
    , _type(type)
    , _canonName(mkCanonName(_baseName, _type))
{}

String const& CanonName::baseName() const
{
    return _baseName;
}

String const& CanonName::canonName() const
{
    return _canonName;
}

Vector<ValueType> const& CanonName::type() const
{
    return _type;
}

bool operator==(CanonName const& a, CanonName const& b)
{
    return a.canonName() == b.canonName();
}

bool operator!=(CanonName const& a, CanonName const& b)
{
    return !(a == b);
}

std::ostream& operator<<(std::ostream& s, CanonName const& x)
{
    return s << x.canonName();
}

} // namespace act

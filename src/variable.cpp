#include "variable.hpp"

namespace act {

Variable::Variable(ValueType const& _type, String const& _name)
    : type(_type), name(_name) {}

String Variable::toString() const
{
    return name;
}

bool operator==(Variable const& a, Variable const& b)
{
    return a.name == b.name;
}

bool operator!=(Variable const& a, Variable const& b)
{
    return !(a == b);
}

} // namespace act
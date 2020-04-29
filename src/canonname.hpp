#pragma once

#include "string.hpp"
#include "type.hpp"
#include <iosfwd>

namespace act {

class CanonName
{
    public:
        CanonName(String, MethodType const&);
        String const& baseName() const;
        String const& canonName() const;
        MethodType const& type() const;

    private:
        String _baseName;
        MethodType _type;
        String _canonName;
};

bool operator==(CanonName const&, CanonName const&);
bool operator!=(CanonName const&, CanonName const&);
std::ostream& operator<<(std::ostream&, CanonName const&);

} // namespace act

namespace std
{

template <>
struct hash<act::CanonName>
{
    size_t operator()(act::CanonName const& x) const
    {
        return std::hash<act::String>{}(x.canonName());
    }
};

} // namespace std

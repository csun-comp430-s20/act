#include "scopemeta.hpp"
#include <iostream>

namespace act
{

void ScopeMetaMan::push()
{
    _scopes.push_back({});
}

void ScopeMetaMan::pop()
{
    _scopes.pop_back();
}

void ScopeMetaMan::declAny(String const& name, Decl const& decl)
{
    _scopes.back().insert({name, decl});
}

void ScopeMetaMan::declLocal(String const& name, ValueType const& type)
{
    Decl decl{ DeclType::local, type };
    declAny(name, decl);
}

Decl const* ScopeMetaMan::lookup(String const& name) const
{
    auto it = _scopes.rbegin();
    auto const end = _scopes.rend();

    while (it != end)
    {
        if (Decl const* decl = act::lookup(*it, name))
        {
            return decl;
        }

        ++it;
    }

    return nullptr;
}

} // namespace act

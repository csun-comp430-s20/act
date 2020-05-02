#pragma once

#include "string.hpp"
#include "map.hpp"
#include "vector.hpp"
#include "type.hpp"

namespace act
{

enum class DeclType
{
    local,
    member,
};

struct Decl
{
    DeclType declType;  
    ValueType type;
};

class ScopeMetaMan
{
    public:
        void push();
        void pop();
        void declLocal(String const&, ValueType const&);
        Decl const* lookup(String const&) const;

    private:
        void declAny(String const&, Decl const&);
        
        Vector<Map<String, Decl>> _scopes = {{}};
};

} // namespace act

#pragma once

#include "ast.hpp"
#include "map.hpp"
#include "canonname.hpp"
#include "print.hpp"

namespace act {

class TypeEnv
{
    public:
        TypeEnv();
        
        void addVarType(String const&, ValueType const&);
        void addEvent(String const&, bool = true);
        void addState(String const&, bool = true);
        Typed<ValueType> lookupRuleType(CanonName const&) const;
        Typed<ValueType> lookupVarType(String const&) const;
        bool lookupEvent(String const&) const;
        bool lookupState(String const&) const;

    private:
        void initialize();

        Map<String,ValueType> _vartypes;
        Map<String,bool> _events;
        Map<String,bool> _states;
        Map<CanonName,ValueType> _rules;
};

} // namespace act
#pragma once

#include "type.hpp"
#include "string.hpp"
#include "map.hpp"
#include "vector.hpp"
#include "scopemeta.hpp"
#include "canonname.hpp"
#include "print.hpp"

namespace act {

class TypeEnv
{
    public:
        TypeEnv();

        // void enterClass(ValueType const& classType);
        // void setClassParent(ValueType const&);
        // void leaveClass();
        // void addClassVar(String const& name, ValueType const& type);
        // void addClassMethod(CanonName const&);
        // bool inClass() const;
        // ClassMeta const& curClass() const;
 
        // void enterMethod(CanonName const&);
        // void leaveMethod();
        // bool inMethod() const;
        // MethodMeta const& curMethod() const;
        // void setMethodMeta(ASN const*, ValueType const& objectType, CanonName const&);

        // void enterScope();
        // void leaveScope();
        
        void declareLocal(String const& name, ValueType const& type);
        
        ValueTyped lookupRuleType(CanonName const&) const;
        // MethodType lookupMethodType(CanonName const&) const;
        // MethodType lookupMethodTypeByClass(ValueType const& classType,
        //         CanonName const&) const;
        ValueTyped lookupVarType(String const& varName) const;
        // ValueType lookupVarTypeByClass(ValueType const& classType,
        //         String const& varName) const;

        // CanonName resolveMethod(ValueType const& classType,
        //         String const& baseName, MethodType const&) const;
        
        // bool compatibleArgs(Vector<ValueType> const& formal,
        //         Vector<ValueType> const& actual) const;

        // type must be declared.
        // void assertValidType(ValueType const& type) const;

        // t1 must equal t2.
        // void assertTypeIs(Type const& t1, Type const& t2) const;

        // t1 must equal t2 or be a base of t2.
        // bool typeIsOrBase(Type const& t1, Type const& t2) const;
        // void assertTypeIsOrBase(Type const& t1, Type const& t2) const;

    private:
        void initialize();

        // ClassMetaMan _classes;
        ScopeMetaMan _scopes;
        // MethodMetaMan _methods;
    
        /// rules - Map of valid rules for how types interact with operators:
        ///     Map: String canonical name -> String expressions return type.
        Map<CanonName,ValueType> _rules;

        // Optional<MethodMeta> _curMethod;

        // friend class GenEnv;

};

} // namespace act
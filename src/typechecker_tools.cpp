#include "typechecker_tools.hpp"

namespace act {

TypeEnv::TypeEnv()
{
    initialize();
}

void TypeEnv::initialize() 
{
    auto binopRule = [&](BinOp op, ValueType const& ret, 
            ValueType const& lhs, ValueType const& rhs)
    {
        String name(opString(op));
        Vector<ValueType> type{ lhs, rhs };
        CanonName canonName(name, type);
        _rules.insert({ canonName, ret });
    };

    ValueType const i = intType;
    ValueType const b = boolType;
    ValueType const s = strType;

    // Predefined function types. 
    binopRule(BinOp::opPlus,    i, i, i); // int +(int,int)
    binopRule(BinOp::opPlus,    s, s, s);

    binopRule(BinOp::opLess,    b, i, i);
    binopRule(BinOp::opLess,    b, s, s);

    binopRule(BinOp::opGreater, b, i, i);
    binopRule(BinOp::opGreater, b, s, s);
    binopRule(BinOp::opEqual,   b, i, i);
    binopRule(BinOp::opEqual,   b, s, s);
    binopRule(BinOp::opEqual,   b, b, b);
    binopRule(BinOp::opAnd,     b, b, b);
}

void TypeEnv::addVarType(String const& name, ValueType const& type) {
    _vartypes.insert({name, type});
}

void TypeEnv::addEvent(String const& name, bool value) {
    _events.insert({name, value});
}

void TypeEnv::addState(String const& name, bool value) {
    _states.insert({name, value});
}

Typed<ValueType> TypeEnv::lookupRuleType(CanonName const& name) const {
    ValueType const* type = lookup(_rules, name);

    if (type) {
        return *type;
    }
    else {
        return TypeError{ "Invalid operands to operator: " + name.canonName() };
    }
}

Typed<ValueType> TypeEnv::lookupVarType(String const& varName) const {
    ValueType const* v = lookup(_vartypes, varName);

    if (v) {
        return *v;
    }
    else {
        return TypeError{ " Var " + varName + " not declared" };
    }
}

bool TypeEnv::lookupEvent(String const& eventName) const {
    bool const* vt = lookup(_events, eventName);

    if (vt) {
        return *vt;
    }
    else {
        return false;
    }
}

bool TypeEnv::lookupState(String const& stateName) const {
    bool const* vt = lookup(_states, stateName);

    if (vt) {
        return *vt;
    }
    else {
        return false;
    }
}

} // namespace act
#include "typechecker_tools.hpp"
#include "ast.hpp"

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
}

void TypeEnv::declareLocal(String const& name, ValueType const& type)
{
    _scopes.declLocal(name, type);
}

Typed<ValueType> TypeEnv::lookupRuleType(CanonName const& name) const
{
    ValueType const* type = lookup(_rules, name);

    if (type) {
        return *type;
    }
    else {
        return TypeError{ "Invalid operands to operator: " + name.canonName() };
    }
}

Typed<ValueType> TypeEnv::lookupVarType(String const& varName) const
{
    Decl const* decl = _scopes.lookup(varName);

    if (decl && decl->declType == DeclType::local) {
        ValueType varType = decl->type;

        return varType;
    }
    else {
        return TypeError{ " Var " + varName + " not declared" };
    }
}

} // namespace act
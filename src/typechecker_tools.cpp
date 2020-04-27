#include "typechecker.hpp"

namespace act {

TypeEnv::TypeEnv() {
    initialize();
}

void TypeEnv::initialize() {

    auto binopRule = [&](BinOp op, ValueType const& ret,
                        ValueType const& lhs, ValueType const& rhs) {
        
        String name(opString(op));
        MethodType type(ret, { lhs, rhs });
        CanonName canonName(name, type);
        _rules.insert({ canonName, ret });
    };

    ValueType const i = intType;
    ValueType const b = boolType;
    ValueType const s = stringType;

    binopRule(opPlus, i, i, i);     // int = int + int
    binopRule(opPlus, s, s, s);     // str = str + str

    binopRule(opLess, b, i, i);     // bool = i < i
    binopRule(opLess, b, s, s);

    binopRule(opGreater, b, i, i);
    binopRule(opGreater, b, s, s);

    binopRule(opEqual, b, i, i);    // bool = i == i
    binopRule(opEqual, b, s, s);
    binopRule(opEqual, b, b, b);

}

TypeResult TypeEnv::lookupRuleType(CanonName const& name) const {
    Type const* type = lookup(_rules, name);

    if (type)
    {
        return *type;
    }
    else
    {
        return TypeError{ "Invalid operands to operator: " + name.canonName() };
    }
}

} // namespace act
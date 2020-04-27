#include "typechecker_tools.hpp"

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

    binopRule(BinOp::opPlus, i, i, i);     // int = int + int
    binopRule(BinOp::opPlus, s, s, s);     // str = str + str

    binopRule(BinOp::opLess, b, i, i);     // bool = i < i
    binopRule(BinOp::opLess, b, s, s);

    binopRule(BinOp::opGreater, b, i, i);
    binopRule(BinOp::opGreater, b, s, s);

    binopRule(BinOp::opEqual, b, i, i);    // bool = i == i
    binopRule(BinOp::opEqual, b, s, s);
    binopRule(BinOp::opEqual, b, b, b);

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

String opString(BinOp const& op) {
    String str;

    switch (op) {
        case BinOp::opPlus: str = "+"; break;
        case BinOp::opLess: str = "<"; break;
        case BinOp::opGreater: str = ">"; break;
        case BinOp::opEqual: str = "=="; break;
    }

    return str;
}

} // namespace act
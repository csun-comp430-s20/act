#include "ast.hpp"

namespace act {

ValueType lookupbinOpRuleValueType(String const& key) {
    ValueType const* type = lookup(binOpRules, key);

    if (type) {
        return *type;
    }
    else {
        return undefinedType;
    }
}

ValueType get_expr_type(Expr const& expr) {
    return std::visit(GetExprType{}, expr);
}

} // namespace act
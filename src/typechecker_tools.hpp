#pragma once

#include "ast.hpp"
#include "canonname.hpp"
#include "parse_result.hpp"
#include "map.hpp"

namespace act {

struct TypeError {
    String what;
};

using TypeResult = Result<Type, TypeError>;

class TypeEnv {

    public:
    TypeEnv();

    TypeResult lookupRuleType(CanonName const&) const;

    private:
    void initialize();

    Map<CanonName,Type> _rules;
};

// TypeEnv typeCheck(Parsed<Program> const&);
String opString(BinOp const&);

} // namespace act
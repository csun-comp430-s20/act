#pragma once

#include "ast.hpp"
#include "result.hpp"
#include "map.hpp"

namespace act {

struct TypeError {
    String what;
};

using TypeResult = Result<Type, TypeError>;

class TypeEnv {

    public:
    TypeEnv();

    TypeResult lookUpRuleType(CanonName const&) const;

    private:
    void initialize();

    Map<CanonName,Type> _rules;
};

TypeEnv typeCheck(Parsed<Program> const&);



} // namespace act
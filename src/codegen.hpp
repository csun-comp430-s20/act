#pragma once

#include <sstream>
#include "typechecker_tools.hpp"
#include "ast.hpp"

namespace act {

struct genExpr;
struct genStmt;

struct CodeTabs {};
struct CodeTabIn {};
struct CodeTabOut {};

String gen_expr(Expr const&);
String gen_stmt(Stmt const&);

String gen_code(Program const&, TypeEnv const&);

class GenEnv {
    public:
        GenEnv(TypeEnv const&);

        GenEnv& operator<<(CodeTabs const&);
        GenEnv& operator<<(CodeTabIn const&);
        GenEnv& operator<<(CodeTabOut const&);
        GenEnv& operator<<(Expr const&);
        GenEnv& operator<<(Stmt const&);

        String prolog() const;
        String epilog() const;
        // String concat() const;

        // void declareLocal(String const& name, ValueType const& type);
        // ValueType const& getLocalType(String const& name) const;
        // ValueType const* lookupLocalType(String const& name) const;

    private:
        std::stringstream& write();
        std::stringstream _codeDef;

        unsigned _tabs = 0;

        // ScopeMetaMan _scopes;
};

} // namespace act
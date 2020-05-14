#pragma once

#include <sstream>
#include "typechecker_tools.hpp"

namespace act {

struct genExpr;
struct genStmt;

struct CodeTabs {};
struct CodeTabIn {};
struct CodeTabOut {};

class GenEnv {
    public:
        GenEnv();

        GenEnv& operator<<(String const&);
        GenEnv& operator<<(CodeTabs const&);
        GenEnv& operator<<(CodeTabIn const&);
        GenEnv& operator<<(CodeTabOut const&);
        GenEnv& operator<<(Expr const&);

        String prolog() const;
        String epilog() const;

    private:
        std::stringstream& write();
        std::stringstream _codeDef;

        unsigned _tabs = 0;

        // ScopeMetaMan _scopes;
};

String gen_expr(Expr const&);
void gen_stmt(GenEnv&, Stmt const&);
String gen_code(Program const&);

} // namespace act
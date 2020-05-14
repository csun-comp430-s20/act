#pragma once

#include <sstream>
#include "typechecker_tools.hpp"

namespace act {

struct genExpr;
struct genStmt;

struct CodeTabs {};
struct CodeTabIn {};
struct CodeTabOut {};

String gen_expr(Expr const&);
void gen_stmt(Stmt const&);

String gen_code(Program const&);

class GenEnv {
    public:
        GenEnv();

        GenEnv& operator<<(CodeTabs const&);
        GenEnv& operator<<(CodeTabIn const&);
        GenEnv& operator<<(CodeTabOut const&);
        GenEnv& operator<<(Expr const&);
        GenEnv& operator<<(Stmt const&);

        String prolog() const;
        String epilog() const;

    private:
        std::stringstream& write();
        std::stringstream _codeDef;

        unsigned _tabs = 0;

        // ScopeMetaMan _scopes;
};

} // namespace act
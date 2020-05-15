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
    GenEnv(TypeEnv const&);

    GenEnv& operator<<(String const&);
    GenEnv& operator<<(CodeTabs const&);
    GenEnv& operator<<(CodeTabIn const&);
    GenEnv& operator<<(CodeTabOut const&);
    GenEnv& operator<<(Expr const&);

    String prolog() const;
    String static_decs() const;
    String epilog() const;
    String concat() const;

    private:
    TypeEnv _env;
    std::stringstream& write();
    std::stringstream _codeDef;
    unsigned _tabs = 0;
};

String gen_expr(Expr const&);
void gen_stmt(GenEnv&, Stmt const&);
void gen_goifstmt(GenEnv&, GoIfStmt const&);
void gen_onstmt(GenEnv&, OnStmt const&);
void gen_statestmt(GenEnv&, StateStmt const&);
String gen_code(TypeEnv const&, Program const&);

} // namespace act
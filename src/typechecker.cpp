#include <iostream>
#include "typechecker.hpp"

namespace act {

struct TypeCheckExpr {
    TypeEnv env;

    ValueTyped operator()(BinOpExpr const& e) {
        ValueTyped lhs = type_check_expr(env, *e.left);
        ValueTyped rhs = type_check_expr(env, *e.right);

        if(!lhs) {
            return lhs.error();
        }

        if(!rhs) {
            return rhs.error();
        }

        String name(opString(e.op));
        Vector<ValueType> type{ lhs.value(), rhs.value() };
        CanonName canonName(name, type);

        return env.lookupRuleType(canonName); 
    }

    ValueTyped operator()(IntExpr const& e) {
        return e.type;
    }

    ValueTyped operator()(StrExpr const& e) {
        return e.type;
    }

    ValueTyped operator()(BoolExpr const& e) {
        return e.type;
    }
};

struct TypeCheckStmt {
    TypeEnv env;

    ValueTyped operator()(DecStmt const& s) {
        if(auto expr_type = type_check_expr(env, *s.exprs)) {
            if(expr_type.value() == s.type) {
                env.declareLocal(s.name, expr_type.value());
                return s.type;
            }
            else {
                return TypeError{ "Improperly declared var" };
            }
        } else {
            return expr_type.error();
        }
    }

    ValueTyped operator()(AssignStmt const& s) {
        if(auto var_type = env.lookupVarType(s.name)) {
            if(auto expr_type = type_check_expr(env, *s.exprs)) {
                if(var_type.value() == expr_type.value()) {
                    return var_type.value();
                } else {
                    return TypeError{ "Types do not match in AssignStmt" };
                }       
            } else {
                return expr_type.error();
            }
        } else {
            return var_type.error();
        }
    }
};

ValueTyped type_check_expr(TypeEnv& env, Expr const& expr) {
    return std::visit(TypeCheckExpr{ env }, expr);
}

ValueTyped type_check_stmt(TypeEnv& env, Stmt const& stmt) {
    return std::visit(TypeCheckStmt{ env }, stmt);
}

TypeEnv type_check_program(Program const& program) {
    TypeEnv env;

    for (Stmt const& stmt : program.stmts) {
        if(auto stmt_type = type_check_stmt(env, stmt)) {
            // ok
        } else {
            std::cout << "Type Error: " << stmt_type.error().what << std::endl;
        }
    }

    return env;
}

} // namespace act
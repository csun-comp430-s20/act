#include <iostream>
#include "typechecker.hpp"
#include "logger.hpp"
#include "config.hpp"

namespace act {

struct TraverseExpr {
    String operator()(VarExpr const& e) {
        return e.name;
    }

    String operator()(BinOpExpr const& e) {
        return print_expr(*e.left)
            + " "
            + print_op(e.op)
            + " "
            + print_expr(*e.right);
    }

    String operator()(IntExpr const& e) {
        return to_string(e.value);
    }

    String operator()(StrExpr const& e) {
        return e.value;
    }

    String operator()(BoolExpr const& e) {
        return to_string(e.value);
    }
};

struct TraverseStmt {
    TypeEnv env;

    void operator()(ExitStmt const&) {}

    void operator()(DecStmt const& s) {
        env.addVarType(s.name, s.type);
        env.varMap.insert({Variable(s.type, s.name), traverse_expr(s.expr)});
    }

    void operator()(AssignStmt const&) {}

    void operator()(IfStmt const&) {}

    void operator()(WhileStmt const&) {}
};

void traverse_state(TypeEnv& env, StateStmt const& state) {
    env.addState(state.name);
    env.states.push_back(state.name);

    for(auto & stmt: state.stmts) {
        traverse_stmt(env, stmt);
    }

    for(auto & s: state.states) {
        traverse_state(env, s);
    }
}
void traverse_stmt(TypeEnv& env, Stmt const& stmt) {
    std::visit(TraverseStmt{ env }, stmt);
}
String traverse_expr(Expr const& expr) {
    return std::visit(TraverseExpr{}, expr);
}

struct TypeCheckExpr {
    TypeEnv env;

    Typed<ValueType> operator()(VarExpr const& e) {
        return env.lookupVarType(e.name);
    }

    Typed<ValueType> operator()(BinOpExpr const& e) {
        Typed<ValueType> lhs = type_check_expr(env, *e.left);
        Typed<ValueType> rhs = type_check_expr(env, *e.right);

        if(!lhs) {
            return lhs.error();
        }

        if(!rhs) {
            return rhs.error();
        }

        String name(opString(e.op));
        Vector<ValueType> type = { lhs.value(), rhs.value() };
        CanonName canonName(name, type);

        return env.lookupRuleType(canonName);
    }

    Typed<ValueType> operator()(IntExpr) {
        return intType;
    }

    Typed<ValueType> operator()(StrExpr) {
        return strType;
    }

    Typed<ValueType> operator()(BoolExpr) {
        return boolType;
    }
};

struct TypeCheckStmt {
    TypeEnv env;

    Typed<ValueType> operator()(WhileStmt const& s) {
        ValueType temp("");
        if(auto expr_type = type_check_expr(env, s.cond)) {
            temp = expr_type.value();
        } else {
            return expr_type.error();
        }

        for(auto & bs: s.block.stmts) {
            if(auto stmt_type = type_check_stmt(env, bs)) {
                temp = stmt_type.value();
            } else {
                return stmt_type.error();
            }
        }

        return temp;
    }

    Typed<ValueType> operator()(IfStmt const& s) {
        ValueType temp("");
        for(auto & e: s.conds) {
            if(auto expr_type = type_check_expr(env, e)) {
                temp = expr_type.value();
            } else {
                return expr_type.error();
            }
        }

        for(auto & b: s.blocks) {
            for(auto & bs: b.stmts) {
                if(auto stmt_type = type_check_stmt(env, bs)) {
                    temp = stmt_type.value();
                } else {
                    return stmt_type.error();
                }
            }
        }

        return temp;
    }

    Typed<ValueType> operator()(DecStmt const& s) {
        if(auto expr_type = type_check_expr(env, s.expr)) {
            if(expr_type.value() == s.type) {
                return s.type;
            } else {
                return TypeError{ "Improperly declared var" };
            }
        } else {
            return expr_type.error();
        }
    }

    Typed<ValueType> operator()(AssignStmt const& s) {
        if(auto var_type = env.lookupVarType(s.name)) {
            if(auto expr_type = type_check_expr(env, s.expr)) {
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

    Typed<ValueType> operator()(ExitStmt const& s) {
        return type_check_expr(env, s.value);
    }
};

Typed<ValueType> type_check_expr(TypeEnv& env, Expr const& expr) {
    return std::visit(TypeCheckExpr{ env }, expr);
}

Typed<ValueType> type_check_stmt(TypeEnv& env, Stmt const& stmt) {
    return std::visit(TypeCheckStmt{ env }, stmt);
}

Typed<ValueType> type_check_event_decstmt(TypeEnv& env, DecStmt const& dec) {
    if(auto expr_type = type_check_expr(env, dec.expr)) {
        if(expr_type.value() == dec.type) {
            env.addVarType(dec.name, dec.type);
            return dec.type;
        } else {
            return TypeError{ "Improperly declared var" };
        }
    } else {
        return expr_type.error();
    }
}

Typed<ValueType> type_check_defevent(TypeEnv& env, DefEvent const& event) {
    ValueType temp("");
    env.addEvent(event.name);

    for(auto & d: event.decs) {
        if(auto decstmt_type = type_check_event_decstmt(env, d)) {
            temp = decstmt_type.value();
        } else {
            return decstmt_type.error();
        }
    }

    return temp;
}

Typed<ValueType> type_check_goifstmt(TypeEnv& env, GoIfStmt const& stmt) {
    ValueType temp("");
    for(auto & e: stmt.conds) {
        if(auto expr_type = type_check_expr(env, e)) {
            temp = expr_type.value();
        } else {
            return expr_type.error();
        }
    }
    
    for(auto & n: stmt.names) {
        if(!env.lookupState(n)) {
            return TypeError{ "State not declared" };
        }
    }

    for(auto & b: stmt.blocks) {
        for(auto & bs: b.stmts) {
            if(auto stmt_type = type_check_stmt(env, bs)) {
                temp = stmt_type.value();
            } else {
                return stmt_type.error();
            }
        }
    }

    return temp;
}

Typed<ValueType> type_check_onstmt(TypeEnv& env, OnStmt const& stmt) {
    if(env.lookupEvent(stmt.event))
        return type_check_goifstmt(env, stmt.gostmt);
    else
        return TypeError{ "Event not declared" };
}

Typed<ValueType> type_check_statestmt(TypeEnv& env, StateStmt const& stmt) {
    ValueType temp("");

    if(!env.lookupState(stmt.name)) {
        return TypeError{ "State not declared" };
    }

    for(auto & s: stmt.stmts) {
        if(auto stmt_temp = type_check_stmt(env, s)) {
            temp = stmt_temp.value();
        } else {
            return stmt_temp.error();
        }
    }

    for(auto & ons: stmt.onstmts) {
        if(auto on_temp = type_check_onstmt(env, ons)) {
            temp = on_temp.value();
        } else {
            return on_temp.error();
        }
    }

    for(auto & state: stmt.states) {
        type_check_statestmt(env, state);
    }

    return temp;
}

TypeEnv type_check_program(Program const& program) {
    TypeEnv env;
    setLogger(config::logFileName, config::logLevel);

    traverse_state(env, program.main_state);

    for(auto & e: program.defevents) {
        if(auto event_temp = type_check_defevent(env, e)) {
            // ok
        } else {
            L_(ldebug) << "Type error: " << event_temp.error().what << "\n";
        }
    }

    if(auto state_temp = type_check_statestmt(env, program.main_state)) {
        // ok
    } else {
        L_(ldebug) << "Type error: " << state_temp.error().what << "\n";
    }
    
    return env;
}

} // namespace act
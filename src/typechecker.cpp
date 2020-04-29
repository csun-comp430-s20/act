#include <iostream>
#include "typechecker.hpp"

namespace act {

ValueTyped TypeEnv::lookupDecValue(String const& name) const {
    ValueType const* type = lookup(declmap, name);

    if (type) {
        return *type;
    }
    else {
        return TypeError{ "Value not declared for " + name };
    }
}

struct TypeCheckStmt {
    TypeEnv env;
    
    ValueTyped operator()(DecStmt const& s) {
        env.declmap.insert({ s.name, s.type });

        ValueType expr_type = get_expr_type(*s.exprs);
        if(expr_type == s.type)
            return s.type;
        else if(expr_type == undefinedType)
            return TypeError{ "Incorrect binop expr" };
        else
            return TypeError{ "Incorrect type in DecStmt" };
    }

    ValueTyped operator()(AssignStmt const& s) {
        if(auto val = env.lookupDecValue(s.name)) {
            ValueType expr_type = get_expr_type(*s.exprs);
            if(expr_type == val.value())
                return val.value();
            else if(expr_type == undefinedType)
                return TypeError{ "Incorrect binop expr" };
            else
                return TypeError{ "Incorrect type in AssignStmt" };
        } else {
            return val.error();
        } 
    }
};

ValueTyped type_check_stmt(TypeEnv& env, Stmt const& stmt) {
    return std::visit(TypeCheckStmt{ env }, stmt);
}

TypeEnv typeCheck(Program const& program) {
    TypeEnv env;

    for (Stmt const& stmt : program.stmts) {
        if(auto val = type_check_stmt(env, stmt)) {
            std::cout << "The value is " << val.value().toString() << std::endl;
        } else {
            std::cout << "The error is " << val.error().what << std::endl;
        }
    }

    return env;
}

} // namespace act
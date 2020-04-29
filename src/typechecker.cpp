#include <iostream>
#include "typechecker.hpp"

namespace act {

TypeEnv::TypeEnv() {
    initialize();
}

void TypeEnv::initialize() {

    auto binopRule = [&](BinOp op, ValueType const& ret, ValueType const& args) {
        
        String name(opString(op));
        MethodType type(ret, { args });
        CanonName canonName(name, type);
        _rules.insert({ canonName, ret });
    };

    ValueType const i = intType;
    ValueType const b = boolType;
    ValueType const s = strType;

    binopRule(BinOp::opPlus, i, i);     // +(int)
    binopRule(BinOp::opPlus, s, s);     // +(str)

    binopRule(BinOp::opLess, b, i);     // <(int)
    binopRule(BinOp::opLess, b, s);

    binopRule(BinOp::opGreater, b, i);  // >(int)
    binopRule(BinOp::opGreater, b, s);

    binopRule(BinOp::opEqual, b, i);    // ==(int)
    binopRule(BinOp::opEqual, b, s);
    binopRule(BinOp::opEqual, b, b);

}

String TypeEnv::opString(BinOp const& op) {
    String str;

    switch (op) {
        case BinOp::opPlus: str = "+"; break;
        case BinOp::opLess: str = "<"; break;
        case BinOp::opGreater: str = ">"; break;
        case BinOp::opEqual: str = "=="; break;
    }

    return str;
}

ValueTyped TypeEnv::lookupRuleValueType(CanonName const& name) const {
    ValueType const* type = lookup(_rules, name);

    if (type) {
        return *type;
    }
    else {
        return TypeError{ "Invalid operands to operator: " + name.canonName() };
    }
}

ValueTyped TypeEnv::lookupDecValue(String const& name) const {
    ValueType const* type = lookup(declmap, name);

    if (type) {
        return *type;
    }
    else {
        return TypeError{ "Value not declared for " + name };
    }
}

struct GetExprType {
    ValueType operator()(BinOpExpr const& e) {
        auto t1 = get_expr_type(*e.left);
        auto t2 = get_expr_type(*e.right);

        if(!isBuiltinType(t2)) {
            return undefinedType;
        }
        
        // NOTE STUCK HERE
        return (t1 == t2) ? t1 : undefinedType;
    }

    ValueType operator()(IntExpr const& e) {
        return e.type();
    }

    ValueType operator()(StrExpr const& e) {
        return e.type();
    }

    ValueType operator()(BoolExpr const& e) {
        return e.type();
    }
};

struct TypeCheckStmt {
    TypeEnv env;
    
    ValueTyped operator()(DecStmt const& s) {
        env.declmap.insert({ s.name, s.type });

        if(get_expr_type(*s.exprs) == s.type)
            return s.type;
        else
            return TypeError{ "Incorrect type in DecStmt" };
    }

    ValueTyped operator()(AssignStmt const& s) {
        if(auto val = env.lookupDecValue(s.name)) {
            if(get_expr_type(*s.exprs) == val.value())
                return val.value();
            else
                return TypeError{ "Incorrect type in AssignStmt" };
        } else {
            return val.error();
        } 
    }
};

ValueType get_expr_type(Expr const& expr) {
    return std::visit(GetExprType{}, expr);
}

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
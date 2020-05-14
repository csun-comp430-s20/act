#include "print.hpp"

namespace act {

String opString(BinOp const& op) {
    String str = "";

    switch (op) {
        case BinOp::opPlus: str = "+"; break;
        case BinOp::opLess: str = "<"; break;
        case BinOp::opGreater: str = ">"; break;
        case BinOp::opEqual: str = "=="; break;
    }

    return str;
}

struct GetTokenId {
    template <typename T>
    Id operator()(T const& t) { return t.tid; }
};

struct GetTokenStr {
    template <typename T>
    String operator()(T const& t) { return t.to_string(); }
};

struct PrintStmt {
    String operator()(DecStmt const& s) {
        String str;
        str = "("
            + s.type.toString() 
            + " (" 
            + s.name
            + ") (=) ";
        
        str += print_expr(s.expr);

        return str + ")";
    }

    String operator()(AssignStmt const& s) {
        String str;
        str = "("
            + s.name
            + " = ";
        
        str += print_expr(s.expr);

        return str + ")";
    }

    String operator()(IfStmt const& s) {
        String str;

        str = "(if(";

        bool first = true;
        unsigned cond_ctr = 0;
        if(!s.has_else) {
            for(auto & b: s.blocks) {
                if(first) { // print if statement
                    str += print_expr(s.conds[cond_ctr])
                        + ") {\n";
                    
                    for(auto & stmt: b.stmts) {
                        str += print_stmt(stmt) + "\n";
                    }

                    str += "}";
                    first = false;
                    cond_ctr++;
                } else {
                    str += " elif("
                        + print_expr(s.conds[cond_ctr])
                        + ") {\n";
                    
                    for(auto & stmt: b.stmts) {
                        str += print_stmt(stmt) + "\n";
                    }

                    str += "}";
                    cond_ctr++;
                }
            }
        } else {
            for(unsigned b_ctr = 0; b_ctr < s.blocks.size(); b_ctr++) {
                if(b_ctr != s.blocks.size()-1) {
                    if(first) {
                        str += print_expr(s.conds[cond_ctr])
                            + ") {\n";
                    
                        for(auto & stmt: s.blocks[b_ctr].stmts) {
                            str += print_stmt(stmt) + "\n";
                        }

                        str += "}";
                        first = false;
                        cond_ctr++;
                    } else {
                        str += " elif("
                            + print_expr(s.conds[cond_ctr])
                            + ") {\n";
                        
                        for(auto & stmt: s.blocks[b_ctr].stmts) {
                            str += print_stmt(stmt) + "\n";
                        }

                        str += "}";
                        cond_ctr++;
                    }
                } else { // print else statement
                    str += String(" else{\n");
                        
                    for(auto & stmt: s.blocks[b_ctr].stmts) {
                        str += print_stmt(stmt) + "\n";
                    }

                    str += "}";
                }
            }
        }

        return str + ")";
    }

    String operator()(WhileStmt const& s) {
        String str;

        str = "while("
            + print_expr(s.cond)
            + ") {\n";
        
        for(auto & stmt: s.block.stmts) {
            str += print_stmt(stmt) + "\n";
        }

        return str + "})";
    }
};

struct PrintExpr {
    String operator()(VarExpr const& e) {
        return "(" + e.name + ")";
    }

    String operator()(BinOpExpr const& e) {
        return "("
            + print_expr(*e.left)
            + " "
            + print_op(e.op)
            + " "
            + print_expr(*e.right)
            + ")";
    }

    String operator()(IntExpr const& e) {
        return "(" + to_string(e.value) + ")";
    }

    String operator()(StrExpr const& e) {
        return "(" + e.value + ")";
    }

    String operator()(BoolExpr const& e) {
        return "(" + to_string(e.value) + ")";
    }
};

String print_value_type(ValueType const& t) {
    return "(" + t.toString() + ")";
}

String print_op(BinOp const& op) {
    String str;

    switch (op) {
        case BinOp::opPlus: str = "+"; break;
        case BinOp::opLess: str = "<"; break;
        case BinOp::opGreater: str = ">"; break;
        case BinOp::opEqual: str = "=="; break;
    }

    return "(" + str + ")";
}

String print_id(Id const& i) {
    return "[" + to_string(static_cast<int>(i)) + "]";
}

String print_token(Token const& token) {
    return std::visit(GetTokenStr{}, token);
}

String print_fancy_token(Token const& token) {
    return print_id(std::visit(GetTokenId{}, token))
            + std::visit(GetTokenStr{}, token);
}

String print_expr(Expr const& expr) {
    return std::visit(PrintExpr{}, expr);
}

String print_stmt(Stmt const& stmt) {
    return std::visit(PrintStmt{}, stmt);
}

String print_decstmt_only(DecStmt const& d) {
    String str;
    str = "("
        + d.type.toString() 
        + " (" 
        + d.name
        + ") (=) ";
    
    str += print_expr(d.expr);

    return str + ")";
}
String print_defstate(DefState const& defstate) {
    return "(" + defstate.name + ")";
}
String print_defevent(DefEvent const& event) {
    String str;

    str = "("
        + String("defevent ")
        + event.name
        + "{\n";
    
    for(auto & d : event.decs) {
        str += "\t" + print_decstmt_only(d) + "\n";
    }

    return str + "})";
}

String print_goifstmt(GoIfStmt const& s) {
    String str;

    str = "(goif(";

    bool first = true;
    unsigned ctr = 0;
    if(!s.has_else) {
        for(auto & b: s.blocks) {
            if(first) { // print if statement
                str += print_expr(s.conds[ctr])
                    + ") " + s.names[ctr] +  " {\n";
                
                for(auto & stmt: b.stmts) {
                    str += print_stmt(stmt) + "\n";
                }

                str += "}";
                first = false;
                ctr++;
            } else {
                str += " goelif("
                    + print_expr(s.conds[ctr])
                    + ") " + s.names[ctr] + " {\n";
                
                for(auto & stmt: b.stmts) {
                    str += print_stmt(stmt) + "\n";
                }

                str += "}";
                ctr++;
            }
        }
    } else {
        for(unsigned b_ctr = 0; b_ctr < s.blocks.size(); b_ctr++) {
            if(b_ctr != s.blocks.size()-1) {
                if(first) {
                    str += print_expr(s.conds[ctr])
                        + ") {\n";
                
                    for(auto & stmt: s.blocks[b_ctr].stmts) {
                        str += print_stmt(stmt) + "\n";
                    }

                    str += "}";
                    first = false;
                    ctr++;
                } else {
                    str += " goelif("
                        + print_expr(s.conds[ctr])
                        + ") " + s.names[ctr] + " {\n";
                    
                    for(auto & stmt: s.blocks[b_ctr].stmts) {
                        str += print_stmt(stmt) + "\n";
                    }

                    str += "}";
                    ctr++;
                }
            } else { // print else statement
                str += " goelse " + s.names[ctr] + " {\n";
                    
                for(auto & stmt: s.blocks[b_ctr].stmts) {
                    str += print_stmt(stmt) + "\n";
                }

                str += "}";
            }
        }
    }

    return str + ")";
}

String print_onstmt(OnStmt const& s) {
    String str;

    str = "on " + s.event + " {\n";

    str += print_goifstmt(s.gostmt) + "\n}";

    return str + ")";
}

String print_statestmt(StateStmt const& s) {

    String str = "(state " + s.name + "{\n";

    for(auto & base_s: s.stmts) {
        str += print_stmt(base_s) + "\n";
    }

    for(auto & o: s.onstmts) {
        str += print_onstmt(o) + "\n";
    }

    for(auto & state: s.states) {
        str += print_statestmt(state) + "\n";
    }
    
    return str + "}";
}

String print_program(Program const& program) {
    String result = "";

    for(auto & state: program.defstates) {
        result += print_defstate(state) + "\n";
    }

    for(auto & event: program.defevents) {
        result += print_defevent(event) + "\n";
    }

    result += print_statestmt(program.main_state);

    return result + ")";
}

} // namespace act

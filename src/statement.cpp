#include "statement.hpp"

id_node::id_node(std::string name) { id = name; }
void id_node::print() { std::cout << id; }
exp_node id_node::evaluate() { 
    // std::cout << "id_node: " << id << " = " << idTable[id] << endl;
    return idTable[id];
}

print_stmt::print_stmt(std::string name) { id = name; }

void print_stmt::evaluate() {
    std::cout << "print_node: " << id << " = ";
    idTable[id].print();
    std::cout << std::endl;
}

assignment_stmt::assignment_stmt(std::string dec_type, std::string name, exp_node expression) {
    type = dec_type;
    id = name;
    expr = expression;
}

void assignment_stmt::print() {
    std::cout << type << " " << id << " = ";
    expr.print();
    std::cout << std::endl;
}

void assignment_stmt::evaluate() {
    std::cout << "assignment_node: " << type << " " << id << " = ";
    expr.print();
    std::cout << std::endl;
    idTable[id] = expr;
    typeTable[id] = type;
}

std::map<std::string, exp_node> idTable;
std::map<std::string, std::string> typeTable;

#include "statement.hpp"

print_stmt::print_stmt (std::string name) : id(name) {}

void print_stmt::evaluate() {
  std::cout << "print_node: " << id << " = " << idTable[id].print() << std::endl;
}

declaration_stmt::declaration_stmt(std::string dec_type, std::string name)
  : type(dec_type), id(name) {}

void declaration_stmt::print() {
    std::cout << type << " " << id << std::endl;
}

void declaration_stmt::evaluate() {
    exp_val result = exp->evaluate();
    std::cout << "assignment_node: " << type << " " << id << " = " << result << std::endl;
    idTable[id] = result;
    typeTable[id] = type;
}

assignment_stmt::assignment_stmt(std::string dec_type, std::string name, exp_node *expression)
  : type(dec_type), id(name), exp(expression) {}

void assignment_stmt::print() {
    std::cout << type << " " << id << " = ";
    exp->print();
}

void assignment_stmt::evaluate() {
    exp_val result = exp->evaluate();
    std::cout << "assignment_node: " << type << " " << id << " = " << result << std::endl;
    idTable[id] = result;
    typeTable[id] = type;
}

// std::map<std::string, std::string> typeTable;
// std::map<std::string, exp> idTable;
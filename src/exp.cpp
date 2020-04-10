#include "exp.hpp"

operator_node::operator_node(exp_node *L, exp_node *R) {
    left = L;
    right = R;
}

number_node::number_node(std::variant<std::string, bool, int> val) {
    value = val;
    type = std::string("int");
}

number_node number_node::operator+(number_node& lhs, const number_node& rhs) {
    int new_num = lhs.evaluate() + rhs.evaluate();
    lhs.value = new_num;
    return lhs;
}

void number_node::print() {
    std::cout << std::get<int>(value);
}

int number_node::evaluate() { 
    std::cout << "number_node: operand = " << std::get<int>(value) << std::endl;
    return std::get<int>(value);
}

bool_node::bool_node(std::variant<std::string, bool, int> val) : exp_node(val, "bool") {}

void bool_node::print() {
    std::cout << std::get<bool>(value);
}

bool bool_node::evaluate() { 
    std::cout << "number_node: operand = " << std::get<bool>(value) << std::endl;
    return std::get<bool>(value);
}

string_node::string_node(std::variant<std::string, bool, int> val) : exp_node(val, "string") {}

void string_node::print() {
    std::cout << std::get<std::string>(value);
}

bool string_node::evaluate() { 
    std::cout << "number_node: operand = " << std::get<std::string>(value) << std::endl;
    return std::get<std::string>(value);
}

id_node::id_node(std::string val) : id(val) {}

void id_node::print() {
    std::cout << id;
}

exp_node id_node::evaluate() { 
    std::cout << "id_node: " << id << " = " << idTable[id] << std::endl;
    return idTable[id];
}

plus_node::plus_node(exp_node *L, exp_node *R) : operator_node(L,R) {}

void plus_node::print() {
    std::cout << "(";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << ")" << std::endl;
}

std::variant<std::string, int, bool> plus_node::evaluate() {
    std::variant<std::string, int, bool> left_num, right_num;

    left_num  = left->evaluate();
    right_num = right->evaluate();

    value = left_num + right_num;
    std::cout << "plus_node: " << left_num << " + " << right_num << " = " << value << std::endl;
    return value;
}

cat_node::cat_node(exp_node *L, exp_node *R) : operator_node(L,R) {}

void cat_node::print() {
    std::cout << "(";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << ")" << std::endl;
}

std::string cat_node::evaluate() {
    std::string left_str, right_str;

    left_str  = left->evaluate();
    right_str = right->evaluate();

    value = left_str + right_str;
    std::cout << "string_node: " << left_str << " + " << right_str << " = " << value << std::endl;
    return value;
}

less_node::less_node(exp_node *L, exp_node *R) : operator_node(L,R) {}

void less_node::print() {
    std::cout << "(";
    left->print();
    std::cout << " < ";
    right->print();
    std::cout << ")" << std::endl;
}

bool less_node::evaluate() {
    int left_str, right_str;

    left_str  = left->evaluate();
    right_str = right->evaluate();

    value = left_str < right_str;
    std::cout << "string_node: " << left_str << " < " << right_str << " = " << value << std::endl;
    return value;
}

std::map<std::string, exp_node> idTable;
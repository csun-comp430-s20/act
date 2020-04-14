#include "exp.hpp"

int_node::int_node() { value = std::monostate(); }
int_node::int_node(const int& val) { value = val; }
void int_node::print() { std::cout << std::get<int>(value); }
void int_node::set(const int& val) { value = val; }
types int_node::evaluate() const { return std::get<int>(value); }
int_node int_node::operator+(const int_node& node) {
    int_node new_node;
    new_node.value = std::get<int>(this->value) + std::get<int>(node.value);
    return new_node;
}

bool_node::bool_node() { value = std::monostate(); }
bool_node::bool_node(const bool val) { value = val; }
void bool_node::print() { std::cout << std::get<bool>(value); }
void bool_node::set(const bool val) { value = val; }
types bool_node::evaluate() const { return std::get<bool>(value); }

bool_node operator==(const exp_node& node1, const exp_node& node2) {
    bool_node new_node;
    bool temp = node1.evaluate() == node2.evaluate();
    new_node.set(temp);
    return new_node;
}

bool_node operator<(const exp_node& node1, const exp_node& node2) {
    bool_node new_node;
    bool temp = node1.evaluate() < node2.evaluate();
    new_node.set(temp);
    return new_node;
}

bool_node operator>(const exp_node& node1, const exp_node& node2) {
    bool_node new_node;
    bool temp = node1.evaluate() > node2.evaluate();
    new_node.set(temp);
    return new_node;
}

string_node::string_node() { value = std::monostate(); }
string_node::string_node(const std::string val) { value = val; }
void string_node::print() { std::cout << std::get<std::string>(value); }
void string_node::set(const std::string val) { value = val; }
types string_node::evaluate() const { return std::get<std::string>(value); }
string_node string_node::operator+(const string_node& node) {
    string_node new_node;
    new_node.value = std::get<std::string>(this->value) + std::get<std::string>(node.value);
    return new_node;
}

// int main() { return 0; }
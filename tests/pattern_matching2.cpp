#include <variant>
#include <iostream>
#include <string>

// template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
// template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

using types = std::variant<std::monostate, int, bool, std::string>;

class exp_node {
    protected:
    types value;
    
    public:
    virtual void print() = 0;
    virtual types evaluate() const = 0;
};

class int_node : public exp_node {
    public:
    int_node() {
        value = std::monostate();
    }

    int_node(const int val) {
        value = val;
    }

    void set(const int val) {
        value = val;
    }

    void print() {
        std::cout << std::get<int>(value) << std::endl;
    }
    
    types evaluate() const {
        return std::get<int>(value);
    }

    int_node operator+(const int_node& node) {
        int_node new_node;
        new_node.value = std::get<int>(this->value) + std::get<int>(node.value);
        return new_node;
    }
};

class bool_node : public exp_node {
    public:
    bool_node() {
        value = std::monostate();
    }

    bool_node(const bool val) {
        value = val;
    }

    void set(const bool val) {
        value = val;
    }

    void print() {
        std::cout << std::get<bool>(value) << std::endl;
    }
    
    types evaluate() const {
        return std::get<bool>(value);
    }
};

class string_node : public exp_node {
    public:
    string_node() {
        value = std::monostate();
    }

    string_node(const std::string val) {
        value = val;
    }

    void set(const std::string val) {
        value = val;
    }

    void print() {
        std::cout << std::get<std::string>(value) << std::endl;
    }
    
    types evaluate() const {
        return std::get<std::string>(value);
    }

    string_node operator+(const string_node& node) {
        string_node new_node;
        new_node.value = std::get<std::string>(this->value) + std::get<std::string>(node.value);
        return new_node;
    }
};

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

int main() {

    // int_node node1 = int_node(10);
    // node1.print();

    // int_node node2 = node1 + node1;
    // node2.print();

    // bool_node test_equal = node1 == node1;
    // bool_node test_equal2 = node1 == node2;

    // std::cout << "Test equal 1:\n"; 
    // test_equal.print();
    // std::cout << "Test equal 2:\n";
    // test_equal2.print();

    // bool_node test_bool = test_equal == test_equal;
    // bool_node test_bool2 = test_equal == test_equal2;

    // std::cout << "Test equal bool 1:\n"; 
    // test_bool.print();
    // std::cout << "Test equal bool 2:\n"; 
    // test_bool2.print();

    // string_node str_node1 = string_node(std::string("Hello"));
    // str_node1.print();

    // string_node str_node2 = str_node1 + str_node1;
    // str_node2.print();

    // bool_node test_bool_str1 = str_node1 == str_node2;
    // test_bool_str1.print();
    // bool_node test_bool_str2 = str_node1 == str_node1;
    // test_bool_str2.print();

    // bool_node temp_bool = bool_node(false);
    // temp_bool.print();

    // bool_node test_str_comp = str_node1 < str_node2;
    // test_str_comp.print();

    

    return 0;
}
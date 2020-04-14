#pragma once

#include <iostream>
#include <variant>
#include <string>

// template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
// template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

using types = std::variant<std::monostate, int, bool, std::string>;

class exp_node {
    protected:
    types value;
    
    public:
    exp_node() { value = std::monostate(); };
    virtual void print() { std::cout << "Not Implemented"; }
    virtual types evaluate() const { return std::monostate(); }
    virtual exp_node operator+(const exp_node& node) {
        exp_node new_node;
        new_node.value = std::monostate();
        return new_node;
    };
};

class int_node : public exp_node {
    public:
    int_node();
    int_node(const int val);
    void print();
    void set(const int val);
    types evaluate() const;
    int_node operator+(const int_node& node);
};

class bool_node : public exp_node {
    public:
    bool_node();
    bool_node(const bool val);
    void print();
    void set(const bool val);
    types evaluate() const;
};

bool_node operator==(const exp_node& node1, const exp_node& node2);
bool_node operator<(const exp_node& node1, const exp_node& node2);
bool_node operator>(const exp_node& node1, const exp_node& node2);

class string_node : public exp_node {
    public:
    string_node();
    string_node(const std::string val);
    void print();
    void set(const std::string val);
    types evaluate() const;
    string_node operator+(const string_node& node);
};

// class id_node : public exp_node {
//     protected:
//     string id;

//     public:
//     id_node(string value);
//     void print();
//     float evaluate();
// };

// extern std::map<std::string, exp_node> idTable;
#pragma once

#include <map>
#include "exp.hpp"

class id_node {
    private:
    std::string id;

    public:
    id_node(std::string val);
    void print();
    exp_node evaluate();
};

class statement {
    public:
    virtual void print() { std::cout << "Not Implemented"; }
    virtual void evaluate() { std::cout << "Not Implemented"; }
};

class print_stmt: public statement {
    protected:
    std::string id;

    public:
    print_stmt(std::string id);
    void evaluate();
};

class assignment_stmt : public statement {
    protected:
    std::string type;
    std::string id;
    exp_node expr;
    public:
    assignment_stmt(std::string& dec_type, std::string& name, exp_node& expression);
    void print();
    void evaluate();
};

extern std::map<std::string, exp_node> idTable;
extern std::map<std::string, std::string> typeTable;
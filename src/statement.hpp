#include <iostream>
#include <map>
#include <string>

#include "exp.hpp"


class statement {
    public:
    virtual void print() {}
    virtual void evaluate() = 0;
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
    exp_node *exp;
    public:
    assignment_stmt(std::string name, exp_node *expression);
    void print();
    void evaluate();
};

class declaration_stmt : public statement {
    protected:
    std::string type;
    std::string id;
    public:
    assignment_stmt(std::string name, exp_node *expression);
    void print();
    void evaluate();
};
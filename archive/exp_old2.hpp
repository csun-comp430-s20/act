#include <iostream>
#include <variant>
#include <string>
#include <map>
#include <list>

class exp_node {
    private:
    std::variant<std::string, int, bool> value;
    std::string type;
    std::function<exp_node(exp_node, exp_node)> op;

    public:
    int evaluate();
    bool evaluate();
    std::string evaluate();

}

// class exp_node {
//     protected:
//     std::variant<std::string, int, bool> value;
//     std::string type;

//     public:
//     exp_node(std::variant<std::string, int, bool> val);
//     virtual void print() = 0;
// };

// class exp_node {
//     protected:
//     std::variant<std::string, int, bool> value;

//     public:
//     // print function for pretty printing an expression
//     virtual void print() = 0;

//     // evaluation function for a leaf, replaced for interior nodes
//     // virtual int evaluate() = 0;
// };

class operator_node : public exp_node {
    public:
    exp_node *left;
    exp_node *right;
    std::function<exp_node(exp_node, exp_node)> op;

    operator_node(exp_node *L, exp_node *R);
};

class number_node : public exp_node {
    public:
    number_node(std::variant<std::string, int, bool> val);
    number_node operator+(number_node&, const number_node&);
    void print();
    int evaluate();
};

class bool_node : public exp_node {
    public:
    bool_node(std::variant<std::string, int, bool> val);
    void print();
    bool evaluate();
};

class string_node : public exp_node {
    public:
    string_node(std::variant<std::string, int, bool> val);
    void print();
    std::string evaluate();
};

class id_node : public exp_node {
    protected:
    std::string id;

    public:
    id_node(std::string value);
    void print();
    exp_node evaluate();
};

class plus_node : public operator_node {
    public:
    plus_node(exp_node *L, exp_node *R);
    void print();
    exp_node evaluate();
};

class less_node : public operator_node {
    public:
    less_node(exp_node *L, exp_node *R);
    void print();
    bool evaluate();
}

class greater_node : public operator_node {
    public:
    greater_node(exp_node *L, exp_node *R);
    void print();
    bool evaluate();
}

class equal_node : public operator_node {
    public:
    equal_node(exp_node *L, exp_node *R);
    void print();
    bool evaluate();
}

extern std::map<std::string, std::string> typeTable;
extern std::map<std::string, exp_node> idTable;
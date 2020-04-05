#include <variant>
#include <string>

class exp_node {
    public:
    std::variant<std::string, int, bool> value;

    // print function for pretty printing an expression
    virtual void print() = 0;

    // evaluation function for a leaf, replaced for interior nodes
    virtual int evaluate() = 0;
};

class operator_node : public exp_node {
    public:
    exp_int_node *left;
    exp_int_node *right;

    operator_int_node(exp_int_node *L, exp_int_node *R);
};

class number_node : public exp_node {
    public:
    number_node(int val);
    void print();
    int evaluate();
};

class id_node : public exp_node {
    protected:
    string id;

    public:
    id_node(string value);
    void print();
    float evaluate();
};
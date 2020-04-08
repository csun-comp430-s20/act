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
    exp_node *left;
    exp_node *right;

    operator_node(exp_node *L, exp_node *R);
};

class number_node : public exp_node {
    public:
    number_node(int val);
    void print();
    int evaluate();
};

class bool_node : public exp_node {
    public:
    number_node(bool val);
    void print();
    bool evaluate();
};

class string_node : public exp_node {
    public:
    number_node(std::string val);
    void print();
    std::string evaluate();
};

class id_node : public exp_node {
    protected:
    std::string id;

    public:
    id_node(std::string value);
    void print();
    std::variant<std::string, int, bool> evaluate();
};

class plus_node : public operator_node {
  public:

  plus_node(exp_node *L, exp_node *R);
  void print();
  int evaluate();
};

class cat_node : public operator_node {
  public:

  cat_node(exp_node *L, exp_node *R);
  void print();
  std::string evaluate();
};


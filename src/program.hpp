#include <list>

class pgm {
    protected:
    std::list<statement *> *stmts;
    public:
    pgm(std::list<statement *> *stmtlist);
    void evaluate();
};

extern pgm *root;
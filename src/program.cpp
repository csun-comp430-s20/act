#include "program.hpp"

pgm::pgm(std::list<statement *> *stmtList) : stmts(stmtList) {}

void pgm::evaluate() {
    std::list<statement *>::iterator stmtIter;
    for (stmtIter = stmts->begin(); stmtIter != stmts->end();
        stmtIter++) {
        (*stmtIter)->print();
        (*stmtIter)->evaluate();
    }
}
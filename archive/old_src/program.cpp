#include "program.hpp"

program::program(std::list<statement> stmtList) : stmts(stmtList) {}

void program::evaluate() {
    std::cout << "This is being called!" << std::endl;

    // std::list<statement>::iterator stmtIter;
    // for (stmtIter = stmts.begin(); stmtIter != stmts.end();
    //     stmtIter++) {
    //     (*stmtIter).print();
    //     (*stmtIter).evaluate();
    // }
    std::cout << "This is the size " << stmts.size() << std::endl;
    
    for(auto& stmt : stmts) {
        stmt.print();
        stmt.evaluate();
    }
}
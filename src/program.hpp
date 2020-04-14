#pragma once

#include <list>
#include "statement.hpp"

class program {
    protected:
    std::list<statement> stmts;
    public:
    program() {}
    program(std::list<statement> stmtlist);
    void evaluate();
};
#include <cxxtest/TestSuite.h>
#include <string>

#include "parser.hpp"
#include "lex.yy.h"


class ActTestSuite : public CxxTest::TestSuite {
    public:
    // void testAddition(void) {
    //     TS_ASSERT(1 + 1 > 1);
    //     TS_ASSERT_EQUALS(1 + 1, 2);
    // }

    void testArgs() {
        std::string args_str = "int, bool, string";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }
};
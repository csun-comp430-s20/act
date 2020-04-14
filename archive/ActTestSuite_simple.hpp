#include <cxxtest/TestSuite.h>
#include <string>

#include "parser.hpp"
#include "lex.yy.h"
#include <iostream>

// NOTE: Create Test Suite for Lexer also. Call this ActTestParserSuite
class ActTestSuite : public CxxTest::TestSuite {
    public:

    void testEmpty() {
        std::string args_str = "";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0);
    }

    void testEventDef() {
        std::string args_str = "defevent myevent(int, string, bool);";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0);
    }

    void testEventDefMultiLine() {
        std::string args_str = "defevent myevent(int, string, bool);\n"
                               "defevent myevent(int, int);";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0);
    }
};
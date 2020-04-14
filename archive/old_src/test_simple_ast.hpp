#include <cxxtest/TestSuite.h>
#include "parser.hpp"
#include "lex.yy.h"

// NOTE: Create Test Suite for Lexer also. Call this ActTestParserSuite
class test_simple_ast : public CxxTest::TestSuite {
    public:

    void testEmpty() {
        std::string args_str = "";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0);
    }

    void testAssignStmt() {
        std::string args_str = "int var = 2 + 2;";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0);
    }

    // void testEventDefMultiLine() {
    //     std::string args_str = "defevent myevent(int, string, bool);\n"
    //                            "defevent myevent(int, int);";

    //     yy::Lexer lexer(args_str);
    //     yy::parser parser(lexer);
    //     TS_ASSERT(parser.parse() == 0);
    // }
};
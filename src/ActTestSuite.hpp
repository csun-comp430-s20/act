#include <cxxtest/TestSuite.h>
#include <string>

#include "parser.hpp"
#include "lex.yy.h"


class ActTestSuite : public CxxTest::TestSuite {
    public:

    void testEmpty() {
        std::string args_str = "";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testEventDef() {
        std::string args_str = "defevent myevent(int, string, bool);";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testEventDefMultiLine() {
        std::string args_str = "defevent myevent(int, string, bool);\n"
                               "defevent myevent(int, int);";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testDecStmtAdd() {
        std::string args_str = "int myvar = 10 + 20;";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testDecStmtAddMulti() {
        std::string args_str = "int myvar = 10 + 20 + 30;";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testDecStmtAddMultiLine() {
        std::string args_str = "int myvar = 10 + 20 + 30;\n"
                               "int newvar = 20 + 40 + 50 + 100;";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testDecStmtLogicBase() {
        std::string args_str = "bool myvar = true;";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testDecStmtLogicValues() {
        std::string args_str = "bool myvar = 5 > 4;";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testDecStmtLogicAndOr() {
        std::string args_str = "bool myvar = 5 > 4;";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testDecStmtLogicParens() {
        std::string args_str = "bool myvar = (5 > 4) || (4 == 4);";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }
    
};
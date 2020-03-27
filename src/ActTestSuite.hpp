#include <cxxtest/TestSuite.h>
#include <string>

#include "parser.hpp"
#include "lex.yy.h"


class ActTestSuite : public CxxTest::TestSuite {
    public:

    void testEventDef() {
        std::string args_str = "defevent myevent(int, string, bool);";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }

    void testArgs() {
        std::string args_str = "int, bool, string";

        yy::Lexer lexer(args_str);
        yy::parser parser(lexer);
        TS_ASSERT(parser.parse() == 0)
    }
};
// lex.yy.cpp generated by reflex 1.5.8 from lexerspec.l

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define REFLEX_OPTION_YYLTYPE             yy::location
#define REFLEX_OPTION_YYSTYPE             yy::parser::semantic_type
#define REFLEX_OPTION_bison_cc            true
#define REFLEX_OPTION_bison_cc_namespace  yy
#define REFLEX_OPTION_bison_cc_parser     parser
#define REFLEX_OPTION_bison_complete      true
#define REFLEX_OPTION_exception           yy::parser::syntax_error("Unknown token.")
#define REFLEX_OPTION_header_file         "lex.yy.h"
#define REFLEX_OPTION_lex                 lex
#define REFLEX_OPTION_lexer               Lexer
#define REFLEX_OPTION_namespace           yy
#define REFLEX_OPTION_outfile             "lex.yy.cpp"
#define REFLEX_OPTION_token_eof           yy::parser::symbol_type(0)
#define REFLEX_OPTION_token_type          yy::parser::symbol_type

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top{ user code %}                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 1 "lexerspec.l"

    #include "parser.hpp"  /* Generated by bison. */
    #include <string>
    #include <fstream>


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  ABSTRACT LEXER CLASS                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/abslexer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

namespace yy {

class Lexer : public reflex::AbstractLexer<reflex::Matcher> {
 public:
  typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
  Lexer(
      const reflex::Input& input = reflex::Input(),
      std::ostream&        os    = std::cout)
    :
      AbstractBaseLexer(input, os)
  {
  }
  static const int INITIAL = 0;
  virtual yy::parser::symbol_type lex(void);
};

} // namespace yy

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  BISON C++                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

yy::parser::symbol_type yy::Lexer::lex()
{
  static const char *REGEX_INITIAL = "(?m)((?:\\Qtrue\\E))|((?:\\Qfalse\\E))|((?:\\Qif\\E))|((?:\\Qelif\\E))|((?:\\Qelse\\E))|((?:\\Qwhile\\E))|((?:\\Qreturn\\E))|((?:\\Qstate\\E))|((?:\\Qentry\\E))|((?:\\Qexit\\E))|((?:\\Qon\\E))|((?:\\Qmoveto\\E))|((?:\\Qlambda\\E))|((?:\\Qdefevent\\E))|((?:\\Qint\\E))|((?:\\Qbool\\E))|((?:\\Qstring\\E))|((?:\\Q+\\E))|((?:\\Q;\\E))|((?:\\Q{\\E))|((?:\\Q}\\E))|((?:\\Q(\\E))|((?:\\Q)\\E))|((?:\\Q,\\E))|((?:\\Q&&\\E))|((?:\\Q||\\E))|((?:\\Q=<\\E))|((?:\\Q=>\\E))|((?:\\Q<\\E))|((?:\\Q>\\E))|((?:\\Q==\\E))|((?:\\Q=\\E))|([A-Z_a-z][0-9A-Z_a-z]*)|([0-9]+)|((?:\\Q/*\\E)(?:.|\\n)*?(?:\\Q*/\\E))|([\\x09\\x0a\\x0d\\x20])";
  static const reflex::Pattern PATTERN_INITIAL(REGEX_INITIAL);
  if (!has_matcher())
  {
    matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
  }
  while (true)
  {
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
#line 49 "lexerspec.l"
return yy::parser::make_EOF();
            }
            else
            {
              throw yy::parser::syntax_error("Unknown token.");
            }
            break;
          case 1: // rule at line 17: (?:\Qtrue\E)
#line 17 "lexerspec.l"
return yy::parser::make_TRUE(str());
            break;
          case 2: // rule at line 18: (?:\Qfalse\E)
#line 18 "lexerspec.l"
return yy::parser::make_FALSE(str());
            break;
          case 3: // rule at line 19: (?:\Qif\E)
#line 19 "lexerspec.l"
return yy::parser::make_IF(str());
            break;
          case 4: // rule at line 20: (?:\Qelif\E)
#line 20 "lexerspec.l"
return yy::parser::make_ELIF(str());
            break;
          case 5: // rule at line 21: (?:\Qelse\E)
#line 21 "lexerspec.l"
return yy::parser::make_ELSE(str());
            break;
          case 6: // rule at line 22: (?:\Qwhile\E)
#line 22 "lexerspec.l"
return yy::parser::make_WHILE(str());
            break;
          case 7: // rule at line 23: (?:\Qreturn\E)
#line 23 "lexerspec.l"
return yy::parser::make_RETURN(str());
            break;
          case 8: // rule at line 24: (?:\Qstate\E)
#line 24 "lexerspec.l"
return yy::parser::make_STATE(str());
            break;
          case 9: // rule at line 25: (?:\Qentry\E)
#line 25 "lexerspec.l"
return yy::parser::make_ENTRY(str());
            break;
          case 10: // rule at line 26: (?:\Qexit\E)
#line 26 "lexerspec.l"
return yy::parser::make_EXIT(str());
            break;
          case 11: // rule at line 27: (?:\Qon\E)
#line 27 "lexerspec.l"
return yy::parser::make_ON(str());
            break;
          case 12: // rule at line 28: (?:\Qmoveto\E)
#line 28 "lexerspec.l"
return yy::parser::make_MOVETO(str());
            break;
          case 13: // rule at line 29: (?:\Qlambda\E)
#line 29 "lexerspec.l"
return yy::parser::make_LAMBDA(str());
            break;
          case 14: // rule at line 30: (?:\Qdefevent\E)
#line 30 "lexerspec.l"
return yy::parser::make_DEFEVENT(str());
            break;
          case 15: // rule at line 31: (?:\Qint\E)
#line 31 "lexerspec.l"
return yy::parser::make_INT(str());
            break;
          case 16: // rule at line 32: (?:\Qbool\E)
#line 32 "lexerspec.l"
return yy::parser::make_BOOL(str());
            break;
          case 17: // rule at line 33: (?:\Qstring\E)
#line 33 "lexerspec.l"
return yy::parser::make_STRING(str());
            break;
          case 18: // rule at line 34: (?:\Q+\E)
#line 34 "lexerspec.l"
return yy::parser::make_PLUS(str());
            break;
          case 19: // rule at line 35: (?:\Q;\E)
#line 35 "lexerspec.l"
return yy::parser::make_SEMI(str());
            break;
          case 20: // rule at line 36: (?:\Q{\E)
#line 36 "lexerspec.l"
return yy::parser::make_LEFT_BRACE(str());
            break;
          case 21: // rule at line 37: (?:\Q}\E)
#line 37 "lexerspec.l"
return yy::parser::make_RIGHT_BRACE(str());
            break;
          case 22: // rule at line 38: (?:\Q(\E)
#line 38 "lexerspec.l"
return yy::parser::make_LEFT_PAREN(str());
            break;
          case 23: // rule at line 39: (?:\Q)\E)
#line 39 "lexerspec.l"
return yy::parser::make_RIGHT_PAREN(str());
            break;
          case 24: // rule at line 40: (?:\Q,\E)
#line 40 "lexerspec.l"
return yy::parser::make_COMMA(str());
            break;
          case 25: // rule at line 41: (?:\Q&&\E)
#line 41 "lexerspec.l"
return yy::parser::make_AND_OP(str());
            break;
          case 26: // rule at line 42: (?:\Q||\E)
#line 42 "lexerspec.l"
return yy::parser::make_OR_OP(str());
            break;
          case 27: // rule at line 43: (?:\Q=<\E)
#line 43 "lexerspec.l"
return yy::parser::make_LESS_EQUAL(str());
            break;
          case 28: // rule at line 44: (?:\Q=>\E)
#line 44 "lexerspec.l"
return yy::parser::make_GREATER_EQUAL(str());
            break;
          case 29: // rule at line 45: (?:\Q<\E)
#line 45 "lexerspec.l"
return yy::parser::make_LESS(str());
            break;
          case 30: // rule at line 46: (?:\Q>\E)
#line 46 "lexerspec.l"
return yy::parser::make_GREATER(str());
            break;
          case 31: // rule at line 47: (?:\Q==\E)
#line 47 "lexerspec.l"
return yy::parser::make_EQUAL(str());
            break;
          case 32: // rule at line 48: (?:\Q=\E)
#line 48 "lexerspec.l"
return yy::parser::make_ASSIGN(str());
            break;
          case 33: // rule at line 50: [A-Z_a-z][0-9A-Z_a-z]*
#line 50 "lexerspec.l"
return yy::parser::make_IDENTIFIER(str());
            break;
          case 34: // rule at line 51: [0-9]+
#line 51 "lexerspec.l"
return yy::parser::make_NUMBER(atoi(text()));
            break;
          case 35: // rule at line 52: (?:\Q/*\E)(?:.|\n)*?(?:\Q*/\E)
#line 52 "lexerspec.l"
/* no action: ignore multiline comments */
            break;
          case 36: // rule at line 53: [\x09\x0a\x0d\x20]
#line 53 "lexerspec.l"
/* no action: ignore all white space */

            break;
        }
  }
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 3: user code                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


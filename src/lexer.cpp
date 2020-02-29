// lexer.cpp generated by reflex 1.5.8 from lexerspec.l

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define REFLEX_OPTION_lex                 lex
#define REFLEX_OPTION_lexer               Lexer
#define REFLEX_OPTION_outfile             "lexer.cpp"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top{ user code %}                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 1 "lexerspec.l"

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>

    // (\+|=|<|>|==|=<|=>|;|{|}|\(|\)|,|int|bool|string|true|false)


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

class Lexer : public reflex::AbstractLexer<reflex::Matcher> {
#line 10 "lexerspec.l"

    private:
    struct Token {
        private:
        std::string data;

        public:
        Token(const std::string data) {
            this->data = data;
        }

        const std::string get() {
            return this->data;
        }
    };

    public:
    std::vector<Token> tokens;  // lexer class member variable (private by default)

    void printTokens() {
        for (std::vector<Token>::iterator i = tokens.begin(); i != tokens.end(); ++i)
            std::cout << (*i).get() << ' ';
    }

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
  virtual int lex();
  int lex(
      const reflex::Input& input,
      std::ostream        *os = NULL)
  {
    in(input);
    if (os)
      out(*os);
    return lex();
  }
};

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

int Lexer::lex()
{
  static const char *REGEX_INITIAL = "(?m)((?:\\<(?:if|elif|else|while|return|state|entry|exit|on|moveto|lambda|defevent)\\>))|((?:\\<(?:\\+|=|==|=<|=>|;|\\{|\\}|\\(|\\)|,|int|bool|string|true|false)\\>))|((?:\\<(?:[A-Z_a-z][0-9A-Z_a-z]*|[0-9]+|\"(?:[^\"\\x5c]|\\\\\")*\")\\>))|((?:\\Q/*\\E)(?:.|\\n)*?(?:\\Q*/\\E))|([\\x09\\x0a\\x0d\\x20])";
  static const reflex::Pattern PATTERN_INITIAL(REGEX_INITIAL);
  if (!has_matcher())
  {
    matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
  }
#line 41 "lexerspec.l"
/* PATTERN */           /* ACTION */
  while (true)
  {
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
              return int();
            }
            else
            {
              out().put(matcher().input());
            }
            break;
          case 1: // rule at line 41: (?:\<(?:if|elif|else|while|return|state|entry|exit|on|moveto|lambda|defevent)\>)
#line 41 "lexerspec.l"
tokens.push_back(Token(text()));
            break;
          case 2: // rule at line 42: (?:\<(?:\+|=|==|=<|=>|;|\{|\}|\(|\)|,|int|bool|string|true|false)\>)
#line 42 "lexerspec.l"
tokens.push_back(Token(text()));
            break;
          case 3: // rule at line 43: (?:\<(?:[A-Z_a-z][0-9A-Z_a-z]*|[0-9]+|"(?:[^"\x5c]|\\")*")\>)
#line 43 "lexerspec.l"
tokens.push_back(Token(text()));
            break;
          case 4: // rule at line 44: (?:\Q/*\E)(?:.|\n)*?(?:\Q*/\E)
#line 44 "lexerspec.l"
/* no action: ignore multiline comments */
            break;
          case 5: // rule at line 45: [\x09\x0a\x0d\x20]
#line 45 "lexerspec.l"
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

#line 48 "lexerspec.l"
int main(int argc, char **argv)
{
    FILE *fd = stdin;
    if (argc > 1 && (fd = fopen(argv[1], "r")) == NULL)
        exit(EXIT_FAILURE);
    std::ofstream of("output.txt", std::ofstream::out);
    if (!of)
        exit(EXIT_FAILURE);
    auto lexer = Lexer(fd, of);
    lexer.lex();
    of.close();
    if (fd != stdin)
        fclose(fd);

    lexer.printTokens();

    return 0;
}

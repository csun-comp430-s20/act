%top{
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
%}

%class{
    private:
    struct Token {
        private:
        std::string data;

        public:
        Token(std::string data) {
            this->data = data;
        }

        std::string get() {
            return this->data;
        }
    }

    public:
    std::vector<Token> tokens;  // lexer class member variable (private by default)

    void printTokens() {
        for (std::vector<Token>::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
            std::cout << *i << ' ';
    }
%}

keywords    (if|elif|else|while|return|state|entry|exit|on|moveto|lambda|defevent)
symbols     (\+|=|<|>|==|=<|=>|;|{|}|\(|\)|,|int|bool|string|true|false)
regexs      ([a-zA-Z_][a-zA-Z0-9_]*|[0-9]+|\"([^\\\"]|\\\")*\")

%%
/* PATTERN */           /* ACTION */
{keywords}              tokens.push_back(new Token(text()))
{symbols}               tokens.push_back(new Token(text()))
{regexs}                tokens.push_back(new Token(text()))
"/*"(.|\n)*?"*/"        /* no action: ignore multiline comments */
[ \t\r\n]               /* no action: ignore all white space */

/**
/* PATTERN */           /* ACTION */
"if"                    return IF_KEYWORD;
"elif"                  return ELIF_KEYWORD;
"else"                  return ELSE_KEYWORD;
"while"                 return WHILE_KEYWORD;
"return"                return RETURN_KEYWORD;
"state"                 return STATE_KEYWORD;
"entry"                 return ENTRY_KEYWORD;
"exit"                  return EXIT_KEYWORD;
"on"                    return ON_KEYWORD;
"moveto"                return MOVETO_KEYWORD;
"lambda"                return LAMBDA_KEYWORD;
"defevent"              return DEFEVENT_TOKEN;
"+"                     return PLUS_TOKEN;
"="                     return ASSING_TOKEN;
"<"                     return LESS_TOKEN;
">"                     return GREATER_TOKEN;
"=="                    return EQUAL_TOKEN;
"=<"                    return EQLESS_TOKEN;
"=>"                    return EQGREATER_TOKEN;
";"                     return SEMI_TOKEN;
"{"                     return RIGHT_BRACE_TOKEN;
"}"                     return LEFT_BRACE_TOKEN;
"("                     return RIGHT_PAREN_TOKEN;
")"                     return LEFT_PAREN_TOKEN;
","                     return COMMA_TOKEN;
"int"                   return INT_TYPE_TOKEN;
"bool"                  return BOOL_TYPE_TOKEN;
"string"                return STRING_TYPE_TOKEN;
"true"                  return TRUE_TOKEN;
"false"                 return FALSE_TOKEN;
[a-zA-Z_][a-zA-Z0-9_]*  return IDEN_TOKEN;
[0-9]+                  return INTEGER_TOKEN;
\"([^\\\"]|\\\")*\"     return STRING_TOKEN;
"/*"(.|\n)*?"*/"        /* no action: ignore multiline comments */
[ \t\r\n]               /* no action: ignore all white space */
*/

%%
int main(int argc, char **argv)
{
    FILE *fd = stdin;
    if (argc > 1 && (fd = fopen(argv[1], "r")) == NULL)
        exit(EXIT_FAILURE);
    std::ofstream of("output.txt", std::ofstream::out);
    if (!of)
        exit(EXIT_FAILURE);
    auto lexer = new Lexer(fd, of);
    lexer.lex()
    of.close();
    if (fd != stdin)
        fclose(fd);
    
    lexer.printTokens()

    return 0;
}
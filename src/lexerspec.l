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
        Token(const std::string data) {
            this->data = data;
        }

        const std::string get() {
            return this->data;
        }
    };

    public:
    std::vector<Token> tokens;  // lexer class member variable

    void printTokens() {
        for (std::vector<Token>::iterator i = tokens.begin(); i != tokens.end(); ++i)
            std::cout << (*i).get() << ' ';
    }
%}

keywords    \<(if|elif|else|while|return|state|entry|exit|on|moveto|lambda|defevent)\>
types       \<(int|bool|string|true|false)\>
regexs      \<([a-zA-Z_][a-zA-Z0-9_]*|[0-9]+|\"([^\\\"]|\\\")*\")\>

%%
/* PATTERN */           /* ACTION */
{keywords}              tokens.push_back(Token(str()));
"+"                     tokens.push_back(Token(str()));
";"                     tokens.push_back(Token(str()));
"{"                     tokens.push_back(Token(str()));
"}"                     tokens.push_back(Token(str()));
"("                     tokens.push_back(Token(str()));
")"                     tokens.push_back(Token(str()));
","                     tokens.push_back(Token(str()));
"=<"                    tokens.push_back(Token(str()));
"=>"                    tokens.push_back(Token(str()));
"=="                    tokens.push_back(Token(str()));
"="                     tokens.push_back(Token(str()));
{types}                 tokens.push_back(Token(str()));
{regexs}                tokens.push_back(Token(str()));
"/*"(.|\n)*?"*/"        /* no action: ignore multiline comments */
[ \t\r\n]               /* no action: ignore all white space */

%%
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
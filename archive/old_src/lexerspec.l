%top{
    #include "parser.hpp"  /* Generated by bison. */
    #include "location.hpp" /* Generated by bison %locations. */
%}

%option bison-complete
%option bison-cc-namespace=yy
%option bison-cc-parser=parser
%option bison-locations

%option exception="yy::parser::syntax_error(location(), \"Unknown token.\")"

%option namespace=yy
%option lexer=Lexer

//%x ERROR

%%

"print"                     return yy::parser::make_PRINT(str(), location());
"true"                      return yy::parser::make_TRUE(str() == "true", location());
"false"                     return yy::parser::make_FALSE(str() == "false", location());
"moveif"                    return yy::parser::make_MOVEIF(str(), location());
"if"                        return yy::parser::make_IF(str(), location());
"elif"                      return yy::parser::make_ELIF(str(), location());
"else"                      return yy::parser::make_ELSE(str(), location());
"while"                     return yy::parser::make_WHILE(str(), location());
"return"                    return yy::parser::make_RETURN(str(), location());
"state"                     return yy::parser::make_STATE(str(), location());
"entry"                     return yy::parser::make_ENTRY(str(), location());
"exit"                      return yy::parser::make_EXIT(str(), location());
"on"                        return yy::parser::make_ON(str(), location());
"break"                     return yy::parser::make_BREAK(str(), location());
"defevent"                  return yy::parser::make_DEFEVENT(str(), location());
"int"                       return yy::parser::make_INT(str(), location());
"bool"                      return yy::parser::make_BOOL(str(), location());
"string"                    return yy::parser::make_STRING(str(), location());
"/*"(.|\n)*?"*/"            /* no action: ignore all multi-line comments */;
[ \t\n\f\r]                 /* no action: ignore all white space */;
"+"                         return yy::parser::make_PLUS(str(), location());
";"                         return yy::parser::make_SEMI(str(), location());
"{"                         return yy::parser::make_LEFT_BRACE(str(), location());
"}"                         return yy::parser::make_RIGHT_BRACE(str(), location());
"("                         return yy::parser::make_LEFT_PAREN(str(), location());
")"                         return yy::parser::make_RIGHT_PAREN(str(), location());
","                         return yy::parser::make_COMMA(str(), location());
"<"                         return yy::parser::make_LESS(str(), location()); 
">"                         return yy::parser::make_GREATER(str(), location()); 
"=="                        return yy::parser::make_EQUAL(str(), location());
"="                         return yy::parser::make_ASSIGN(str(), location());
[0-9]+                      return yy::parser::make_INT_NUMBER(atoi(text()), location());
[a-zA-Z_][a-zA-Z0-9_]*      return yy::parser::make_IDENTIFIER(str(), location());
\"([^\\\"]|\\\")*\"         return yy::parser::make_STRING_VAL(str(), location());
<<EOF>>                     return yy::parser::make_EOF(location());
                            throw yy::parser::syntax_error(location(), "Unknown token.");

%%

/*
int main(int argc, char **argv)
{
    FILE *fd = stdin;
    if (argc > 1 && (fd = fopen(argv[1], "r")) == NULL)
        exit(EXIT_FAILURE);
    std::ofstream of("output.txt", std::ofstream::out);
    if (!of)
        exit(EXIT_FAILURE);
    yy::Lexer lexer(fd, of);
    yy::parser parser(lexer);
    if (parser.parse() != 0) {}
    of.close();
    if (fd != stdin)
        fclose(fd);
    return 0;
}
*/
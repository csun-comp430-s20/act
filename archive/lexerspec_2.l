%top{
    #include <iostream>
    #include <fstream>
    #include <string>
%}

%union {
    int num;
    std::string str;
    bool flag;
}

%token <str> IF_KEYWORD
%token <str> ELIF_KEYWORD
%token <str> ELSE_KEYWORD
%token <str> WHILE_KEYWORD
%token <str> RETURN_KEYWORD
%token <str> STATE_KEYWORD
%token <str> ENTRY_KEYWORD
%token <str> EXIT_KEYWORD
%token <str> ON_KEYWORD
%token <str> MOVETO_KEYWORD
%token <str> LAMBDA_KEYWORD
%token <str> DEFEVENT_KEYWORD
%token <str> INT_TYPE
%token <str> BOOL_TYPE
%token <str> STRING_TYPE
%token <num> NUM_VAL
%token <str> STRING_VAL
%token <flag> TRUE_VAL
%token <flag> FALSE_VAL
%token <str> PLUS_TOKEN
%token <str> SEMI_TOKEN
%token <str> RIGHT_BRACE_TOKEN
%token <str> LEFT_BRACE_TOKEN
%token <str> RIGHT_PAREN_TOKEN
%token <str> LEFT_PAREN_TOKEN
%token <str> COMMA_TOKEN
%token <str> LESS_EQUAL_TOKEN
%token <str> GREATER_EQUAL_TOKEN
%token <str> EQUAL_TOKEN
%token <str> ASSIGN_TOKEN
%token <str> IDEN_TOKEN

%%
/* PATTERN */           /* ACTION */
"if"                    return IF_KEYWORD
"elif"                  return ELIF_KEYWORD
"else"                  return ELSE_KEYWORD
"while"                 return WHILE_KEYWORD
"return"                return RETURN_KEYWORD
"state"                 return STATE_KEYWORD
"entry"                 return ENTRY_KEYWORD
"exit"                  return EXIT_KEYWORD
"on"                    return ON_KEYWORD
"moveto"                return MOVETO_KEYWORD
"lambda"                return LAMBDA_KEYWORD
"defevent"              return DEFEVENT_KEYWORD
"int"                   return INT_TYPE
"bool"                  return BOOL_TYPE
"string"                return STRING_TYPE
[0-9]+                  return NUM_VAL
\"([^\\\"]|\\\")*\"     return STRING_VAL
"true"                  return TRUE_VAL
"false"                 return FALSE_VAL
"+"                     return PLUS_TOKEN
";"                     return SEMI_TOKEN
"{"                     return RIGHT_BRACE_TOKEN
"}"                     return LEFT_BRACE_TOKEN
"("                     return RIGHT_PAREN_TOKEN
")"                     return LEFT_PAREN_TOKEN
","                     return COMMA_TOKEN
"=<"                    return LESS_EQUAL_TOKEN
"=>"                    return GREATER_EQUAL_TOKEN
"=="                    return EQUAL_TOKEN
"="                     return ASSIGN_TOKEN
[a-zA-Z_][a-zA-Z0-9_]*  return IDEN_TOKEN
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

    return 0;
}
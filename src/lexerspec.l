%%
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
"int"                   return INT_TYPE_TOKEN;
"bool"                  return BOOL_TYPE_TOKEN;
"string"                return STRING_TYPE_TOKEN;
[a-zA-Z_][a-zA-Z0-9_]*  return NAME_TOKEN;
[0-9]+                  return INTEGER_TOKEN;
\"([^\\\"]|\\\")*\"     return STRING_TOKEN;
"false"                 return FALSE_TOKEN;
"true"                  return TRUE_TOKEN;
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
    Lexer(fd, of).lex();
    of.close();
    if (fd != stdin)
        fclose(fd);
    return 0;
}
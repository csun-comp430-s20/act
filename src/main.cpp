#include <iostream>
#include "print.hpp"
#include "lexer.hpp"
#include "parse.hpp"

using namespace std;
using namespace act;

LexerResult lexify(String const& input) {
    cout << "input: " << input << "\n";

    if (LexerResult result = lex(input)) {
        cout << "The tokens are: ";
        for (Token const& t : result.value()) {
            cout << print_token(t);
        }

        cout << "\n\n";

        return result;
    }
    else {
        LexerError e = result.error();
        cout << "Lexer Error: " << e.what << " at " << e.where << "\n";
        return e;
    }
}

int main() {
    // String lex_input = " if +=()()><== \"Hello\" 4num";
    // String lex_input = "int num = (10 + 23) + 45;\n"
    //                     "string str = \"Hello\";";
    String lex_input = "int num = 5;\n" 
                        "string str = \"Hello\";\n"
                        "bool b = 23 < 45;";
    // String lex_input = "string str = \"Hello\";\n"
    //                     "bool b = 23 < 45;";
    // String lex_input = "string str = \"Hello\";\n"
    //                     "bool b = \"Hello\";\n"
    //                     "string t = 24;";
    
    // NOTE: Passes but should be an error
    // String lex_input = "bool b = 23 < 45 < 45;";

    if (LexerResult lex_result = lexify(lex_input)) {
        Input parse_input(lex_result.value());
        Parsed<Program> program = parse_program(parse_input);

        if(program) {
            cout << print_program(program.value());
        }
        else {
            cout << "parse error (" << parse_input.pos() << "): " << 
                program.error().what << "\n";
        }
    }
}

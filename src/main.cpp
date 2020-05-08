#include <iostream>
#include "print.hpp"
#include "lexer.hpp"
#include "parse.hpp"
#include "typechecker.hpp"
#include "codegen.hpp"

using namespace std;
using namespace act;

int main(int argc, char* argv[]) {
    string fileName;

    if(argc == 2)
    {
        //read in a file name from command line:
        fileName = argv[1];
    }
    else
    {
        cerr << "Usage: act SOURCEFILE" << endl;
        return 1;
    }

    ifstream file(fileName);
    stringstream buffer;
    string fileContents;

    if(file.is_open())
    {
        buffer << file.rdbuf();
        fileContents = buffer.str();
    }
    else
    {
        cerr << "Error: File not found!\n";
        return 1;
    }

    if (LexerResult lex_result = lexify(lex_input)) {
        Input parse_input(lex_result.value());
        Parsed<Program> program = parse_program(parse_input);

        if(program) {
            cout << print_program(program.value());
        }
        else {
            cout << "parse error (" << parse_input.pos() << "): " << 
                program.error().what << "\n";
            
            return 1
        }

        // TypeEnv typeEnv = type_check_program(program.value());

        // String output = gen_code(program.value(), typeEnv);
        // cout << output << endl;
    } else {
        return 1;
    }

    return 0;
}

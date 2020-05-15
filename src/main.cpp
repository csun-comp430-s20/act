#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "lexer.hpp"
#include "parse.hpp"
#include "typechecker.hpp"
#include "codegen.hpp"
#include "logger.hpp"
#include "config.hpp"

using namespace std;
using namespace act;

int main(int argc, char* argv[]) {

    String actFileName;
    String logFileName;
    String logLevel;
    
    if(argc == 4) {
        logLevel = argv[1];
        actFileName = String("../tests/") + argv[2];
        char cwd[2048];
        getcwd(cwd, sizeof(cwd));
        logFileName = cwd + String("/../logs/") + argv[3];   
    }
    else {
        cerr << "Number of args input incorrect" << endl;
        return 1;
    }

    config::logFileName = logFileName;
    config::logLevel = logLevel;
    setLogger(config::logFileName, config::logLevel);

    ifstream file(actFileName);
    stringstream buffer;
    String fileContents;

    if(file.is_open()) {
        buffer << file.rdbuf();
        fileContents = buffer.str();
    }
    else {
        cerr << "Error: File not found!\n";
        return 1;
    }

    if (LexerResult lex_result = lexify(fileContents)) {
        Input parse_input(lex_result.value());
        Parsed<Program> program = parse_program(parse_input);

        if(program) {
            // L_(ldebug) << print_program(program.value());
            TypeEnv typeEnv = type_check_program(program.value());
            L_(ldebug) << gen_code(typeEnv, program.value());
        } else {
            L_(ldebug) << "parse error (" << program.error().what << ") " << "\n";
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}

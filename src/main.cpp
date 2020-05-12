#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "print.hpp"
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
        //read in a file name from command line:
        actFileName = String("../tests/") + argv[1];
        char cwd[2048];
        getcwd(cwd, sizeof(cwd));
        logFileName = cwd + String("/../logs/") + argv[2];
        logLevel = argv[3];
    }
    else {
        cerr << "Number of args input incorrect" << endl;
        return 1;
    }

    std::ofstream logFile (logFileName); // Create log file
    config::logFileName = logFileName;
    config::logLevel = logLevel;
    setLogger(logFileName, logLevel);

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
            // cout << print_program(program.value());
            L_(ldebug) << print_program(program.value());
        }
        else {
            // cout << "parse error (" << parse_input.pos() << "): " << 
            //     program.error().what << "\n";
            L_(lerror) << "parse error (" << parse_input.pos() << "): " <<
                program.error().what << "\n";
            
            return 1;
        }

        // TypeEnv typeEnv = type_check_program(program.value());

        // String output = gen_code(program.value(), typeEnv);
        // cout << output << endl;
    } else {
        return 1;
    }

    return 0;
}

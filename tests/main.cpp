//"Main" for the Catch unit test library

#define CATCH_CONFIG_RUNNER // Allow us to define our own main
#include "catch2/catch.hpp"
#include "config.hpp"

#include <fstream>
#include <unistd.h>

//All tests are done in external .cpp files

int main(int argc, char** argv)
{
    using namespace Catch::clara;
    using namespace act;
    Catch::Session session;

    // Modify the included Catch CLI parser
    auto cli = session.cli()
        | Opt([&](bool) { config::logLevel = "error";
                          char cwd[2048];
                          getcwd(cwd, sizeof(cwd));
                          config::logFileName = cwd + String("/../logs/logtest_error.txt"); 
                          std::ofstream logFile (config::logFileName); })
          ["--error"]
          ("print error output")
        
        | Opt([&](bool) { config::logLevel = "debug";
                          char cwd[2048];
                          getcwd(cwd, sizeof(cwd));
                          config::logFileName = cwd + String("/../logs/logtest_debug.txt");
                          std::ofstream logFile (config::logFileName); })
          ["--debug"]
          ("print debug output")
        
        | Opt([&](bool) { config::logLevel = "info";
                          char cwd[2048];
                          getcwd(cwd, sizeof(cwd));
                          config::logFileName = cwd + String("/../logs/logtest_info.txt");
                          std::ofstream logFile (config::logFileName); })
          ["--info"]
          ("print info output");

    session.cli(cli); // Use the new CLI parser.
    auto rc = session.applyCommandLine(argc, argv); // Parse the CLI.

    if (rc != 0)
    {
        return rc; // Exit with error.
    }

    return session.run();
}

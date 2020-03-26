/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestSuiteArgs_init = false;
#include "/home/dan/Projects/Compilers/act/src/TestSuiteArgs.hpp"

static TestSuiteArgs suite_TestSuiteArgs;

static CxxTest::List Tests_TestSuiteArgs = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestSuiteArgs( "TestSuiteArgs.hpp", 3, "TestSuiteArgs", suite_TestSuiteArgs, Tests_TestSuiteArgs );

static class TestDescription_suite_TestSuiteArgs_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSuiteArgs_testAddition() : CxxTest::RealTestDescription( Tests_TestSuiteArgs, suiteDescription_TestSuiteArgs, 4, "testAddition" ) {}
 void runTest() { suite_TestSuiteArgs.testAddition(); }
} testDescription_suite_TestSuiteArgs_testAddition;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

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
bool suite_ActTestSuite_init = false;
#include "/home/dan/Projects/Compilers/act/src/ActTestSuite.hpp"

static ActTestSuite suite_ActTestSuite;

static CxxTest::List Tests_ActTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ActTestSuite( "ActTestSuite.hpp", 9, "ActTestSuite", suite_ActTestSuite, Tests_ActTestSuite );

static class TestDescription_suite_ActTestSuite_testEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testEmpty() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 12, "testEmpty" ) {}
 void runTest() { suite_ActTestSuite.testEmpty(); }
} testDescription_suite_ActTestSuite_testEmpty;

static class TestDescription_suite_ActTestSuite_testEventDef : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testEventDef() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 20, "testEventDef" ) {}
 void runTest() { suite_ActTestSuite.testEventDef(); }
} testDescription_suite_ActTestSuite_testEventDef;

static class TestDescription_suite_ActTestSuite_testEventDefMultiLine : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testEventDefMultiLine() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 28, "testEventDefMultiLine" ) {}
 void runTest() { suite_ActTestSuite.testEventDefMultiLine(); }
} testDescription_suite_ActTestSuite_testEventDefMultiLine;

static class TestDescription_suite_ActTestSuite_testDecStmtAdd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testDecStmtAdd() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 37, "testDecStmtAdd" ) {}
 void runTest() { suite_ActTestSuite.testDecStmtAdd(); }
} testDescription_suite_ActTestSuite_testDecStmtAdd;

static class TestDescription_suite_ActTestSuite_testDecStmtAddMulti : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testDecStmtAddMulti() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 45, "testDecStmtAddMulti" ) {}
 void runTest() { suite_ActTestSuite.testDecStmtAddMulti(); }
} testDescription_suite_ActTestSuite_testDecStmtAddMulti;

static class TestDescription_suite_ActTestSuite_testDecStmtAddMultiLine : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testDecStmtAddMultiLine() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 53, "testDecStmtAddMultiLine" ) {}
 void runTest() { suite_ActTestSuite.testDecStmtAddMultiLine(); }
} testDescription_suite_ActTestSuite_testDecStmtAddMultiLine;

static class TestDescription_suite_ActTestSuite_testDecStmtLogicBase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testDecStmtLogicBase() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 62, "testDecStmtLogicBase" ) {}
 void runTest() { suite_ActTestSuite.testDecStmtLogicBase(); }
} testDescription_suite_ActTestSuite_testDecStmtLogicBase;

static class TestDescription_suite_ActTestSuite_testDecStmtLogicValues : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testDecStmtLogicValues() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 70, "testDecStmtLogicValues" ) {}
 void runTest() { suite_ActTestSuite.testDecStmtLogicValues(); }
} testDescription_suite_ActTestSuite_testDecStmtLogicValues;

static class TestDescription_suite_ActTestSuite_testDecStmtLogicAndOr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testDecStmtLogicAndOr() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 78, "testDecStmtLogicAndOr" ) {}
 void runTest() { suite_ActTestSuite.testDecStmtLogicAndOr(); }
} testDescription_suite_ActTestSuite_testDecStmtLogicAndOr;

static class TestDescription_suite_ActTestSuite_testDecStmtLogicParens : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testDecStmtLogicParens() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 86, "testDecStmtLogicParens" ) {}
 void runTest() { suite_ActTestSuite.testDecStmtLogicParens(); }
} testDescription_suite_ActTestSuite_testDecStmtLogicParens;

static class TestDescription_suite_ActTestSuite_testAssignStmtLogic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testAssignStmtLogic() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 94, "testAssignStmtLogic" ) {}
 void runTest() { suite_ActTestSuite.testAssignStmtLogic(); }
} testDescription_suite_ActTestSuite_testAssignStmtLogic;

static class TestDescription_suite_ActTestSuite_testAssignStmtAdd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testAssignStmtAdd() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 102, "testAssignStmtAdd" ) {}
 void runTest() { suite_ActTestSuite.testAssignStmtAdd(); }
} testDescription_suite_ActTestSuite_testAssignStmtAdd;

static class TestDescription_suite_ActTestSuite_testIfStmtEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testIfStmtEmpty() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 110, "testIfStmtEmpty" ) {}
 void runTest() { suite_ActTestSuite.testIfStmtEmpty(); }
} testDescription_suite_ActTestSuite_testIfStmtEmpty;

static class TestDescription_suite_ActTestSuite_testIfStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testIfStmt() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 118, "testIfStmt" ) {}
 void runTest() { suite_ActTestSuite.testIfStmt(); }
} testDescription_suite_ActTestSuite_testIfStmt;

static class TestDescription_suite_ActTestSuite_testWhileStmtEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testWhileStmtEmpty() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 127, "testWhileStmtEmpty" ) {}
 void runTest() { suite_ActTestSuite.testWhileStmtEmpty(); }
} testDescription_suite_ActTestSuite_testWhileStmtEmpty;

static class TestDescription_suite_ActTestSuite_testWhileStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testWhileStmt() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 135, "testWhileStmt" ) {}
 void runTest() { suite_ActTestSuite.testWhileStmt(); }
} testDescription_suite_ActTestSuite_testWhileStmt;

static class TestDescription_suite_ActTestSuite_testOnBlock : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ActTestSuite_testOnBlock() : CxxTest::RealTestDescription( Tests_ActTestSuite, suiteDescription_ActTestSuite, 144, "testOnBlock" ) {}
 void runTest() { suite_ActTestSuite.testOnBlock(); }
} testDescription_suite_ActTestSuite_testOnBlock;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

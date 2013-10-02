/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    status = CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "test_must_follow_a.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_must_follow_a.cpp", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_a_is_second_to_last : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_a_is_second_to_last() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 17, "test_a_is_second_to_last" ) {}
 void runTest() { suite_MyTestSuite.test_a_is_second_to_last(); }
} testDescription_suite_MyTestSuite_test_a_is_second_to_last;

static class TestDescription_suite_MyTestSuite_test_a_is_followed_by_two_b : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_a_is_followed_by_two_b() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 24, "test_a_is_followed_by_two_b" ) {}
 void runTest() { suite_MyTestSuite.test_a_is_followed_by_two_b(); }
} testDescription_suite_MyTestSuite_test_a_is_followed_by_two_b;

static class TestDescription_suite_MyTestSuite_test_should_failed : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_should_failed() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 30, "test_should_failed" ) {}
 void runTest() { suite_MyTestSuite.test_should_failed(); }
} testDescription_suite_MyTestSuite_test_should_failed;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

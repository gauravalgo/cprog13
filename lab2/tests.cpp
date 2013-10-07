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
    status = CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "test_date.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_date.cpp", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_default_constructor_date_now : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_default_constructor_date_now() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 9, "test_default_constructor_date_now" ) {}
 void runTest() { suite_MyTestSuite.test_default_constructor_date_now(); }
} testDescription_suite_MyTestSuite_test_default_constructor_date_now;

static class TestDescription_suite_MyTestSuite_test_plusplus_prefix : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_plusplus_prefix() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "test_plusplus_prefix" ) {}
 void runTest() { suite_MyTestSuite.test_plusplus_prefix(); }
} testDescription_suite_MyTestSuite_test_plusplus_prefix;

static class TestDescription_suite_MyTestSuite_test_plusplus_prefix_month_shift : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_plusplus_prefix_month_shift() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 34, "test_plusplus_prefix_month_shift" ) {}
 void runTest() { suite_MyTestSuite.test_plusplus_prefix_month_shift(); }
} testDescription_suite_MyTestSuite_test_plusplus_prefix_month_shift;

static class TestDescription_suite_MyTestSuite_test_minnusminus_prefix : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_minnusminus_prefix() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 42, "test_minnusminus_prefix" ) {}
 void runTest() { suite_MyTestSuite.test_minnusminus_prefix(); }
} testDescription_suite_MyTestSuite_test_minnusminus_prefix;

static class TestDescription_suite_MyTestSuite_test_minusminus_prefix_month_shift : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_minusminus_prefix_month_shift() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 49, "test_minusminus_prefix_month_shift" ) {}
 void runTest() { suite_MyTestSuite.test_minusminus_prefix_month_shift(); }
} testDescription_suite_MyTestSuite_test_minusminus_prefix_month_shift;

static class TestDescription_suite_MyTestSuite_test_minus_equlas : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_minus_equlas() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "test_minus_equlas" ) {}
 void runTest() { suite_MyTestSuite.test_minus_equlas(); }
} testDescription_suite_MyTestSuite_test_minus_equlas;

static class TestDescription_suite_MyTestSuite_test_add_equals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_add_equals() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 67, "test_add_equals" ) {}
 void runTest() { suite_MyTestSuite.test_add_equals(); }
} testDescription_suite_MyTestSuite_test_add_equals;

static class TestDescription_suite_MyTestSuite_test_add_equals_negative_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_add_equals_negative_value() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 78, "test_add_equals_negative_value" ) {}
 void runTest() { suite_MyTestSuite.test_add_equals_negative_value(); }
} testDescription_suite_MyTestSuite_test_add_equals_negative_value;

static class TestDescription_suite_MyTestSuite_test_subtract_equals_negative_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_subtract_equals_negative_value() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 84, "test_subtract_equals_negative_value" ) {}
 void runTest() { suite_MyTestSuite.test_subtract_equals_negative_value(); }
} testDescription_suite_MyTestSuite_test_subtract_equals_negative_value;

static class TestDescription_suite_MyTestSuite_test_add_year : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_add_year() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 91, "test_add_year" ) {}
 void runTest() { suite_MyTestSuite.test_add_year(); }
} testDescription_suite_MyTestSuite_test_add_year;

static class TestDescription_suite_MyTestSuite_test_add_year_w_n : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_add_year_w_n() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 97, "test_add_year_w_n" ) {}
 void runTest() { suite_MyTestSuite.test_add_year_w_n(); }
} testDescription_suite_MyTestSuite_test_add_year_w_n;

static class TestDescription_suite_MyTestSuite_test_subtract_year : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_subtract_year() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 103, "test_subtract_year" ) {}
 void runTest() { suite_MyTestSuite.test_subtract_year(); }
} testDescription_suite_MyTestSuite_test_subtract_year;

static class TestDescription_suite_MyTestSuite_test_add_month : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_add_month() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 109, "test_add_month" ) {}
 void runTest() { suite_MyTestSuite.test_add_month(); }
} testDescription_suite_MyTestSuite_test_add_month;

static class TestDescription_suite_MyTestSuite_test_add_month_n_negative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_add_month_n_negative() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 115, "test_add_month_n_negative" ) {}
 void runTest() { suite_MyTestSuite.test_add_month_n_negative(); }
} testDescription_suite_MyTestSuite_test_add_month_n_negative;

static class TestDescription_suite_MyTestSuite_test_equalsequals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_equalsequals() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 122, "test_equalsequals" ) {}
 void runTest() { suite_MyTestSuite.test_equalsequals(); }
} testDescription_suite_MyTestSuite_test_equalsequals;

static class TestDescription_suite_MyTestSuite_test_not_equals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_not_equals() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 135, "test_not_equals" ) {}
 void runTest() { suite_MyTestSuite.test_not_equals(); }
} testDescription_suite_MyTestSuite_test_not_equals;

static class TestDescription_suite_MyTestSuite_test_greater_then : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_greater_then() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 144, "test_greater_then" ) {}
 void runTest() { suite_MyTestSuite.test_greater_then(); }
} testDescription_suite_MyTestSuite_test_greater_then;

static class TestDescription_suite_MyTestSuite_test_diff_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_diff_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 157, "test_diff_operator" ) {}
 void runTest() { suite_MyTestSuite.test_diff_operator(); }
} testDescription_suite_MyTestSuite_test_diff_operator;

static class TestDescription_suite_MyTestSuite_test_print_outs : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_print_outs() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 170, "test_print_outs" ) {}
 void runTest() { suite_MyTestSuite.test_print_outs(); }
} testDescription_suite_MyTestSuite_test_print_outs;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

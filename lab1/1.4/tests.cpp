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
#include "test_vector.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_vector.cpp", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_initialize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_initialize() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test_initialize" ) {}
 void runTest() { suite_MyTestSuite.test_initialize(); }
} testDescription_suite_MyTestSuite_test_initialize;

static class TestDescription_suite_MyTestSuite_test_initialize_zero_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_initialize_zero_vector() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "test_initialize_zero_vector" ) {}
 void runTest() { suite_MyTestSuite.test_initialize_zero_vector(); }
} testDescription_suite_MyTestSuite_test_initialize_zero_vector;

static class TestDescription_suite_MyTestSuite_test_all_values_are_init_to_zero_with_get : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_all_values_are_init_to_zero_with_get() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 24, "test_all_values_are_init_to_zero_with_get" ) {}
 void runTest() { suite_MyTestSuite.test_all_values_are_init_to_zero_with_get(); }
} testDescription_suite_MyTestSuite_test_all_values_are_init_to_zero_with_get;

static class TestDescription_suite_MyTestSuite_test_get_values_are_init_to_zero_with_index_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_get_values_are_init_to_zero_with_index_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 32, "test_get_values_are_init_to_zero_with_index_operator" ) {}
 void runTest() { suite_MyTestSuite.test_get_values_are_init_to_zero_with_index_operator(); }
} testDescription_suite_MyTestSuite_test_get_values_are_init_to_zero_with_index_operator;

static class TestDescription_suite_MyTestSuite_test_get_values_not_zero_with_index_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_get_values_not_zero_with_index_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 40, "test_get_values_not_zero_with_index_operator" ) {}
 void runTest() { suite_MyTestSuite.test_get_values_not_zero_with_index_operator(); }
} testDescription_suite_MyTestSuite_test_get_values_not_zero_with_index_operator;

static class TestDescription_suite_MyTestSuite_test_index_operator_throws_out_of_bounds : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_index_operator_throws_out_of_bounds() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 46, "test_index_operator_throws_out_of_bounds" ) {}
 void runTest() { suite_MyTestSuite.test_index_operator_throws_out_of_bounds(); }
} testDescription_suite_MyTestSuite_test_index_operator_throws_out_of_bounds;

static class TestDescription_suite_MyTestSuite_test_set_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_set_value() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 51, "test_set_value" ) {}
 void runTest() { suite_MyTestSuite.test_set_value(); }
} testDescription_suite_MyTestSuite_test_set_value;

static class TestDescription_suite_MyTestSuite_test_get_value_out_of_bounds_throws_exception : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_get_value_out_of_bounds_throws_exception() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 65, "test_get_value_out_of_bounds_throws_exception" ) {}
 void runTest() { suite_MyTestSuite.test_get_value_out_of_bounds_throws_exception(); }
} testDescription_suite_MyTestSuite_test_get_value_out_of_bounds_throws_exception;

static class TestDescription_suite_MyTestSuite_test_set_value_out_of_bounds_throws_exception : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_set_value_out_of_bounds_throws_exception() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 70, "test_set_value_out_of_bounds_throws_exception" ) {}
 void runTest() { suite_MyTestSuite.test_set_value_out_of_bounds_throws_exception(); }
} testDescription_suite_MyTestSuite_test_set_value_out_of_bounds_throws_exception;

static class TestDescription_suite_MyTestSuite_test_copy_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_copy_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 75, "test_copy_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_copy_constructor(); }
} testDescription_suite_MyTestSuite_test_copy_constructor;

static class TestDescription_suite_MyTestSuite_test_vector_assignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_vector_assignment() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 83, "test_vector_assignment" ) {}
 void runTest() { suite_MyTestSuite.test_vector_assignment(); }
} testDescription_suite_MyTestSuite_test_vector_assignment;

static class TestDescription_suite_MyTestSuite_test_vector_assignment_values : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_vector_assignment_values() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 88, "test_vector_assignment_values" ) {}
 void runTest() { suite_MyTestSuite.test_vector_assignment_values(); }
} testDescription_suite_MyTestSuite_test_vector_assignment_values;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

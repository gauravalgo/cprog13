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
#include "test_template_vector.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_template_vector.cpp", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_initialize_with_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_initialize_with_size() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 9, "test_initialize_with_size" ) {}
 void runTest() { suite_MyTestSuite.test_initialize_with_size(); }
} testDescription_suite_MyTestSuite_test_initialize_with_size;

static class TestDescription_suite_MyTestSuite_test_initialize_zero_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_initialize_zero_vector() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "test_initialize_zero_vector" ) {}
 void runTest() { suite_MyTestSuite.test_initialize_zero_vector(); }
} testDescription_suite_MyTestSuite_test_initialize_zero_vector;

static class TestDescription_suite_MyTestSuite_test_all_values_are_init_to_zero_with_get : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_all_values_are_init_to_zero_with_get() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 23, "test_all_values_are_init_to_zero_with_get" ) {}
 void runTest() { suite_MyTestSuite.test_all_values_are_init_to_zero_with_get(); }
} testDescription_suite_MyTestSuite_test_all_values_are_init_to_zero_with_get;

static class TestDescription_suite_MyTestSuite_test_get_values_are_init_to_zero_with_index_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_get_values_are_init_to_zero_with_index_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 31, "test_get_values_are_init_to_zero_with_index_operator" ) {}
 void runTest() { suite_MyTestSuite.test_get_values_are_init_to_zero_with_index_operator(); }
} testDescription_suite_MyTestSuite_test_get_values_are_init_to_zero_with_index_operator;

static class TestDescription_suite_MyTestSuite_test_get_values_not_zero_with_index_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_get_values_not_zero_with_index_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 39, "test_get_values_not_zero_with_index_operator" ) {}
 void runTest() { suite_MyTestSuite.test_get_values_not_zero_with_index_operator(); }
} testDescription_suite_MyTestSuite_test_get_values_not_zero_with_index_operator;

static class TestDescription_suite_MyTestSuite_test_index_operator_throws_out_of_bounds : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_index_operator_throws_out_of_bounds() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 45, "test_index_operator_throws_out_of_bounds" ) {}
 void runTest() { suite_MyTestSuite.test_index_operator_throws_out_of_bounds(); }
} testDescription_suite_MyTestSuite_test_index_operator_throws_out_of_bounds;

static class TestDescription_suite_MyTestSuite_test_insert_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert_value() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 52, "test_insert_value" ) {}
 void runTest() { suite_MyTestSuite.test_insert_value(); }
} testDescription_suite_MyTestSuite_test_insert_value;

static class TestDescription_suite_MyTestSuite_test_set_default_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_set_default_value() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "test_set_default_value" ) {}
 void runTest() { suite_MyTestSuite.test_set_default_value(); }
} testDescription_suite_MyTestSuite_test_set_default_value;

static class TestDescription_suite_MyTestSuite_test_insert_value_out_of_bounds_throws_exception : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert_value_out_of_bounds_throws_exception() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 67, "test_insert_value_out_of_bounds_throws_exception" ) {}
 void runTest() { suite_MyTestSuite.test_insert_value_out_of_bounds_throws_exception(); }
} testDescription_suite_MyTestSuite_test_insert_value_out_of_bounds_throws_exception;

static class TestDescription_suite_MyTestSuite_test_push_back_via_insert : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_push_back_via_insert() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 71, "test_push_back_via_insert" ) {}
 void runTest() { suite_MyTestSuite.test_push_back_via_insert(); }
} testDescription_suite_MyTestSuite_test_push_back_via_insert;

static class TestDescription_suite_MyTestSuite_test_copy_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_copy_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 77, "test_copy_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_copy_constructor(); }
} testDescription_suite_MyTestSuite_test_copy_constructor;

static class TestDescription_suite_MyTestSuite_test_sort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_sort() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 87, "test_sort" ) {}
 void runTest() { suite_MyTestSuite.test_sort(); }
} testDescription_suite_MyTestSuite_test_sort;

static class TestDescription_suite_MyTestSuite_test_sort_unique : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_sort_unique() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 104, "test_sort_unique" ) {}
 void runTest() { suite_MyTestSuite.test_sort_unique(); }
} testDescription_suite_MyTestSuite_test_sort_unique;

static class TestDescription_suite_MyTestSuite_test_sort_unique_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_sort_unique_2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 113, "test_sort_unique_2" ) {}
 void runTest() { suite_MyTestSuite.test_sort_unique_2(); }
} testDescription_suite_MyTestSuite_test_sort_unique_2;

static class TestDescription_suite_MyTestSuite_test_exists : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_exists() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 128, "test_exists" ) {}
 void runTest() { suite_MyTestSuite.test_exists(); }
} testDescription_suite_MyTestSuite_test_exists;

static class TestDescription_suite_MyTestSuite_test_push_back : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_push_back() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 136, "test_push_back" ) {}
 void runTest() { suite_MyTestSuite.test_push_back(); }
} testDescription_suite_MyTestSuite_test_push_back;

static class TestDescription_suite_MyTestSuite_test_clear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_clear() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 160, "test_clear" ) {}
 void runTest() { suite_MyTestSuite.test_clear(); }
} testDescription_suite_MyTestSuite_test_clear;

static class TestDescription_suite_MyTestSuite_test_insert : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 174, "test_insert" ) {}
 void runTest() { suite_MyTestSuite.test_insert(); }
} testDescription_suite_MyTestSuite_test_insert;

static class TestDescription_suite_MyTestSuite_test_assignment_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_assignment_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 186, "test_assignment_operator" ) {}
 void runTest() { suite_MyTestSuite.test_assignment_operator(); }
} testDescription_suite_MyTestSuite_test_assignment_operator;

static class TestDescription_suite_MyTestSuite_test_alloc_more : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_alloc_more() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 194, "test_alloc_more" ) {}
 void runTest() { suite_MyTestSuite.test_alloc_more(); }
} testDescription_suite_MyTestSuite_test_alloc_more;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

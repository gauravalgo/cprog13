#include <cxxtest/TestSuite.h>
#include "Vector14.h"
#include "Vector14.cpp"

class MyTestSuite : public CxxTest::TestSuite
{
public:

  void test_initialize( void  )
  {
    Vector v(5);
    int result = v.get_size();
    TS_ASSERT_EQUALS( result, 5 );
  }

  void test_initialize_zero_vector( void ) {
    Vector v(0);
    int result = v.get_size();
    TS_ASSERT_EQUALS( result, 0 );
    TS_ASSERT_THROWS_ANYTHING( v.get(-1) );
  }

  void test_get_element( void ) {
    Vector v(5);
    int result = v.get_size();
    int firstElement = v.get(1);
    TS_ASSERT_EQUALS( result, 5 );
    TS_ASSERT_EQUALS( firstElement, 0);
    //TS_ASSERT_THROWS_ANYTHING( v.get(-1) );
    //TS_ASSERT_THROWS_ANYTHING( v.get(1) );
    //TS_ASSERT_THROWS_ANYTHING( v.get(0) );
  }
  void test_get_operator_overloaded( void ) {
    Vector v(5);
    int firstElement = v[0];
    v[1] = 5;
    TS_ASSERT_EQUALS( firstElement, 0);
    TS_ASSERT_EQUALS( v[1], 5);
  }
    void test_assignment_operator_overloaded( void ) {
    Vector v(5);
    auto list = { 10, 20, 30, 40, 50 };  
    v = list;
    unsigned int result = v[1];
    TS_ASSERT_EQUALS( result, 20 );
  }
  void test_move(void){
    Vector v(5);
    auto list = { 10, 20, 30, 40, 50 };  
    v = list;
    TS_ASSERT_EQUALS(v.get_size(), 5);
    Vector a = std::move(v);
    TS_ASSERT_EQUALS(a.get_size(), 5);
    TS_ASSERT_EQUALS(v.get_size(),0);
  }

};

/*#include <cxxtest/TestSuite.h>
#include "Vector.h"
#include "Vector.cpp"

class MyTestSuite : public CxxTest::TestSuite
{
public:

  void test_initialize_with_size( void  )
  {
    Vector<int> v = Vector<int>(5);
    TS_ASSERT_EQUALS( v.size(), 5 );
  }

  void test_initialize_zero_vector( void ) {
    Vector<int> v(0);
    TS_ASSERT_EQUALS( v.size(), 0 );
    TS_ASSERT_THROWS_ANYTHING( v.get(-1) );
    TS_ASSERT_THROWS_ANYTHING( v.get(1) );
    TS_ASSERT_THROWS_ANYTHING( v.get(0) );
  }

  void test_all_values_are_init_to_zero_with_get( void  ) {
    int size = 5;
    Vector<int> v(size);
    for (int i = 0; i < size; i++) {
      TS_ASSERT_EQUALS( v.get(i), 0 );
    }
  }

  void test_get_values_are_init_to_zero_with_index_operator( void ) {
    int size = 6;
    Vector<int> v(6);
    for (int i = 0; i < size; i++) {
      TS_ASSERT_EQUALS( v[i], 0 );
    }
  }

  void test_get_values_not_zero_with_index_operator( void ) {
    Vector<int> v(6);
    v.insert(1,5);
    TS_ASSERT_EQUALS( v[1], 5 );
  }

   void test_index_operator_throws_out_of_bounds( void ) {
     Vector<int> v(7);
     TS_ASSERT_THROWS_ANYTHING( v.get(7) );
     TS_ASSERT_THROWS_ANYTHING( v[8] );
     TS_ASSERT_THROWS_ANYTHING( v[-1] );
   }

  void test_insert_value( void  ) {
    Vector<int> v(1);
    v.insert(0,2);
    TS_ASSERT_EQUALS( v.get(0),2 );
  }

  void test_set_default_value(void){
    int defVal = 4;
    Vector<int> v(5,defVal);
    for (int i = 0; i < 5; ++i)
    {
      TS_ASSERT_EQUALS(v[i], 4);
    }
  }

  void test_insert_value_out_of_bounds_throws_exception( void ) {
    Vector<int> v(10);
    TS_ASSERT_THROWS_ANYTHING( v.insert(11, 10 ) );
  }
    void test_push_back_via_insert( void ) {
    Vector<int> v(10);
    v.insert(10, 10 );
    TS_ASSERT_EQUALS( v[10], 10);
  }

  void test_copy_constructor( void ) {
    Vector<int> v(5);
    Vector<int> v2 = v;
    v2.insert(3,10);
    TS_ASSERT_EQUALS( v2.size(), 6);
    TS_ASSERT_EQUALS( v2.get(3), 10 );
    TS_ASSERT_EQUALS( v.size(), 5 );
    TS_ASSERT_EQUALS( v.get(3), 0 );
  }

  void test_sort(void){
    Vector<int> v(4,3);
    v[2] = 1; //will look like {3,3,1,3}
    size_t beforeSize = v.size();
    v.sort(true);
    size_t afterSize = v.size();
    TS_ASSERT_EQUALS(beforeSize, afterSize);
    TS_ASSERT_EQUALS(v[0], 1);
    v.sort(false);
    TS_ASSERT_EQUALS(v[3], 1);
    TS_ASSERT_EQUALS(v[1], 3);
    Vector<int> a(1, 2);
    int beforeSort = a[0];
    a.sort(true);
    TS_ASSERT_EQUALS(beforeSort, a[0]);
  }

  void test_sort_unique( void ) {
    Vector<int> v(10, 5);
    v[3] = 4;
    v[7] = 4;
    v.unique_sort(true);
    TS_ASSERT_EQUALS(v.size(), 2);
  
  }

  void test_exists(void){
    Vector<int> v(2);
    v[0] = 2;
    v[1] = 1;
    TS_ASSERT_EQUALS(v.exists(1),true);
    TS_ASSERT_EQUALS(v.exists(4), false);
  }

  void test_push_back(void){
    Vector<int> v(2);
    v[0] = 2;
    v[1] = 1;
    v.push_back(3);
    TS_ASSERT_EQUALS(v[2], 3);
    v.push_back(5);
    TS_ASSERT_EQUALS(v[3], 5);
    //v.print();
    Vector<int> a(0);
    a.push_back(1);
    TS_ASSERT_EQUALS(a[0], 1);
    TS_ASSERT_THROWS_ANYTHING(a[1]);
    //a.print();
    Vector<int> b(0);
    for (int i = 0; i < 13; ++i)
    {
      b.push_back(10);
    }
    TS_ASSERT_EQUALS(b[0], 10);
    TS_ASSERT_EQUALS(b[12], 10);
    //b.print();
    }

  void test_clear(void){
    Vector<int> v(10, 2);
    v.clear();
    TS_ASSERT_EQUALS(v.size(),0);
    TS_ASSERT_EQUALS(v.bufSize, 40);
    TS_ASSERT_THROWS_ANYTHING(v[0]);
    v.push_back(1);
    TS_ASSERT_EQUALS(v[0], 1);
    Vector<int> a;
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.bufSize, 10);
  }

  void test_insert(void){
    Vector<int> v(10,2);
    v.insert(7,10);
    //v.print();
    v.insert(1,1);
    v.insert(2,3);
    //v.print();
    TS_ASSERT_EQUALS(v[1],1);
    TS_ASSERT_EQUALS(v[2],3);
    TS_ASSERT_EQUALS(v[9],10);
    TS_ASSERT_EQUALS(v[12],2);
  }
    void test_assignment_operator( void ) {
    Vector<int> v(5);
    auto list = { 10, 20, 30, 40, 50 };  
    v = list;
    int result = v[1];
    TS_ASSERT_EQUALS( result, 20 );
  }

  void test_alloc_more(void){
    Vector<int> v;
    v.alloc_more();
    TS_ASSERT_EQUALS(2, v.bufSize);
  }
};*/
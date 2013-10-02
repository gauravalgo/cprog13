#include <cxxtest/TestSuite.h>
#include "vector.h"

class MyTestSuite : public CxxTest::TestSuite
{
public:

  void test_initialize( void  )
  {
    Vector<int> v = Vector<int>(5);
    int result = v.size();
    TS_ASSERT_EQUALS( result, 5 );
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

  // void test_index_operator_throws_out_of_bounds( void ) {
  //   std::cout << "create vecotr of lenght 7" << std::endl;
  //   Vector<int> v(7);
  //   std::cout << "done!" << std::endl;
  //   TS_ASSERT_THROWS_ANYTHING( v.get(7) );
  //   std::cout << "hej" << std::endl;
  //   TS_ASSERT_THROWS_ANYTHING( v[8] );
  //   std::cout << "throwed exception" << std::endl;
  // }

  void test_set_value( void  ) {
    // std::cout << "bug printf" << std::endl;
    Vector<int> v(1);
    v.insert(0,2);
    TS_ASSERT_EQUALS( v.get(0),2 );
  }

  void get_custom_value_with_index_operator( void ) {
    Vector<int> v(10);
    v.insert(5,7);
    for (int i = 0; i < 10; i++) {
      TS_ASSERT_EQUALS( v.get(0), 0 )
    }
  }

  void test_get_value_out_of_bounds_throws_exception( void ) {
    Vector<int> v(10);
    TS_ASSERT_THROWS_ANYTHING( v.get(10) );
  }

  void test_set_value_out_of_bounds_throws_exception( void ) {
    Vector<int> v(10);
    TS_ASSERT_THROWS_ANYTHING( v.insert(10, 10 ) );
  }

  void test_copy_constructor( void ) {
    Vector<int> v(5);
    Vector<int> v2 = v;
    v2.insert(3,10);
    TS_ASSERT_EQUALS( v2.size(), 6);
    TS_ASSERT_EQUALS( v2.get(3), 10 );
    TS_ASSERT_EQUALS( v.size(), 5 );
    TS_ASSERT_EQUALS( v.get(3), 10 );

  }

  void test_sort_unique( void ) {
    Vector<int> v(11);
    for (int i = 0; i < 10; i++) {
      v[i] = 5;
    }
    v[3] = 4;
    v[7] = 4;
    v[10] = 99;

    v.unique_sort(true);

    TS_ASSERT_EQUALS(v.size(), 3);

    TS_ASSERT_EQUALS(v.get(0), 4);
    TS_ASSERT_EQUALS(v.get(1), 5);
    TS_ASSERT_EQUALS(v.get(2), 99);
  
  }

  void test_find( void ) {
    Vector<int> v(100);
    for (int i = 0; i < 100; i++) {
      v[i] = i;
    }

    TS_ASSERT_EQUALS(v.exists(50), true);
    TS_ASSERT_EQUALS(v.exists(100), false);
    TS_ASSERT_EQUALS(v.exists(99), true);
    TS_ASSERT_EQUALS(v.exists(0), true);
  }

   void test_initializer_list_constructor (void) {
     Vector<int> a = {0,1,2,3,4,5,6,7,8,9};
     TS_ASSERT_EQUALS(a.size(),10);
     for (int i = 0; i < a.size(); i++) {
       TS_ASSERT_EQUALS(a[i],i);
     }
   }

  // void test_vector_assignment( void ) {
  //   Vector<int> v({ 1, 2, 3, 4 });
  //   TS_ASSERT_EQUALS(v.get_size(), 4);
  // }

  // void test_vector_assignment_values( void ){
  //   Vector<int> v({ 1,2,3,4,5 });
  //   for (int i = 0; i < 4; i++) {
  //     TS_ASSERT_EQUALS( v.get(i), i+1 );
  //   }
  // }
};

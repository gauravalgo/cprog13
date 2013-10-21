/*
    */
  }

/*
  void test_all_values_are_init_to_zero_with_get( void  ) {
    int size = 5;
    Vector v(size);
    for (int i = 0; i < size; i++) {
      TS_ASSERT_EQUALS( v.get(i), 0 );
    }
  }

  void test_get_values_are_init_to_zero_with_index_operator( void ) {
    int size = 6;
    Vector v(6);
    for (int i = 0; i < size; i++) {
      TS_ASSERT_EQUALS( v[i], 0 );
    }
  }

  void test_set_value( void  ) {
    Vector v(1);
    v.set(0,2);
    TS_ASSERT_EQUALS( v.get(0),2 );
  }

  void get_custom_value_with_index_operator( void ) {
    Vector v(10);
    v.set(5,7);
    for (int i = 0; i < 10; i++) {
      TS_ASSERT_EQUALS( v.get(0), 0 )
    }
  }

  void test_get_value_out_of_bounds_throws_exception( void ) {
    Vector v(10);
    TS_ASSERT_THROWS_ANYTHING( v.get(10) );
  }

  void test_set_value_out_of_bounds_throws_exception( void ) {
    Vector v(10);
    TS_ASSERT_THROWS_ANYTHING( v.set(10, 10 ) );
  }

  void test_copy_constructor( void ) {
    Vector v(5);
    v.set(3,10);
    Vector v2 = v;
    TS_ASSERT_EQUALS( v2.get_size(), 5);
    TS_ASSERT_EQUALS( v2.get(3), 10 );
  }

  void test_vector_assignment( void ) {
    Vector v;
    v = { 1, 2, 3, 4 };
    TS_ASSERT_EQUALS(v.get_size(), 4);
  }*/
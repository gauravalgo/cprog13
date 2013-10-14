#include <cxxtest/TestSuite.h>
#include "julian.h"

class JulianTestSuite : public CxxTest::TestSuite
{
public:

  void test_initializing_and_basic_inheritance( void )
  {
    lab2::Julian j(2013, 10, 2);
    TS_ASSERT_EQUALS(j.year(), 2013);
    TS_ASSERT_EQUALS(j.month(), 10);
    TS_ASSERT_EQUALS(j.day(), 2);
  }

  void test_default_constructor( void ) {
    lab2::Julian j;
    TS_ASSERT_EQUALS(j.year(), 2013);
  }
  
  void test_default_constructor_date_now( void  )
  {
    lab2::Julian d(2013, 10, 2);
    TS_ASSERT_EQUALS(d.year(), 2013 );
    TS_ASSERT_EQUALS(d.month(), 10);
    TS_ASSERT_EQUALS(d.day(), 2);

    TS_ASSERT_EQUALS(d.week_day(), 3);

    TS_ASSERT_EQUALS(d.days_per_week(), 7);

    TS_ASSERT_EQUALS(d.days_this_month(), 31);
    TS_ASSERT_EQUALS(d.months_per_year(), 12);
  }
};

#include <cxxtest/TestSuite.h>
#include "date.h"

class MyTestSuite : public CxxTest::TestSuite
{
public:

  void test_default_constructor_date_now( void  )
  {
    lab2::Date d(12, 7, 2013, 10, 2);
    TS_ASSERT_EQUALS(d.year(), 2013 );
    TS_ASSERT_EQUALS(d.month(), 10);
    TS_ASSERT_EQUALS(d.day(), 2);

    TS_ASSERT_EQUALS(d.week_day(), 3);

    TS_ASSERT_EQUALS(d.days_per_week(), 7);

    TS_ASSERT_EQUALS(d.days_this_month(), 31);
    TS_ASSERT_EQUALS(d.months_per_year(), 12);

  }

  void test_plusplus_prefix(void) {
    lab2::Date d(12, 7, 2013, 10, 2);
    ++d;

    TS_ASSERT_EQUALS(d.day(), 3);
    TS_ASSERT_EQUALS(d.month(), 10);
  }

  void test_plusplus_prefix_month_shift( void ) {
    lab2::Date d(12, 7, 2013, 10, 31);
    ++d;
    TS_ASSERT_EQUALS(d.day(), 1);
    TS_ASSERT_EQUALS(d.month(), 11);
  }

  void test_minnusminus_prefix( void ) {
    lab2::Date d(12, 7, 2013, 10, 2);
    --d;

    TS_ASSERT_EQUALS(d.day(), 1);
  }

  void test_minusminus_prefix_month_shift( void ) {
    lab2::Date d(12, 7, 2013, 10, 1);
    --d;

    TS_ASSERT_EQUALS(d.day(), d.days_this_month());
    TS_ASSERT_EQUALS(d.month(), 9);
  }

};

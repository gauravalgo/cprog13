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
  }

  void test_plusplus_postfix( void ) {
    lab2::Date d(12,7, 2013, 10, 2);
    d++;

    TS_ASSERT_EQUALS(d.day(), 3);

    // TODO test this better!
  }

};

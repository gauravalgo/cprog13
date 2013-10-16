#include <cxxtest/TestSuite.h>
#include "gregorian.h"

class GregorianTestSuite : public CxxTest::TestSuite
{
public:
  void test_initializing( void )
  {
    lab2::Gregorian g(2013,10,3);
    TS_ASSERT_EQUALS(g.year(), 2013);
    TS_ASSERT_EQUALS(g.month(), 10);
    TS_ASSERT_EQUALS(g.day(), 3);
  }

  void test_empty_constructor( void ) {
    time_t tp;
    time(&tp);    
    set_k_time(tp);
    
    struct tm *t = gmtime(&tp);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon + 1;      // m mytimenaderna och dagarna
    int day   = t->tm_mday;         // indexerade fr =n ETTt k_time(NULL);
    
    lab2::Gregorian g;

    TS_ASSERT_EQUALS(g.year(), year);
    TS_ASSERT_EQUALS(g.month(), month);
    TS_ASSERT_EQUALS(g.day(), day);
  }

  void test_add_day( void )
  {
    lab2::Gregorian g(2000, 1, 30);
    TS_ASSERT_EQUALS(g.mod_julian_day(), 51573);

    ++g;
    TS_ASSERT_EQUALS(g.day(), 31);
    ++g;
    TS_ASSERT_EQUALS(g.day(), 1);
    TS_ASSERT_EQUALS(g.month(), 2);
    TS_ASSERT_EQUALS(g.mod_julian_day(), 51575);

  }

  void test_mod_julian_day( void )
  {
    lab2::Gregorian g(1858, 11, 17);

    TS_ASSERT_EQUALS(g.mod_julian_day(), 0);
  }

  void test_invalid_date( void  ) {
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 0, 1) );
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 1, 0) );
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 0, 0) );
  }

  void test_days_this_month( void ) {
    lab2::Gregorian g(2013, 10, 3);

    TS_ASSERT_EQUALS(g.days_this_month(), 31);

    g.add_month();

    TS_ASSERT_EQUALS(g.days_this_month(), 30);
  }

  void test_days_in_feb( void ) {
    lab2::Gregorian g(2013,2,20);

    TS_ASSERT_EQUALS(g.days_this_month(), 28);
  }

  void test_leap_years( void ) {
    lab2::Gregorian g(2000,2,17);

    TS_ASSERT_EQUALS(g.days_this_month(), 29)

    TS_ASSERT_EQUALS(g.leap_year(1900), false)
    TS_ASSERT_EQUALS(g.leap_year(1901), false)
    TS_ASSERT_EQUALS(g.leap_year(1902), false)
    TS_ASSERT_EQUALS(g.leap_year(1903), false)
    TS_ASSERT_EQUALS(g.leap_year(1904), true)
    TS_ASSERT_EQUALS(g.leap_year(2000), true)
  }

};

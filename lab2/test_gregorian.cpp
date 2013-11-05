#include <cxxtest/TestSuite.h>
#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"

class GregorianTestSuite : public CxxTest::TestSuite
{
public:

  void test_initializing_day_zero( void ) {
    time_t tp;
    time(&tp);
    set_k_time(tp);
    lab2::Gregorian g(1858, 11, 17);
    TS_ASSERT_EQUALS(g.year(), 1858);
    TS_ASSERT_EQUALS(g.month(), 11);
    TS_ASSERT_EQUALS(g.day(), 17);
    TS_ASSERT_EQUALS(g.mod_julian_day(), 0);
  }

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
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 1, 32) );
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 1, 0) );
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 0, 0) );
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 2, 31) );
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 13, 1) );
    
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(2000, 2, 30) );
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(2001, 2, 29) );
  }

  void test_days_this_month( void ) {
    lab2::Gregorian g(2013, 10, 3);

    TS_ASSERT_EQUALS(g.days_this_month(), 31);

    g.add_month();

    TS_ASSERT_EQUALS(g.year(), 2013);
    TS_ASSERT_EQUALS(g.month(), 11);
    TS_ASSERT_EQUALS(g.day(), 3);

    TS_ASSERT_EQUALS(g.days_this_month(), 30);

    lab2::Gregorian h(2013, 3, 31);
    h.add_month();

    TS_ASSERT_EQUALS(h.month(), 4);
    TS_ASSERT_EQUALS(h.day(), 30);
  }

  void test_get_month_lenght( void ) {
    lab2::Gregorian g(2013,2,2);

    TS_ASSERT_EQUALS(g.get_month_length(1), 31);
    TS_ASSERT_EQUALS(g.get_month_length(12), 31);
    TS_ASSERT_EQUALS(g.get_month_length(2), 28);
    
    lab2::Gregorian h(2000,2,2);
    TS_ASSERT_EQUALS(h.leap_year(), true);
    TS_ASSERT_EQUALS(h.get_month_length(2), 29);
    
    lab2::Gregorian i(2001,2,2);
    TS_ASSERT_EQUALS(i.leap_year(),false);
    TS_ASSERT_EQUALS(i.get_month_length(2), 28);
  }

  void test_add_month( void ) {
    lab2::Gregorian g(2000,1,1);
    int j = g.mod_julian_day();
    g.add_month(2);

    TS_ASSERT_EQUALS(g.month(),3);
    TS_ASSERT_EQUALS(g.day(), 1);
    TS_ASSERT_DIFFERS(g.mod_julian_day(), j);
  }

  void test_add_month_many_with_leap_year( void ) {
    lab2::Gregorian g(2000,1,30);
    g.add_month(2);

    TS_ASSERT_EQUALS(g.month(),3);
    TS_ASSERT_EQUALS(g.day(), 29);
  }

  void test_add_month_shift_year() {
    lab2::Gregorian g(2012,12,15);
    g.add_month();

    TS_ASSERT_EQUALS(g.year(), 2013);
    TS_ASSERT_EQUALS(g.month(), 1);
    TS_ASSERT_EQUALS(g.day(), 15);
    
    g.add_month(-1);
    TS_ASSERT_EQUALS(g.year(), 2012);
    TS_ASSERT_EQUALS(g.month(), 12);
    TS_ASSERT_EQUALS(g.day(), 15);

    g.add_month(-2);
    TS_ASSERT_EQUALS(g.year(), 2012);
    TS_ASSERT_EQUALS(g.month(), 10);
    TS_ASSERT_EQUALS(g.day(), 15);
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
    TS_ASSERT_EQUALS(g.leap_year(2012), true)
    TS_ASSERT_EQUALS(g.leap_year(2012), true)
    TS_ASSERT_EQUALS(g.leap_year(2016), true)
    TS_ASSERT_EQUALS(g.leap_year(2004), true)
    TS_ASSERT_EQUALS(g.leap_year(2008), true)
  }

  void test_init_leap_year_date( void ) {
    TS_ASSERT_THROWS_ANYTHING( lab2::Gregorian g(1900, 2, 29));
  }

  void test_add_year_single( void ) {
    lab2::Gregorian g(1995, 1,1);

    int j = g.mod_julian_day();
    g.add_year();
    TS_ASSERT_EQUALS(g.year(), 1996);
    TS_ASSERT_EQUALS(g.month(), 1);
    TS_ASSERT_EQUALS(g.day(), 1);
    TS_ASSERT_DIFFERS(g.mod_julian_day(), j);
  }

  void test_add_year_29_feb( void ) {
    lab2::Gregorian g(2000,2,29);
    g.add_year();
    
    TS_ASSERT_EQUALS(g.year(), 2001);
    TS_ASSERT_EQUALS(g.day(), 28);

    lab2::Gregorian h(2000,2,29);
    h.add_year(4);

    TS_ASSERT_EQUALS(h.year(), 2004);
    TS_ASSERT_EQUALS(h.day(), 29);
  }

  void test_add_3_years( void ) {
    lab2::Gregorian g(2000,2,29);
    g.add_year(3);

    TS_ASSERT_EQUALS(g.year(), 2003);
    TS_ASSERT_EQUALS(g.month(), 2);
    TS_ASSERT_EQUALS(g.day(), 28);
  }

  void test_add_negative_month( void ) {
    lab2::Gregorian g(2001, 2,28);
    g.add_year(-1);

    TS_ASSERT_EQUALS(g.year(), 2000);
    TS_ASSERT_EQUALS(g.month(), 2);
    TS_ASSERT_EQUALS(g.day(), 28);
  }
  void test_add_negative_month_leap_year( void ) {
    lab2::Gregorian g(2000, 2,29);
    g.add_year(-1);

    TS_ASSERT_EQUALS(g.year(), 1999);
    TS_ASSERT_EQUALS(g.month(), 2);
    TS_ASSERT_EQUALS(g.day(), 28);

    g.add_year(-3);
    TS_ASSERT_EQUALS(g.year(), 1996);
  }

  void test_starting_weekday( void ) {
    lab2::Gregorian g(1858, 11, 17);

    TS_ASSERT_EQUALS(g.week_day(), 3);
    TS_ASSERT_EQUALS(g.week_day_name(), "wednesday");
  }

  void test_weekdays_before_day_zero( void ) {
    lab2::Gregorian g(1858,11,16);

    TS_ASSERT_EQUALS(g.week_day(), 2);
    --g;
    TS_ASSERT_EQUALS(g.week_day(), 1);
    g.add_day(-2);
    TS_ASSERT_EQUALS(g.week_day(), 6);

    g.add_day(-8);
    TS_ASSERT_EQUALS(g.week_day(), 5);

    TS_ASSERT_EQUALS(g.mod_julian_day(), -12);
  }

  void test_other_days( void  ) {
    lab2::Gregorian g(2013, 10, 21);

    TS_ASSERT_EQUALS(g.week_day(), 1);
    TS_ASSERT_EQUALS(g.week_day_name(), "monday");
  }

  void test_month_name( void ) {
    lab2::Gregorian g(2013, 10, 21);

    TS_ASSERT_EQUALS(g.month_name(), "october");
  }

  void test_prefix_stupids( void ) {
    lab2::Gregorian g(2013, 10, 4);

    g -= 2;
    TS_ASSERT_EQUALS(g.day(), 2);

    g -= -2;
    TS_ASSERT_EQUALS(g.day(), 4);

    g += 2;
    TS_ASSERT_EQUALS(g.day(), 6);
    
    g += -2;
    TS_ASSERT_EQUALS(g.day(), 4);
    
    --g;
    TS_ASSERT_EQUALS(g.day(), 3);

    ++g;
    TS_ASSERT_EQUALS(g.day(), 4);
  }

  void test_copy_gregorian( void ) {
    lab2::Julian j1(1900,2,29);

    lab2::Gregorian * g1 = new lab2::Gregorian(j1);

    TS_ASSERT_EQUALS( j1.year(), 1900);
    TS_ASSERT_EQUALS( j1.month(), 2);
    TS_ASSERT_EQUALS( j1.day(), 29);

    TS_ASSERT_EQUALS( g1->year(), 1900);
    TS_ASSERT_EQUALS( g1->month(), 3);
    TS_ASSERT_EQUALS( g1->day(), 13);
  }

  void test_negative_add_years( void ) {
    lab2::Gregorian g( 1904,2,29);
    g.add_year(-2);

    TS_ASSERT_EQUALS( g.year(), 1902);
    TS_ASSERT_EQUALS( g.month(), 2);
    TS_ASSERT_EQUALS( g.day(), 28);

    g.add_year(2);

    TS_ASSERT_EQUALS( g.year(), 1904);
    TS_ASSERT_EQUALS( g.month(), 2);
    TS_ASSERT_EQUALS( g.day(), 28);

    ++g;
    g.add_year(4);

    TS_ASSERT_EQUALS( g.year(), 1908);
    TS_ASSERT_EQUALS( g.month(), 2);
    TS_ASSERT_EQUALS( g.day(), 29);
  }
};

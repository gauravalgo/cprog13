#include <cxxtest/TestSuite.h>
#include "julian.h"

class JulianTestSuite : public CxxTest::TestSuite
{
public:

  void test_initializing_and_basic_inheritance( void )
  {
    time_t tp;
    time(&tp);
    set_k_time(tp);
    lab2::Julian j(2013, 11, 3);
    TS_ASSERT_EQUALS(j.year(), 2013);
    TS_ASSERT_EQUALS(j.month(), 11);
    TS_ASSERT_EQUALS(j.day(), 3);
  }

  void test_default_constructor( void ) {

    time_t tp;
    time(&tp);
    set_k_time(tp);

    struct tm *t = gmtime(&tp);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon + 1;      // m mytimenaderna och dagarna
    int day   = t->tm_mday;         // indexerade fr =n ETTt k_time(NULL);

    lab2::Julian j;
    TS_ASSERT_EQUALS(j.year(), year);
  }

  void test_assignment_constructor( void ){
    lab2::Julian d(2013, 10, 2);
    lab2::Julian &a = d;
    TS_ASSERT_EQUALS(a.year(), d.year());
    TS_ASSERT_EQUALS(a.month(), d.month());
    TS_ASSERT_EQUALS(a.day(), d.day());
    d.add_day(1);
    TS_ASSERT_EQUALS(a.day(), d.day());
  }

  void test_default_constructor_date_now( void  )
  {
    lab2::Julian d(2013, 10, 2);
    TS_ASSERT_EQUALS(d.year(), 2013 );
    TS_ASSERT_EQUALS(d.month(), 10);
    TS_ASSERT_EQUALS(d.day(), 2);

    TS_ASSERT_EQUALS(d.week_day(), 2);

    TS_ASSERT_EQUALS(d.days_per_week(), 7);

    TS_ASSERT_EQUALS(d.months_per_year(), 12);

  }

  void test_mod_julian_day_zero( void ) {
    lab2::Julian d(1858, 11, 5);
    TS_ASSERT_EQUALS(d.mod_julian_day(), 0);

    lab2::Julian d2(1858, 11, 6);
    TS_ASSERT_EQUALS(d2.mod_julian_day(), 1);
  }

  void test_leap_year( void ) {
    lab2::Julian d(1902,2,20);

    TS_ASSERT_EQUALS(d.leap_year(1900), true);
    TS_ASSERT_EQUALS(d.leap_year(1901), false);
    TS_ASSERT_EQUALS(d.leap_year(1902), false);
    TS_ASSERT_EQUALS(d.leap_year(1903), false);
    TS_ASSERT_EQUALS(d.leap_year(1904), true);
  }

   void test_init_leap_year_date( void ) {
    lab2::Julian j(1900, 2, 20);
    TS_ASSERT_EQUALS( j.leap_year(), true);
  }

  void test_copy_julian_to_gregorian( void ) {
    lab2::Gregorian g1(2000, 2, 29);

    lab2::Julian * j1 = new lab2::Julian(g1);

    TS_ASSERT_EQUALS( j1->year(), 2000);
    TS_ASSERT_EQUALS( j1->month(), 2);
    TS_ASSERT_EQUALS( j1->day(), 16);
  }

  void test_add_year_negative_numbers( void ) {
    lab2::Gregorian g1(1998,9,19);

    lab2::Julian * j1 = new lab2::Julian( g1 );

    j1->add_year(-3);

    TS_ASSERT_EQUALS( j1->year(), 1995);
    TS_ASSERT_EQUALS( j1->month(), 9);
    TS_ASSERT_EQUALS( j1->day(), 6);

    ++(*j1);

    TS_ASSERT_EQUALS( j1->year(), 1995);
    TS_ASSERT_EQUALS( j1->month(), 9);
    TS_ASSERT_EQUALS( j1->day(), 7);

  }

  void test_fix_exception_in_add_month( void ) {
    lab2::Julian j1(1904,2,29);
    lab2::Julian j2(1904,2,29);

    TS_ASSERT_EQUALS( j1.leap_year(), true);

    j1.add_month(10);
    j2.add_month(11);

    TS_ASSERT_EQUALS( j1.month(), 12);
    TS_ASSERT_EQUALS( j1.year(),  1904);
    TS_ASSERT_EQUALS( j1.day(),   29);

    TS_ASSERT_EQUALS( j2.month(), 1);
    TS_ASSERT_EQUALS( j2.year(),  1905);
    TS_ASSERT_EQUALS( j2.day(),   29);
  }
};

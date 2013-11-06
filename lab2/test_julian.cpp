#include <cxxtest/TestSuite.h>
#include "date.h"
#include "julian.h"
#include "gregorian.h"

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

    j2.add_month(-2);

    TS_ASSERT_EQUALS( j2.month(), 11);
    TS_ASSERT_EQUALS( j2.year(),  1904);
    TS_ASSERT_EQUALS( j2.day(),   29);

  }

  void test_copy_date( void ) {
    // Test taget från infilen lab2c.in.
    // L1741.
    lab2::Julian        d337(2004,1,24);
    lab2::Gregorian     d324(2302,1,13); // mod julian day: 161859

    TS_ASSERT_EQUALS( d324.mod_julian_day(), 161859);

    ++d337;
    TS_ASSERT_EQUALS( d337.mod_julian_day(), 53042);
    TS_ASSERT_EQUALS( d337.week_day_name(), "saturday");
    TS_ASSERT_EQUALS( d337.day(), 25);

    TS_ASSERT_EQUALS( d337.month(), 1);

    // L1804 - copy
    // copy from 324 to 337

    d337 = d324;
    //d337 should have the same date as d324 
    TS_ASSERT_EQUALS( d337, d324);

    TS_ASSERT_EQUALS( d324.year(), 2302);
    TS_ASSERT_EQUALS( d324.month(), 1);
    TS_ASSERT_EQUALS( d324.day(), 13);

    --d324; // should not be same anymore

    TS_ASSERT_EQUALS( d324.year(), 2302);
    TS_ASSERT_EQUALS( d324.month(), 1);
    TS_ASSERT_EQUALS( d324.day(), 12);

    d337.add_year();

    TS_ASSERT_EQUALS( d337.year(), 2302);
    TS_ASSERT_EQUALS( d337.month(), 12);
    TS_ASSERT_EQUALS( d337.day(), 28);

    d337.add_month();

    TS_ASSERT_EQUALS( d337.year(), 2303);
    TS_ASSERT_EQUALS( d337.month(), 1);
    TS_ASSERT_EQUALS( d337.day(), 28);

  }

  void test_L1005( void ) {
    set_k_time(906215504);
    lab2::Julian d12;

    int d12_mod = d12.mod_julian_day();

    TS_ASSERT_EQUALS( d12.year(), 1998);
    TS_ASSERT_EQUALS( d12.month(), 9);
    TS_ASSERT_EQUALS( d12.day(), 6);

    TS_ASSERT_EQUALS( d12.mod_julian_day(), d12_mod);

    set_k_time(169073856);

    // L65
    lab2::Julian d33;

    int d33_mod = d33.mod_julian_day();
    TS_ASSERT_EQUALS( d33.year(), 1975);
    TS_ASSERT_EQUALS( d33.month(), 4);
    TS_ASSERT_EQUALS( d33.day(), 28);

    TS_ASSERT_EQUALS( d33.mod_julian_day(), d33_mod);

    // L299
    lab2::Gregorian d194 = *(new lab2::Gregorian( d33 ) );

    TS_ASSERT_EQUALS( d194.year(), 1975);
    TS_ASSERT_EQUALS( d194.month(), 5);
    TS_ASSERT_EQUALS( d194.day(), 11);

    TS_ASSERT_EQUALS( d194.mod_julian_day(), d33_mod);

    TS_ASSERT_EQUALS( d194, d33);

    // L403
    lab2::Julian d298 = d12;


    // L585
    lab2::Gregorian d480 = d194;

    TS_ASSERT_EQUALS( d480.year(), 1975);
    TS_ASSERT_EQUALS( d480.month(), 5);
    TS_ASSERT_EQUALS( d480.day(), 11);

    TS_ASSERT_EQUALS( d480.mod_julian_day(), d33_mod);

    TS_ASSERT_EQUALS( d194, d33);
    TS_ASSERT_EQUALS( d480, d33);

    // copy self L653
    d12 = d12;

    TS_ASSERT_EQUALS( d12.year(), 1998);
    TS_ASSERT_EQUALS( d12.month(), 9);
    TS_ASSERT_EQUALS( d12.day(), 6);

    TS_ASSERT_EQUALS( d12.mod_julian_day(), d12_mod);

    // copy to 480 L886
    d480 = *(new lab2::Gregorian( d12 ));

    TS_ASSERT_EQUALS( d480.year(), 1998);
    TS_ASSERT_EQUALS( d480.month(), 9);
    TS_ASSERT_EQUALS( d480.day(), 19);

    TS_ASSERT_EQUALS( d480.mod_julian_day(), d12_mod);

    // L1005
    std::cout << "Add year -3" << std::endl;
    d480.add_year(-3);
    std::cout << "Done adding year -3" << std::endl;
    TS_ASSERT_EQUALS( d480.year(), 1995);
    TS_ASSERT_EQUALS( d480.month(), 9);
    TS_ASSERT_EQUALS( d480.day(), 19);
  }

  void test_kattis_add_month_neg_28(void) {
    lab2::Julian j1(1992,2,29);
    j1.add_month(-28);

    TS_ASSERT_EQUALS(j1.year(), 1989);
    TS_ASSERT_EQUALS(j1.month(), 10);
    TS_ASSERT_EQUALS(j1.day(), 27);
  }
};

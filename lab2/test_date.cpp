#include <cxxtest/TestSuite.h>
#include "date.h"
#include <iostream>

class MyTestSuite : public CxxTest::TestSuite
{
public:
// 
//   void test_default_constructor_date_now( void  )
//   {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     TS_ASSERT_EQUALS(d.year(), 2013 );
//     TS_ASSERT_EQUALS(d.month(), 10);
//     TS_ASSERT_EQUALS(d.day(), 2);
// 
//     TS_ASSERT_EQUALS(d.week_day(), 3);
// 
//     TS_ASSERT_EQUALS(d.days_per_week(), 7);
// 
//     TS_ASSERT_EQUALS(d.months_per_year(), 12);
// 
//   }
// 
//   void test_empty_constructor( void ) {
//     lab2::Date d;
// 
//     TS_ASSERT_EQUALS(d.year(), 0);
//   }
// 
//   // ++d prefix
//   void test_plusplus_prefix(void) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     ++d;
// 
//     TS_ASSERT_EQUALS(d.day(), 3);
//     TS_ASSERT_EQUALS(d.month(), 10);
//   }
// 
//   void test_plusplus_prefix_month_shift( void ) {
//     lab2::Date d(12, 7, 2013, 10, 31);
//     ++d;
//     TS_ASSERT_EQUALS(d.day(), 1);
//     TS_ASSERT_EQUALS(d.month(), 11);
//   }
// 
//   // --d prefix
//   void test_minnusminus_prefix( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     --d;
// 
//     TS_ASSERT_EQUALS(d.day(), 1);
//   }
// 
//   void test_minusminus_prefix_month_shift( void ) {
//     lab2::Date d(12, 7, 2013, 10, 1);
//     --d;
// 
//     TS_ASSERT_EQUALS(d.month(), 9);
//   }
// 
//   // d -= 10
//   void test_minus_equlas( void ) {
//     lab2::Date d(12,7, 2013, 10, 2);
// 
//     d -= 10;
// 
//     TS_ASSERT_EQUALS(d.day(), 23); // Assumes 31 days in sept.
//     TS_ASSERT_EQUALS(d.month(), 9);
//   }
// 
//   void test_add_equals( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d += 10;
//     TS_ASSERT_EQUALS(d.day(), 12);
//     TS_ASSERT_EQUALS(d.month(), 10);
// 
//     d += 21;
//     TS_ASSERT_EQUALS(d.day(), 2);
//     TS_ASSERT_EQUALS(d.month(), 11);
//   }
// 
//   void test_add_equals_negative_value( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d+= -10;
//     TS_ASSERT_EQUALS(d.day(), 2); // does nothing
//   }
// 
//   void test_subtract_equals_negative_value( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d -= -10;
//     TS_ASSERT_EQUALS(d.day(), 2);
//   }
// 
//   // add year and month
//   void test_add_year( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d.add_year(); // n = 1;
//     TS_ASSERT_EQUALS(d.year(), 2014);
//   };
// 
//   void test_add_year_w_n( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d.add_year(19);
//     TS_ASSERT_EQUALS(d.year(), 2032);
//   }
// 
//   void test_subtract_year( void  ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d.add_year(-10);
//     TS_ASSERT_EQUALS(d.year(), 2003);
//   }
// 
//   void test_add_month( void ) {
//     lab2::Date d(12,7, 2013, 10, 2);
//     d.add_month();
//     TS_ASSERT_EQUALS(d.month(), 11);
//   }
// 
//   void test_add_month_n_negative( void ){
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d.add_month(-9);
//     TS_ASSERT_EQUALS(d.month(), 1);
//     TS_ASSERT_EQUALS(d.year(), 2013);
//   }
// 
//   void test_add_month_n_changes_year( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d.add_month(3);
//     TS_ASSERT_EQUALS(d.year(), 2014);
//     TS_ASSERT_EQUALS(d.month(), 1);
//   }
// 
//   void test_add_negative_month_n_changes_year( void ) {
//     lab2::Date d(12, 7, 2013, 10, 2);
//     d.add_month(-11);
//     TS_ASSERT_EQUALS(d.year(), 2012);
//     TS_ASSERT_EQUALS(d.month(), 12);
//   }
// 
//   // comperators
//   void test_equalsequals( void) {
//     lab2::Date d1(12, 7, 2013, 10, 2);
//     lab2::Date d2(12, 7, 2013, 10, 4);
//     lab2::Date d3(12, 7, 2013, 10, 4);
//     lab2::Date d4(12, 7, 2013, 9, 2);
//     lab2::Date d5(12, 7, 2014, 9, 2);
// 
//     TS_ASSERT_EQUALS(d1==d2, false);
//     TS_ASSERT_EQUALS(d2==d3, true);
//     TS_ASSERT_EQUALS(d1==d4, false);
//     TS_ASSERT_EQUALS(d4==d5, false);
//   }
// 
//   void test_not_equals( void ) {
//     lab2::Date d1(12, 7, 2013, 10, 2);
//     lab2::Date d2(12, 7, 2013, 10, 4);
//     lab2::Date d3(12, 7, 2013, 10, 4);
// 
//     TS_ASSERT_EQUALS(d1 != d2, true)
//     TS_ASSERT_EQUALS(d2 != d3, false)
//   }
// 
//   void test_greater_then( void  ){
//     lab2::Date d1(12, 7, 2013, 10, 2);
//     lab2::Date d2(12, 7, 2013, 10, 4);
//     lab2::Date d3(12, 7, 2013, 10, 4);
//     lab2::Date d4(12, 7, 2013, 9, 2);
// 
//     TS_ASSERT_EQUALS(d1 > d2, false)
//     TS_ASSERT_EQUALS(d2 > d3, false)
//     TS_ASSERT_EQUALS(d4 > d3, false)
//     TS_ASSERT_EQUALS(d3 > d4, true)
//     TS_ASSERT_EQUALS(d1 > d4, true)
//     
//   }
// 
//   void test_greater_equals(void) {
//     lab2::Date d1(12, 7, 2013, 10, 2);
//     lab2::Date d2(12, 7, 2013, 10, 4);
//     lab2::Date d3(12, 7, 2013, 10, 4);
// 
//     TS_ASSERT_EQUALS( d1 >= d2, false );
//     TS_ASSERT_EQUALS( d2 >= d1, true );
//     TS_ASSERT_EQUALS( d2 >= d3, true );
//   }
// 
//   void test_less_or_equal_then( void ) {
//     lab2::Date d1(12, 7, 2013, 10, 2);
//     lab2::Date d2(12, 7, 2013, 10, 4);
//     lab2::Date d3(12, 7, 2013, 10, 4);
// 
//     TS_ASSERT_EQUALS( d1 <= d2, true );
//     TS_ASSERT_EQUALS( d2 <= d1, false );
//     TS_ASSERT_EQUALS( d2 <= d3, true );
//   }
// 
//   void test_less_then( void ){
//     lab2::Date d1(12, 7, 2013, 10, 2);
//     lab2::Date d2(12, 7, 2013, 10, 4);
//     lab2::Date d3(12, 7, 2013, 10, 4);
// 
//     TS_ASSERT_EQUALS( d1 < d2, true );
//     TS_ASSERT_EQUALS( d2 < d1, false );
//     TS_ASSERT_EQUALS( d2 < d3, false );
//   }
// 
//   void test_diff_operator( void ) {
//     lab2::Date d1(12, 7, 2013, 10, 2);
//     lab2::Date d2(12, 7, 2013, 10, 4);
//     lab2::Date d3(12, 7, 2013, 10, 4);
//     lab2::Date d4(12, 7, 2013, 9, 2);
//     lab2::Date d5(12, 7, 2014, 9, 2);
// 
//     TS_ASSERT_EQUALS(d1-d2, -2);
//     TS_ASSERT_EQUALS(d2-d3, 0);
//     TS_ASSERT_EQUALS(d1-d4, 31); // assumes 31 days in this month
//     TS_ASSERT_EQUALS(d4-d5, -31*12); // assumes 31 days per month
//   }
// 
//   void test_mod_julian_day_day_zero( void ) {
//     lab2::Date d1(12, 7, 1858, 11, 17);
//     TS_ASSERT_EQUALS(d1.mod_julian_day(), 0);
//   }
// 
//   void test_mod_julian_day_first( void ) {
//     lab2::Date d1(12, 7, 1858, 11, 18);
//     TS_ASSERT_EQUALS(d1.mod_julian_day(), 1);
//   }
};

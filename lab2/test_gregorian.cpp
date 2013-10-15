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
    lab2::Gregorian g(2013, 10, 3);
    ++g;
    TS_ASSERT_EQUALS(g.day(), 4);
  }
};

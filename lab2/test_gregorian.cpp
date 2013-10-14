#include <cxxtest/TestSuite.h>
#include "gregorian.h"

class GregorianTestSuite : public CxxTest::TestSuite
{
public:
  void test_initializing( void )
  {
    lab2::Gregorian g(2013,10,2);
    TS_ASSERT_EQUALS(g.year(), 2013);
    TS_ASSERT_EQUALS(g.month(), 10);
    TS_ASSERT_EQUALS(g.day(), 2);

  }
};

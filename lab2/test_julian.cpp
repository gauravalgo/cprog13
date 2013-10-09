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
};

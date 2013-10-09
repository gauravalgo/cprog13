#include <cxxtest/TestSuite.h>
#include "julian.h"

class JulianTestSuite : public CxxTest::TestSuite
{
public:

  void test_initializing( void )
  {
    lab2::Julian j(2013, 10, 2);
    TS_ASSERT_EQUALS(j.year(), 2013);
  }
};

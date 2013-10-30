#include <cxxtest/TestSuite.h>
#include "calendar.h"

class CalTestSuite : public CxxTest::TestSuite
{
public:
	void test_init_of_calendar( void )
	{
		std::cout << "test calendar" << std::endl;
	    
		lab2::Calendar<int> gCal();
	}
};
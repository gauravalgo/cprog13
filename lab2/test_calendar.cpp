#include <cxxtest/TestSuite.h>
#include "calendar.h"

class CalTestSuite : public CxxTest::TestSuite
{
public:
	void test_init_of_calendar( void )
	{
		std::cout << "test calendar" << std::endl;

		lab2::Calendar<lab2::Gregorian> cal;

    bool returnValue = cal.set_date(2013,2,2);
    TS_ASSERT_EQUALS(returnValue, true);

    TS_ASSERT_EQUALS(cal.get_current_date().year(), 2013);

    cal.set_date(2012, 2, 2);
    TS_ASSERT_EQUALS(cal.get_current_date().year(), 2012);
  }

  void test_invalid_date( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;
    
    TS_ASSERT_THROWS_NOTHING( cal.set_date(2000, 1, 0) );

    bool returnValue = cal.set_date(2000, 1, 0);
    TS_ASSERT_EQUALS(returnValue, false);

    TS_ASSERT_EQUALS(cal.get_current_date().year(), 2013);
  }

  void test_add_event( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;


    TS_ASSERT_EQUALS( cal.events_count(), 0);
    cal.set_date(2013,1,1);
    
    cal.add_event("event1", 2013, 2, 2);
    TS_ASSERT_EQUALS( cal.events_count(), 1);
  }

  void test_add_event_out_of_range( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;

    TS_ASSERT_EQUALS(cal.events_count(), 0);    
    TS_ASSERT_THROWS_NOTHING( cal.add_event("event 1", 2013, 1, 0) );

    TS_ASSERT_EQUALS(cal.events_count(), 0); // Nothing should have been added

    TS_ASSERT_EQUALS(cal.add_event("event 1", 2013, 1, 0), false);
  }


  void test_add_several_events_to_the_same_day( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;

    cal.add_event("event 1", 2013, 1, 1);
    cal.add_event("event 2", 2013, 1, 1);

    TS_ASSERT_EQUALS(cal.events_count(), 2);
  }

  void test_add_same_event_twice_should_be_ignored( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;

    TS_ASSERT_EQUALS( cal.add_event("event 1", 2013, 1, 1), true );
    TS_ASSERT_EQUALS( cal.add_event("event 1", 2013, 1, 1), false );
    TS_ASSERT_EQUALS(cal.events_count(), 1);
  }
};
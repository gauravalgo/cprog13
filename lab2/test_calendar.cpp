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

  void test_print_events( void ) {
    lab2::Calendar<lab2::Gregorian> cal;

    cal.set_date(2012,1,1);

    TS_ASSERT_EQUALS( cal.add_event("event 1", 2013, 1, 1), true );
    TS_ASSERT_EQUALS( cal.add_event("event 2", 2013, 1, 2), true );

    std::cout << "----- Calendar ----- " << std::endl;
    std::cout << cal;
  }

  void test_copy_constructor() {
    lab2::Calendar<lab2::Gregorian> calG;

    calG.set_date(2012,1,1);

    lab2::Calendar<lab2::Julian> calJ;

    calJ.set_date(2012,1,1);

    lab2::Calendar<lab2::Julian> calJ2 = calG;
  }

  void test_of_output_version1( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;

    cal.set_date(2010, 1, 1);
    cal.add_event("Johanna!!", 2010,1,2);

    std::cout << cal;
  }

  void test_of_output_version2( void ) {
    lab2::Calendar<lab2::Gregorian> cal;
    cal.set_date(2000, 12, 2);
    cal.add_event("Basketträning", 4, 12, 2000);
    cal.add_event("Basketträning", 11, 12, 2000);
    cal.add_event("Nyårsfrukost", 1, 1, 2001);
    cal.add_event("Första advent", 1);
    // år = 2000, månad = 12
    cal.add_event("Vårdagjämning", 20, 3);
    // år = 2000
    cal.add_event("Julafton", 24, 12);
    cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
    cal.add_event("Julafton", 24); // En likadan händelse samma datum ska
    // ignoreras och inte sättas in i kalendern
    cal.add_event("Min första cykel", 20, 12, 2000);
    cal.remove_event("Basketträning", 4);
    std::cout << cal; // OBS! Vårdagjämning och första advent är
    // före nuvarande datum och skrivs inte ut
  }
};
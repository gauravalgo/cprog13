#include <cxxtest/TestSuite.h>
#include "calendar.h"

class CalTestSuite : public CxxTest::TestSuite
{
public:
	void test_init_of_calendar( void )
	{
		std::cout << "test calendar" << std::endl;
    set_k_time(906215504);
		lab2::Calendar<lab2::Gregorian> cal;

    TS_ASSERT_EQUALS(cal.get_current_date().year(), 1998);
    TS_ASSERT_EQUALS(cal.get_current_date().month(), 9);
    bool returnValue = cal.set_date(2013,2,2);
    TS_ASSERT_EQUALS(returnValue, true);

    TS_ASSERT_EQUALS(cal.get_current_date().year(), 2013);

    cal.set_date(2012, 2, 2);
    TS_ASSERT_EQUALS(cal.get_current_date().year(), 2012);
  }

  void test_invalid_date( void )
  {
    set_k_time(906215504);
    lab2::Calendar<lab2::Gregorian> cal;
    
    TS_ASSERT_THROWS_NOTHING( cal.set_date(2000, 1, 0) );

    bool returnValue = cal.set_date(2000, 1, 0);
    TS_ASSERT_EQUALS(returnValue, false);

    TS_ASSERT_EQUALS(cal.get_current_date().year(), 1998);
  }
  void test_strange_date( void ){
    lab2::Calendar<lab2::Gregorian> cal;
    TS_ASSERT_EQUALS(cal.set_date(2100,2,29), false);
     lab2::Calendar<lab2::Julian> cjul;
    TS_ASSERT_EQUALS(cjul.set_date(2100,2,29), true);
  }

  void test_add_event( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;


    TS_ASSERT_EQUALS( cal.events_count(), 0);
    cal.set_date(2013,1,1);
    
    cal.add_event("event1", 2, 2, 2013);
    TS_ASSERT_EQUALS( cal.events_count(), 1);
  }

  void test_add_event_out_of_range( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;

    TS_ASSERT_EQUALS(cal.events_count(), 0);    
    TS_ASSERT_THROWS_NOTHING( cal.add_event("event 1", 0, 1, 2013) );

    TS_ASSERT_EQUALS(cal.events_count(), 0); // Nothing should have been added

    TS_ASSERT_EQUALS(cal.add_event("event 1", 0, 1, 2013), false);
  }

  void test_add_event_with_one_parameter( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;
    cal.add_event("hejhej");
    TS_ASSERT_EQUALS(cal.events_count(), 1);
  }

  void test_add_several_events_to_the_same_day( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;

    cal.add_event("event 1", 1, 1, 2013);
    cal.add_event("event 2", 1, 1, 2013);

    TS_ASSERT_EQUALS(cal.events_count(), 2);
  }

  void test_add_same_event_twice_should_be_ignored( void )
  {
    lab2::Calendar<lab2::Gregorian> cal;

    TS_ASSERT_EQUALS( cal.add_event("event 1", 1, 1, 2013), true );
    TS_ASSERT_EQUALS( cal.add_event("event 1", 1, 1, 2013), false );
    TS_ASSERT_EQUALS(cal.events_count(), 1);
  }

  void test_print_events( void ) {
    lab2::Calendar<lab2::Gregorian> cal;

    cal.set_date(2012,1,1);

    TS_ASSERT_EQUALS( cal.add_event("event 1", 1, 1, 2013), true );
    TS_ASSERT_EQUALS( cal.add_event("event 2", 1, 2, 2013), true );

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
    cal.add_event("Johanna!!", 2, 1, 2010);

    std::cout << cal;
  }

  void test_of_output_version2( void ) {

    std::cout << "version2"<< std::endl;
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
    std::cout << "slut på version 2"<< std::endl;
    std::cout << "----------------------------------------" << std::endl;
    cal.remove_event("Vårdagjämning", 20, 3, 2000);
    cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2000);
    cal.set_date(2000, 11, 2);
    if (! cal.remove_event("Julafton", 24)) {
    std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl
    << " bort något eftersom aktuell månad är november" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << cal;
  }

  void test_remove_string_int_that_exists( void ) {
    lab2::Calendar<lab2::Gregorian> cal;
    cal.set_date(2000,12, 2);
    cal.add_event("ett", 4, 12, 2000);
    TS_ASSERT_EQUALS( cal.events_count(), 1);
    TS_ASSERT_EQUALS( cal.remove_event("ett",4), true);
    TS_ASSERT_EQUALS( cal.events_count(), 0); 
  }

  void test_remove_string_that_does_not_exists( void ) {
    lab2::Calendar<lab2::Gregorian> cal;
    cal.set_date(2000, 12, 2);
    TS_ASSERT_EQUALS( cal.remove_event("ett", 4,12,2000), false);
    cal.add_event("ett", 4, 12, 2000);
    TS_ASSERT_EQUALS( cal.remove_event("ett", 5), false);
  }

  void test_remove_string_other_int_constalations( void ) {
    lab2::Calendar<lab2::Gregorian> cal;
    cal.set_date(2000,12,2);
    cal.add_event("ett", 4, 12, 2000);
    TS_ASSERT_EQUALS( cal.events_count(), 1);
    TS_ASSERT_EQUALS(cal.remove_event("ett", 4, 12), true);
    TS_ASSERT_EQUALS( cal.events_count(), 0);
  }

  void test_remove_event_without_given_date( void ){
    lab2::Calendar<lab2::Gregorian> cal;
    cal.set_date(2000,12,2);
    cal.add_event("ett");
    TS_ASSERT_EQUALS(cal.events_count(), 1);
    TS_ASSERT_EQUALS(cal.remove_event("ett"), true);
    TS_ASSERT_EQUALS(cal.events_count(), 0);
  }

  void test_kattis_fuckar_ur_1( void ) {
    lab2::Calendar<lab2::Gregorian> gcal;
    lab2::Calendar<lab2::Julian> jcal;

    TS_ASSERT_EQUALS( gcal.set_date(1974,2,1), true);
    TS_ASSERT_EQUALS( gcal.add_event("ywrXjGV",7), true);
    TS_ASSERT_EQUALS( gcal.events_count(), 1 );

    TS_ASSERT_EQUALS( jcal.set_date(1974,2,1), true);
    TS_ASSERT_EQUALS( jcal.add_event("ywrXjGV", 7), true);
    TS_ASSERT_EQUALS( jcal.events_count(), 1 );
  }
};

#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <vector>
#include "date.h"

namespace lab2 {
	class Calendar;

}

class lab2::Calendar {
	std::vector<Date> events;

	public:
		Calendar();
		Calendar(const Calendar &);
		bool set_date(int, int, int);
		bool add_event(std::string, int, int, int);
		bool remove_event(std::string, int, int, int);

};

#endif


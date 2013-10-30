#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include "date.h"
#include "kattistime.h"

//#include <vector>
#include <map>
// http://www.cplusplus.com/reference/map/multimap/

namespace lab2 {
	template<class T>
	class Calendar {
	private:
		std::multimap<T, std::string> cal;
		T current_date;

	public:
		Calendar() : Date( T() ) {};
		Calendar(const Calendar &);
		bool set_date(int, int, int);
		bool add_event(std::string, int, int, int);
		bool remove_event(std::string, int, int, int);
		int get_current_date() const { return current_date; }

		void init(int, int, int);
	};
}

#endif


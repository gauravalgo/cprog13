#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include "date.h"
#include <stdexcept>

#include "kattistime.h"

//#include <vector>
#include <map>
// http://www.cplusplus.com/reference/map/multimap/

namespace lab2 {
	template<class T>
	class Calendar {
	private:
		std::multimap<T, std::string> calendar;
		T current_date;

	public:
		Calendar() : current_date( T() ) {
			// http://stackoverflow.com/questions/14843006/error-lnk2019unresolved-external-symbol-c/14843056#14843056
			std::cout << "Calendar() in .h" << std::endl;
		}

		bool set_date(int y, int m, int d) {
			try {
				current_date = T(y,m,d);
			} catch (std::out_of_range & e) {
				return false;
			}
			return true;
		};

		bool add_event(std::string event, int y, int m, int d) {
			try {
				T date = T( y, m , d);
				calendar.insert(std::pair<T, std::string>(date, event));
			} catch ( std::out_of_range & e) {
				return false;	
			}
			return true;
		}

		bool remove_event(std::string, int, int, int);

		int events_count() {
			return calendar.size();
		}

		T get_current_date() { return current_date; }
	};
}

#endif


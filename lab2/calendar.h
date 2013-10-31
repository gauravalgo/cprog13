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

		template< class Q>
		Calendar(const Calendar<Q> & d) : current_date( Q() ) {
			
		}

		bool set_date(int y, int m, int d) {
			try {
				current_date = T(y,m,d);
			} catch (std::out_of_range & e) {
				return false;
			}
			return true;
		};

		bool add_event(std::string s) {
			return true;
		}

		bool add_event(const std::string s, int i) {
			add_event(s, i, current_date.month(), current_date.year());
		}

		bool add_event(std::string event, int d, int m) {
			add_event(event, d, m, current_date.year());
		}

		bool add_event(std::string event, int d, int m, int y) {
			try {
				T date = T( y, m , d);

				typename std::multimap<T,std::string>::iterator it;
				std::pair <typename std::multimap<T, std::string>::iterator, typename std::multimap<T,std::string>::iterator> ret;
				ret = calendar.equal_range(date);

				// std::cout << date << " =>";
			    for (it=ret.first; it!=ret.second; ++it) {

			    	// std::cout << ' ' << it->second;
			    	if (event == (*it).second) { // second är samma som event namn
			    		// duplicate!
			    		return false;
			    	}
			    }
			    
			    std::cout << '\n';

				calendar.insert(std::pair<T, std::string>(date, event));
			} catch ( std::out_of_range & e) {
				return false;	
			}

			return true;
		}

		bool remove_event(std::string s, int d, int m, int y) {
			T date = T(y, m, d);

			typename std::multimap<T,std::string>::iterator it;
			std::pair <typename std::multimap<T, std::string>::iterator, typename std::multimap<T,std::string>::iterator> ret;
			ret = calendar.equal_range(date);

			// std::cout << date << " =>";
		    for (it=ret.first; it!=ret.second; ++it) {

		    	// std::cout << ' ' << it->second;
		    	if (s == (*it).second) {
		    		// remove it
		    		calendar.erase(it);
		    		return true;
		    	}
		    }
		    return false;
		};

		bool remove_event(std::string s, int d, int m) {
			return remove_event(s, d, m, current_date.year());
		};

		bool remove_event(std::string s, int d) {
			return remove_event(s, d, current_date.month(), current_date.year());
		}

		bool remove_event(std::string) {};

		int events_count() {
			return calendar.size();
		}

		T get_current_date() { return current_date; }

		void print_events() const {
			typename std::multimap<T, std::string>::const_iterator it;
	        
	        for (it = calendar.begin(); it != calendar.end(); it++) {
	           if (it->first > current_date) {
	                std::cout << it->first << " : " << it->second << std::endl;
	            }
	        }
		}
	};

	template <typename T>
    std::ostream & operator<<(std::ostream & os, const Calendar<T> & c) {
    	c.print_events();
        
    }
}

#endif


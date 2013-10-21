#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cmath> // abs

namespace lab2 {
  class Date;
  std::ostream & operator<<(std::ostream & os, const Date &);
}

class lab2::Date {
  protected:
    const long MODIFED_JULIAN_DAY_CONSTANT = 2400001;
    long JDN = 0;
    int lyear = 0;
    int lmonth = 0;
    int lday = 0;

    int ldays_per_week = 7;
    int lmonth_per_year = 10;

    void subtract_day();
    void add_day();
    void subtract_month();

    virtual long convert_to_jdn() const = 0;
  public:
    Date();
    Date(int m_per_year, int d_per_week);
    Date(int, int, int);
    Date(int m_per_year, int d_per_week, int y, int m, int d);

    int year() const;
    int month() const;
    int day() const;
    int week_day();
    int days_per_week();
    virtual int days_this_month() const;
    int months_per_year();

    void add_year();
    void add_year(int);

    void add_month();
    void add_month(int);

    virtual bool leap_year(int) const; 
    virtual bool leap_year() const;

    // Operators
    // Prefix
    Date & operator++();
    Date & operator--();

    Date & operator-=(int);
    Date & operator+=(int);

    // Comperators
    bool operator == ( const Date & ) const;
    bool operator != ( const Date & ) const;
    bool operator >  ( const Date & ) const;
    bool operator <  ( const Date & ) const;
    bool operator >= ( const Date & ) const;
    bool operator <= ( const Date & ) const;

    // Diff operators
    int operator-( const Date & ) const;

    long mod_julian_day() const;
};

#endif

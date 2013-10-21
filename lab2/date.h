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
    // long MODIFIED_JULIAN_DAY_CONSTANT = 2400001;
    long JDN;
    
    long get_jdn() const;

    virtual bool isValid(int, int, int) const = 0;

    virtual long convert_to_jdn(int, int, int) const = 0;
    
    virtual void subtract_day() = 0;
  public:
    Date();
    Date(Date&);

    virtual int year() const = 0;
    virtual int month() const = 0;
    virtual int day() const = 0;

    virtual int week_day() const; // ska den vara virtual
    virtual std::string week_day_name() const = 0;
    virtual std::string month_name() const = 0;
    virtual int days_per_week() const = 0;
    virtual int days_this_month() const = 0;
    virtual int months_per_year() const = 0;

    virtual void add_day() = 0;
    virtual void add_day(int) = 0;

    virtual void add_year() = 0;
    virtual void add_year(int) = 0;

    virtual void add_month() = 0;
    virtual void add_month(int) = 0;
    
    virtual bool leap_year(int) const = 0; 
    virtual bool leap_year() const = 0;


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

    virtual long mod_julian_day() const = 0;
};

#endif

#include "Date.h"

// Default constructor
Date::Date() : month(1), day(1), year(2000) {}

// Parameterized constructor
Date::Date(int mon, int day, int year) : month(mon), day(day), year(year) {}

// Getter methods
int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}
int Date::getYear() const {
    return year;
}

// Setter methods
bool Date::setMonth(int m) {
    if (m < 1 || m > 12) {
        return false; // invalid month
    }
    month = m;
    return true;
}
bool Date::setDay(int d) {
    if (d < 1 || d > 31) {
        return false; // invalid day
    }
    day = d;
    return true;
}
bool Date::setYear(int y) {
    if (y < 0) {
        return false; // invalid year
    }
    year = y;
    return true;
}

// Friend function for input operator
istream& operator >> (istream& in, Date& d) {
    char sep;
    in >> d.month >> d.day >> d.year;
    return in;
}

// Non-member functions for comparison operators

bool operator == (const Date& d1, const Date& d2) {
    return (d1.getMonth () == d2.getMonth ()) && (d1.getDay () == d2.getDay ()) && (d1.getYear () == d2.getYear ());
}
bool operator != (const Date& date1, const Date& date2) {
    return !(date1 == date2);
}

// Non-member function for output operator
ostream& operator << (ostream& out, const Date& d) {
    out << d.getMonth() << ' ' << d.getDay() << ' ' << d.getYear();
    return out;
}

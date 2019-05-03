#include <iostream>
#include "date.h"
using namespace std;

Date::Date() {
    this->year = 2019;
    this->month = 1;
    this-> day = 1;
};

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
};


Date::Date(const Date &d)
{
    this->year = d.year;
    this->month = d.month;
    this->day = d.day;
};

void Date::show()
{
    cout << this->year << "-" << this->month << "-" << this->day;
};

ostream& operator<<(ostream& os, const Date& dt)
{
	os << dt.year << "-" << dt.month << "-" << dt.day;
	return os;
}

int Date::getDay() {
    return this->day;
}

int Date::getMonth() {
    return this->month;
}

int Date::getYear() {
    return this->year;
}
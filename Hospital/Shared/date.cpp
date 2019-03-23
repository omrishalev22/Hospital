#include <iostream>
#include "date.h"
using namespace std;

Date::Date() {
    // Todo: get the real today's date.
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

int Date::getYear()
{
    return this->year;
};

int Date::getMonth()
{
    return this->month;
};

int Date::getDay()
{
    return this->day;
};

void Date::show()
{
    cout << this->year << "-" << this->month << "-" << this->day;
};
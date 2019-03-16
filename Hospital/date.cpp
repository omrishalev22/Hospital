#include "date.h"

Date::Date() {
    this->year = 2019;
    this->month = 1;
    this-> day = 1;
};

Date::Date(Date &d) {
    this->year = d.year;
    this->month = d.month;
    this->day = d.day;
}

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::show()
{
    cout << this->year << "-" << this->month << "-" << this->day;
}
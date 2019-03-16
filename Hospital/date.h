#ifndef _DATE_H
class Date {

private:
    int year, month, day;

public:
    Date();
    Date(Date& d);
    Date(int year, int month, int day);
};
#define _DATE_H

#endif //_DATE_H

#ifndef _DATE_H
#define _DATE_H
class Date {

private:
    int year, month, day;

public:
    Date();
    Date(int year, int month, int day);
    Date(const Date &d);

    int getYear();
    int getMonth();
    int getDay();
    void show();
};

#endif //_DATE_H

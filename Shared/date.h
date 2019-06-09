#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <fstream>

using namespace std;

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
	friend ostream& operator<<(ostream& os, const Date& dt);
	static Date loadDate(ifstream& inFile);
	void save(ofstream& outFile) const;
};

#endif //_DATE_H

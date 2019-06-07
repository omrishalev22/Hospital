#ifndef __PERSON_H
#define __PERSON_H
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Person {
protected:
	int id;
	string name;

public:
	Person() {};
	Person(int id, string name);
	int getID();
	const string & getName() const;
	virtual void show();
};

#endif //__PERSON_H

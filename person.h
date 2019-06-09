#ifndef __PERSON_H
#define __PERSON_H
#include "entity.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Person : public Entity {
protected:
	int id;
	string name;

public:
	Person() {};
	Person(int id, string name);
	Person(ifstream& inFile);
	void save(ofstream& outFile) const;
	int getID();
	const string & getName() const;
	virtual void show();
};

#endif //__PERSON_H

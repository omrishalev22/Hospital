#ifndef __PERSON_H
#define __PERSON_H

class Person {
protected:
	int id;
	char *name;

public:
	Person() {};
	Person(int id, char *name);
	int getID();
	char* getName();
	void show();
	virtual void dummy() {};
};

#endif //__PERSON_H

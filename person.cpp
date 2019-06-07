#include "person.h"

Person::Person(int id, string name) {
	this->id = id;
	this->name = name;
}

int Person::getID() {
	return this->id;
}

const string & Person::getName() const {
	return name;
}

void Person::show()
{
	cout << "[ " << typeid(*this).name() + 6 << " ]" << endl;
	cout << "    Name: " << this->name << endl;
	cout << "    ID: " << this->id << endl;
}
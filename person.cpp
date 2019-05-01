#include "person.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Person::Person(int id, char *name) {
	this->id = id;
	this->name = new char[strlen(name) + 1];
	this->name = strcpy(this->name, name);
}

int Person::getID() {
	return this->id;
}

char* Person::getName() {
	return this->name;
}

void Person::show()
{
	cout << "[ " << typeid(*this).name() + 6 << " ]" << endl;
	cout << "    Name: " << this->name << endl;
	cout << "    ID: " << this->id << endl;
}
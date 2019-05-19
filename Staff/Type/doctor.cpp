#include "doctor.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Doctor::Doctor(int id, char *name, char *interField) : Person(id, name) {
	this->internField = new char[strlen(interField) + 1];
	this->internField = strcpy(this->internField, interField);
}

void Doctor::show()
{
	this->Person::show();
	cout << "    Intership field: " << this->internField << endl;
}
#include "doctor.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Doctor::Doctor(int id, string name, string interField) : Person(id, name) {
	this->internField = interField;
}

void Doctor::show()
{
	this->Person::show();
	cout << "    Intership field: " << this->internField << endl;
}
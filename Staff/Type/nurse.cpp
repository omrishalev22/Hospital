#include "nurse.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Nurse::Nurse(int id, char *name, int yearsOfExperience) : Person(id, name) {
	this->yearsOfExperience = yearsOfExperience;
}

void Nurse::show()
{
	this->Person::show();
	cout << "    Years of experience: " << this->yearsOfExperience << endl;
}
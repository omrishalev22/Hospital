#include "nurse.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Nurse::Nurse(int id, const string& name, int yearsOfExperience) : Person(id, name) {
	this->yearsOfExperience = yearsOfExperience;
}

Nurse::Nurse(ifstream& inFile) : Person(inFile)
{
	inFile.read((char *)&yearsOfExperience, sizeof(yearsOfExperience));
}

void Nurse::save(ofstream& outFile) const
{
	Person::save(outFile);
	outFile.write((const char *)&yearsOfExperience, sizeof(yearsOfExperience));
}

void Nurse::show()
{
	this->Person::show();
	cout << "    Years of experience: " << this->yearsOfExperience << endl;
}
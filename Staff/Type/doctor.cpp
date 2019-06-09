#include "doctor.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Doctor::Doctor(int id, string name, string interField) : Person(id, name) {
	this->internField = interField;
}

Doctor::Doctor(ifstream& inFile) : Person(inFile)
{
	getline(inFile, internField);
}

void Doctor::save(ofstream& outFile) const
{
	Person::save(outFile);
	outFile << internField << endl;
}

void Doctor::show()
{
	this->Person::show();
	cout << "    Intership field: " << this->internField << endl;
}
#include "person.h"

Person::Person(int id, string name) {
	this->id = id;
	this->name = name;
}

Person::Person(ifstream& inFile) {
	inFile.read((char *)&id, sizeof(id));
	getline(inFile, name);
}

void Person::save(ofstream& outFile) const
{
	outFile.write((const char *)&id, sizeof(id));
	outFile << name << endl;
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
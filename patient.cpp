#include <cstring>
#include <iostream>
#include "patient.h"
#include "visit.h"
#include "surgery_visit.h"
#include "entityGenerator.h"
#include "Shared/consts.h"

using namespace std;


Patient::Patient(const Patient &patient)
{
    this->name = patient.name;
    this->id = patient.id;
    this->yearOfBirth = patient.yearOfBirth;
    this->sex = patient.sex;
}

Patient::Patient(int id, const string& name, int yearOfBirth, eSex sex) : Person(id, name)
{
	this->yearOfBirth = yearOfBirth;
    this->sex = sex;
}

Patient::Patient(ifstream& inFile) : Person(inFile)
{
	inFile.read((char *)&yearOfBirth, sizeof(yearOfBirth));
	inFile.read((char *)&sex, sizeof(sex));
	getline(inFile, departmentName);
	int amountOfVisits;
	inFile.read((char *)&amountOfVisits, sizeof(amountOfVisits));
	for (int i = 0; i < amountOfVisits; i++) {
		visits.push_back(EntityGenerator::loadEntity(inFile));
	}
}

void Patient::save(ofstream& outFile) const
{
	Person::save(outFile);
	outFile.write((const char *)&yearOfBirth, sizeof(yearOfBirth));
	outFile.write((const char *)&sex, sizeof(sex));
	outFile << departmentName << endl;
	int amountOfVisits = this->visits.size();
	outFile.write((const char *)&amountOfVisits, sizeof(amountOfVisits));
	EntityGenerator::EntityType type;
	for (int i = 0; i < amountOfVisits; i++) {
		type = EntityGenerator::getType(visits[i]);
		outFile.write((const char *)&type, sizeof(type));
		visits[i]->save(outFile);
	}
}

/*
 * Get patient's department he is currently attached to
 */
const string& Patient::getDepartmentName()
{
    return this->departmentName;
}

/*
 * Set the patient's department
 */
bool Patient::setDepartment(const string& departmentName)
{
	this->departmentName = departmentName;
    return true;
}

/*
 * Add new visit to patient's list of visits
 */
bool Patient::addNewVisit(Visit * visit)
{
    this->visits.push_back(visit);
    return true;
}

/*
 * Show patient's details
 */
void Patient::show()
{
	this->Person::show();
    cout << "    Year of birth: " << this->yearOfBirth << endl;
    cout << "    Department: " << this->departmentName << endl;
    cout << "    Sex: " << (this->getESex() == Patient::eSex::MALE ? "Male" : "Female") << endl;
    cout << "    Number of visits: " << this->visits.size() << endl;
    cout << "    Visits: " << endl;

    for (size_t i = 0; i < this->visits.size(); i++) {
        this->visits[i]->show();
		cout << endl;
    }

    cout << endl;
}


/*
 * Get patients gender
 */
Patient::eSex Patient::getESex()
{
    return sex;
}

Patient::~Patient()
{
}

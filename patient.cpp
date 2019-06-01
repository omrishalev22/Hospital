#include <cstring>
#include <iostream>
#include "patient.h"
#include "visit.h"
#include "Shared/consts.h"

using namespace std;


Patient::Patient(const Patient &patient)
{
    this->name = patient.name;
    this->id = patient.id;
    this->yearOfBirth = patient.yearOfBirth;
    this->sex = patient.sex;
}

Patient::Patient(int id, char *name, int yearOfBirth, eSex sex) : Person(id, name)
{
	this->yearOfBirth = yearOfBirth;
    this->sex = sex;
}

/*
 * Get patient's department he is currently attached to
 */
char* Patient::getDepartmentName()
{
    return departmentName;
}

/*
 * Set the patient's department
 */
bool Patient::setDepartment(char *departmentName)
{
    this->departmentName = new char[strlen(departmentName) + 1];
    this->departmentName = strcpy(this->departmentName, departmentName);
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
    delete[] this->name;
    delete[] this->departmentName;
}

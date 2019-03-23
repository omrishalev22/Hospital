#include <cstring>
#include <iostream>
#include "patient.h"

using namespace std;


Patient::Patient(char *name, int id, int yearOfBirth, eSex sex, Date arrivalDate)
{
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this->id = id;
    this->yearOfBirth = yearOfBirth;
    this->sex = sex;
    this->arrivalDate = Date(arrivalDate);
}


int Patient::getId()
{
    return id;
}


char *Patient::getName()
{
    return name;
}

bool Patient::setDepartment(char *departmentName)
{
    this->departmentName = new char[strlen(departmentName) + 1];
    this->departmentName = strcpy(this->departmentName, departmentName);
    return true;
}

void Patient::show()
{
    cout << "[Patient]" << endl;
    cout << "    Name: " << this->name << endl;
    cout << "    ID: " << this->id << endl;
    cout << "    Year of birth: " << this->yearOfBirth << endl;
    cout << "    Purpose of arrival: " << this->departmentName << endl;
    cout << "    Sex: " << (this->getESex() == 0 ? "Male" : "Female") << endl;
    cout << "    Date of arrival: ";

    this->arrivalDate.show();
    cout << endl;
}

bool Patient::setStaffMember(Nurse *nurse)
{
    this->nurse = nurse;
}

bool Patient::setStaffMember(Doctor *doctor)
{
    this->doctor = doctor;
}

Patient::eSex Patient::getESex()
{
    return sex;
}

Patient::~Patient()
{
    delete[] this->name;
    delete[] this->departmentName;
    delete this->doctor;
    delete this->nurse;
}

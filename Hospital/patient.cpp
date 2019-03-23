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
    this->visits = new Visit*[AMOUNT_OF_STARTED_ITEMS];
    this->indexVisits = 0;
    this->sizeVisits = AMOUNT_OF_STARTED_ITEMS;
}

Patient::Patient(char *name, int id, int yearOfBirth, eSex sex)
{
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this->id = id;
    this->yearOfBirth = yearOfBirth;
    this->sex = sex;
    this->visits = new Visit*[AMOUNT_OF_STARTED_ITEMS];
    this->indexVisits = 0;
    this->sizeVisits = AMOUNT_OF_STARTED_ITEMS;
}


int Patient::getId()
{
    return id;
}


char *Patient::getName()
{
    return name;
}

char* Patient::getDepartmentName()
{
    return departmentName;
}

bool Patient::setDepartment(char *departmentName)
{
    this->departmentName = new char[strlen(departmentName) + 1];
    this->departmentName = strcpy(this->departmentName, departmentName);
    return true;
}

bool Patient::addNewVisit(Visit * visit)
{
    if (this->indexVisits >= this->sizeVisits)
    {
        Visit** tempArr = new Visit*[this->sizeVisits * 2];
        for (int i = 0; i < this->indexVisits; i++)
            tempArr[i] = this->visits[i];

        delete [] this->visits;
        this->visits = tempArr;
        this->sizeVisits *= 2;
    }
    this->visits[this->indexVisits++] = visit;
    return true;
}

void Patient::show()
{
    cout << "[Patient]" << endl;
    cout << "    Name: " << this->name << endl;
    cout << "    ID: " << this->id << endl;
    cout << "    Year of birth: " << this->yearOfBirth << endl;
    cout << "    Department: " << this->departmentName << endl;
    cout << "    Sex: " << (this->getESex() == Patient::eSex::MALE ? "Male" : "Female") << endl;
    cout << "    Number of visits: " << this->indexVisits << endl;
    cout << "    Visits: " << endl;

    for (int i = 0; i < this->indexVisits; i++) {
        this->visits[i]->show();
    }

    cout << endl;
}

Patient::eSex Patient::getESex()
{
    return sex;
}

Patient::~Patient()
{
    delete[] this->name;
    delete[] this->departmentName;
    if (this->visits != nullptr) {
        for (int i = 0; i < this->indexVisits; i++)
            delete this->visits[i];
        delete[] this->visits;
    }
}

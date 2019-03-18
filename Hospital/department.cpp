#include <string>
#include <iostream>
#include <cstring>
#include "department.h"
#include "consts.h"

using namespace std;


Department::Department(char *name)
{
    this->staff = new Staff();
    this->patients = new Patient*[AMOUNT_OF_STARTED_ITEMS];
    this->indexPatients = 0;
    this->sizePatients = 0;
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
}

bool Department::addNewDoctor(Doctor *doctor)
{
    staff->addNewDoctor(doctor);
    return true;
}

bool Department::addNewNurse(Nurse *nurse)
{
    staff->addNewNurse(nurse);
    return true;
}

char *Department::getName()
{
    return name;
}

/**
 * Add new department to the hospital
 */
bool Department::addNewPatient(Patient newPatient)
{

    Patient * patient = new Patient(newPatient);
    if (this->indexPatients >= this->sizePatients) {
        Patient **tempArr = new Patient *[this->sizePatients * 2];
        for (int i = 0; i < this->indexPatients; i++)
            tempArr[i] = this->patients[i];

        delete[] this->patients;
        this->patients = tempArr;
        this->sizePatients *= 2;
    }
    this->patients[this->indexPatients++] = patient;
    return true;
}

Staff * Department::getStaffMembers() {
    return this->staff;
}

Department::~Department()
{
    // We don't delete the patients here because we will delete them in the Hospital class.
    delete[] this->patients;
}
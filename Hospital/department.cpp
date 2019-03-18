#include <string>
#include <iostream>
#include <cstring>
#include "department.h"

using namespace std;


Department::Department(char *name)
{
    setName(name);
}


bool Department::setName(char *departmentName)
{
    name = new char[strlen(departmentName) + 1];
    strcpy(name, departmentName);
}

bool Department::addNewDoctor(Doctor *doctor)
{
    staff.addNewDoctor(doctor);
}

bool Department::addNewNurse(Nurse *nurse)
{
    staff.addNewNurse(nurse);
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
}


#include <string>
#include <iostream>
#include <cstring>
#include "department.h"

using namespace std;


Department::Department(char *name)
{
    staff = new Staff();
    setIndexPatients(0);
    setSizePatients(0);
    setName(name);
}

bool Department::setIndexPatients(int index){
    this->indexPatients = index;
    return true;
}

bool Department::setSizePatients(int index){
    this->sizePatients = index;
    return true;
}

bool Department::setName(char *departmentName)
{
    name = new char[strlen(departmentName) + 1];
    strcpy(name, departmentName);
    return true;
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

Department::~Department()
{
    // We don't delete the patients here because we will delete them in the Hospital class.
    delete[] this->patients;
}
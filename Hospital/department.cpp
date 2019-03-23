#include <string>
#include <iostream>
#include <cstring>
#include "department.h"
#include "Shared/consts.h"

using namespace std;


Department::Department(char *name)
{
    this->staff = new Staff();
    this->patients = new Patient *[AMOUNT_OF_STARTED_ITEMS];
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
bool Department::addNewPatient(Patient *newPatient)
{
    if (this->indexPatients >= this->sizePatients) {
        Patient **tempArr = new Patient *[this->sizePatients * 2];
        for (int i = 0; i < this->indexPatients; i++)
            tempArr[i] = this->patients[i];

        delete[] this->patients;
        this->patients = tempArr;
        this->sizePatients *= 2;
    }
    this->patients[this->indexPatients++] = newPatient;
    this->addPatientToStaffMember(newPatient);
    return true;
}

Staff *Department::getStaffMembers()
{
    return this->staff;
}

void Department::showPatients()
{
    if (indexPatients == 0) {
        cout << "There are no patient in the current department." << endl;
    } else {
        for (int i = 0; i < indexPatients; i++) {
            patients[i]->show();
        }
    }
}


/**
 * Random mechanism to choose a staff member to a patient
 *
 * The algorithm makes no sense in terms of logic, described in the known issues file.
 * @param patient
 * @return
 */
bool Department::addPatientToStaffMember(Patient *patient)
{
    int staffSize = staff->getNumberOfDoctors() + staff->getNumberOfNurses();
    if (strcmp(patient->getName(), "j") > 0) {
        int index = staffSize % staff->getNumberOfNurses();
        Nurse *nurse = staff->getNurseByIndex(index);
        patient->setStaffMember(nurse);
    } else {
        int index = staffSize % staff->getNumberOfDoctors();
        Doctor *doctor = staff->getDoctorByIndex(index);
        patient->setStaffMember(doctor);
    }
}

Department::~Department()
{
    // We don't delete the patients here because we will delete them in the Hospital class.
    delete[] this->patients;
}
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

/*
 * Attach a new Doctor to department
 */
bool Department::addNewDoctor(Doctor *doctor)
{
    staff->addNewDoctor(doctor);
    return true;
}

/*
 * Attach a new Nurse to department
 */
bool Department::addNewNurse(Nurse *nurse)
{
    staff->addNewNurse(nurse);
    return true;
}

/*
 * Get the current department name
 */
char *Department::getName()
{
    return name;
}

/**
 * Add new patient to department
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
    return true;
}

/*
 * Get Department's staff members
 */
Staff *Department::getStaffMembers()
{
    return this->staff;
}

/*
 * Print to stdout all patients in current department
 */
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
 * Removing a patient from list of patients by pointing the chosen patient
 * to null and create a new array of patients without the removed one.
 * @param patientID
 * @return
 */
bool Department::removePatientByID(int patientID)
{
    Patient **tempArr = new Patient *[this->indexPatients];
    int index = 0;

    for (int i = 0; i < this->indexPatients; i++) {
        // in case patient does not match the given ID add to new arr
        if (patients[i]->getID() != patientID) {
            tempArr[index] = this->patients[index];
            index++;
        } else {
            // removing the access not deleting the element since it is used in other place
            this->patients[i] = nullptr;
        }
    }

    if (index == indexPatients) { // nothing changed, meaning no patient was found matching to the corresponding ID
        cout << "couldn't find any patient under this ID" << endl;
        return false;
    }

    delete[] this->patients;
    this->patients = tempArr;
    this->indexPatients--;
    return true;
}

/*
 * Free memoery allocation
 */
Department::~Department()
{
    // We don't delete the patients here because we will delete them in the Hospital class. just the    pointer to them
    delete[] this->patients;
    delete[] this->name;
    delete[] this->staff;
}
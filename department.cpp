#include <string>
#include <iostream>
#include <cstring>
#include "department.h"
#include "Shared/consts.h"
#include "Shared/Array.h"

using namespace std;

Department::Department(char *name)
{
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
	this->staff = new Staff();
}

/*
* Attach new staff member to the department
*/
bool Department::operator+=(Person* staffMember) {
	this->staff->addNewStaffMember(staffMember);
	return true;
}
/*
 * Attach a new Nurse to department
 */
bool Department::addNewNurse(Nurse *nurse)
{
	this->staff->addNewStaffMember(nurse);
    return true;
}

/*
 * Get the current department name
 */
char *Department::getName()
{
    return name;
}

Staff * Department::getStaffMembers()
{
	return this->staff;
}

/**
 * Add new patient to department
 */
bool Department::addNewPatient(Patient *newPatient)
{
    this->patients += newPatient;
    return true;
}


/*
 * Print to stdout all patients in current department
 */
void Department::showPatients()
{
    if (patients.getSize() == 0) {
        cout << "There are no patient in the current department." << endl;
    } else {
        for (int i = 0; i < patients.getSize(); i++) {
            patients[i]->show();
        }
    }
}

Patient * Department::getPatientByID(int id)
{
	for (int i = 0; i < patients.getSize(); i++) {
		if (patients[i]->getID() == id) {
			return patients[i];
		}
	}
	return nullptr;
}


/**
 * Filtering current patients based on the given patient ID, at this point we are sure
 * after validation that we have such patient (thus the proccess is not for nothing)
 * new arr is created.
 * @param patientID
 * @return
 */
bool Department::removePatientByID(int patientID)
{
	Patient * patient = this->getPatientByID(patientID);
	if (patient == nullptr) {
		return false;
	}

	Array<Patient *> tmp(this->patients.getSize());
	int counter = 0;
	for (int i = 0; i < patients.getSize(); i++) {
		if (patients[i]->getID() != patientID) {
			tmp += patients[counter];
		}
	}
	patients = tmp;
    return true;
}

ostream& operator<<(ostream& os, const Department& department)
{
	os << "Department: " << department.name;
	return os;
}

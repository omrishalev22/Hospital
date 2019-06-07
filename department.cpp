#include <string>
#include <iostream>
#include <cstring>
#include "department.h"
#include "Shared/consts.h"

using namespace std;

Department::Department(const string& name)
{
	this->name = name;
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
const string& Department::getName()
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
    this->patients.push_back(newPatient);
    return true;
}


/*
 * Print to stdout all patients in current department
 */
void Department::showPatients()
{
    if (patients.size() == 0) {
        cout << "There are no patient in the current department." << endl;
    } else {
        for (size_t i = 0; i < patients.size(); i++) {
            patients[i]->show();
        }
    }
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
	int patientIndex = 0;
	vector<Patient *>::iterator it = patients.begin();
	for (it = patients.begin(); it != patients.end(); ++it) {
		if ((*it)->getID() == patientID) {
			continue;
		}
		patientIndex++;
	}
	patients.erase(patients.begin()+ patientIndex);
    return true;
}

ostream& operator<<(ostream& os, const Department& department)
{
	os << "Department: " << department.name;
	return os;
}

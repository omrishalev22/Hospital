#include <string>
#include <iostream>
#include <cstring>
#include "department.h"
#include "Shared/consts.h"
#include "entityGenerator.h"

using namespace std;

Department::Department(const string& name)
{
	this->name = name;
}

Department::Department(ifstream& inFile)
{
	getline(inFile, name);
	int amountOfPatients, amountOfStaffMembers;
	// Loading patients
	inFile.read((char *)&amountOfPatients, sizeof(amountOfPatients));
	for (int i = 0; i < amountOfPatients; i++) {
		patients.push_back(EntityGenerator::loadEntity(inFile));
	}

	// Loading members
	inFile.read((char *)&amountOfStaffMembers, sizeof(amountOfStaffMembers));
	for (int i = 0; i < amountOfStaffMembers; i++) {
		members.push_back(EntityGenerator::loadEntity(inFile));
	}
}

void Department::save(ofstream& outFile) const
{
	outFile << name << endl;
	// Saving patients
	int amountOfPatients = (int)patients.size();
	outFile.write((const char *)&amountOfPatients, sizeof(amountOfPatients));
	EntityGenerator::EntityType type;
	for (size_t i = 0; i < patients.size(); i++) {
		type = EntityGenerator::getType(patients[i]);
		outFile.write((const char *)&type, sizeof(type));
		patients[i]->save(outFile);
	}

	// Saving staff members
	int amountOfStaffMembers = (int)members.size();
	outFile.write((const char *)&amountOfStaffMembers, sizeof(amountOfStaffMembers));
	for (size_t j = 0; j < members.size(); j++) {
		type = EntityGenerator::getType(members[j]);
		outFile.write((const char *)&type, sizeof(type));
		members[j]->save(outFile);
	}
}

/*
* Attach new staff member to the department
*/
bool Department::operator+=(Person* staffMember) {
	this->addNewStaffMember(staffMember);
	return true;
}
/*
 * Attach a new Nurse to department
 */
bool Department::addNewNurse(Nurse *nurse)
{
	this->addNewStaffMember(nurse);
    return true;
}

/*
 * Get the current department name
 */
const string& Department::getName()
{
    return name;
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
	vector<Entity *>::iterator it = patients.begin();
	for (it = patients.begin(); it != patients.end(); ++it) {
		if (((Patient *)*it)->getID() == patientID) {
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


bool Department::isStaffEmpty()
{
	return this->members.size() == 0;
}

void Department::showStaff()
{
	int i;
	cout << "Showing all staff members:" << endl;
	if (this->members.size() == 0) {
		cout << "There are no staff members in the specific department." << endl;
	}
	else {
		for (i = 0; i < (int)members.size(); i++) {
			members[i]->show();
		}
	}
}

bool Department::addNewStaffMember(Person * member)
{
	this->members.push_back(member);
	return true;
}

Person * Department::getStaffMemberByID(int id)
{
	for (int i = 0; i < (int)members.size(); i++) {
		if (((Person *)members[i])->getID() == id) {
			return (Person *)(members[i]);
		}
	}

	return nullptr;
}

int Department::getAmountOfStaffMembers()
{
	return (int)members.size();
}
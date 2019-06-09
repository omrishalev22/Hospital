#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "entity.h"
#include "Staff/Type/doctor.h"
#include "Staff/Type/surgent.h"
#include "Staff/Type/nurse.h"
#include "patient.h"
#include <iostream>
#include <vector>

using namespace std;

class Department : public Entity
{
private:
    std::string name;
	vector<Entity *>patients;
	vector<Entity *> members;

public:
	enum staffMembersTypes
	{
		DOCTOR,
		NURSE,
		SURGENT
	};
    explicit Department(const string& name);
	Department(ifstream& inFile);
	void save(ofstream& outFile) const;

    // GETTERS
    const string& getName();
    void showPatients();
	friend ostream& operator<<(ostream& os, const Department& department);
	bool isStaffEmpty();
	void showStaff();
	Person * getStaffMemberByID(int id);
	int getAmountOfStaffMembers();


    // SETTERS
	bool operator+=(Person* staffMember);
	bool addNewNurse(Nurse *nurse);
	bool addNewPatient(Patient * patient);
    bool removePatientByID(int patientID);
	bool addNewStaffMember(Person * member);

};

#endif // __DEPARTMENT_H
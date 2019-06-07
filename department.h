#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "Staff/staff.h"
#include "Staff/Type/doctor.h"
#include "Staff/Type/surgent.h"
#include "Staff/Type/nurse.h"
#include "patient.h"
#include <iostream>
#include <vector>

using namespace std;

class Department
{
private:
    std::string name;

	Staff * staff;
	vector<Patient*>patients;


public:

    explicit Department(const string& name);

    // GETTERS
    const string& getName();
	Staff * getStaffMembers();
    void showPatients();
	friend ostream& operator<<(ostream& os, const Department& department);


    // SETTERS
	bool operator+=(Person* staffMember);
	bool addNewNurse(Nurse *nurse);
	bool addNewPatient(Patient * patient);
    bool removePatientByID(int patientID);

};

#endif // __DEPARTMENT_H
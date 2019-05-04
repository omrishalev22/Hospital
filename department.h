#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "Staff/staff.h"
#include "Staff/Type/doctor.h"
#include "Staff/Type/surgent.h"
#include "Staff/Type/nurse.h"
#include "patient.h"
#include <iostream>

using namespace std;

class Department
{
private:
    char *name;
    Staff * staff;
    Patient ** patients;
    int indexPatients;
    int sizePatients;


public:

    explicit Department(char *name);

    // GETTERS
    char *getName();
    Staff * getStaffMembers();
    void showPatients();
	friend ostream& operator<<(ostream& os, const Department& department);


    // SETTERS
	bool operator+=(Person* staffMember);
    bool addNewNurse(Nurse *nurse);
    bool addNewPatient(Patient * patient);
    bool removePatientByID(int patientID);
    ~Department();

};

#endif // __DEPARTMENT_H
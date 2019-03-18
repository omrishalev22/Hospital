#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "staff.h"
#include "Staff-Members/doctor.h"
#include "Staff-Members/nurse.h"
#include "patient.h"

class Department
{
private:
    char *name;
    Staff staff;
    Patient ** patients;
    int indexPatients = 0;
    int sizePatients = 0;


public:

    Department(char *name);

    // GETTERS
    char *getName();

    Staff *getStaffMembers();
    Patient *getStaffPatients();


    // SETTERS
    bool setName(char *name); // in case in future someone want to change the name
    bool addNewDoctor(Doctor *doctor);
    bool addNewNurse(Nurse *nurse);
    bool addNewPatient(Patient patient);

};

#endif // __DEPARTMENT_H
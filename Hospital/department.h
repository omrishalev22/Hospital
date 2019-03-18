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


    // SETTERS
    bool addNewDoctor(Doctor *doctor);
    bool addNewNurse(Nurse *nurse);
    bool addNewPatient(Patient patient);

    ~Department();

};

#endif // __DEPARTMENT_H
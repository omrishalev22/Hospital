#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "staff.h"
#include "Staff-Members/doctor.h"
#include "Staff-Members/nurse.h"

class Department
{
private:
    char * name;
    Staff staff[20]; // TODO dynamic

public:

    Department(){};
    Department(char * name);

    const char * getName();
    void setName(char * name); // in case in future someone want to change the name

    void addNewDoctor(Doctor doctor);
    void addNewNurse(Nurse nurse);
};

#endif // __DEPARTMENT_H
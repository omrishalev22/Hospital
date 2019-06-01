#include "Shared/date.h"
#include "Staff/staff.h"
#include "visit.h"
#include "person.h"
#include <vector>

#ifndef __PATIENT_H
#define __PATIENT_H

class Patient : public Person
{
public:
    enum eSex
    {
        MALE, FEMALE
    };

    Patient(const Patient& patient);
    Patient(int id, char *name, int yearOfBirth, eSex sex);

    // GETTERS
    void show();
    eSex getESex();
    char *getDepartmentName();

    // SETTERS
    bool setDepartment(char * departmentName);
    bool addNewVisit(Visit * visit);

    ~Patient();
private:
    int yearOfBirth;
    char *departmentName;
    eSex sex;
    vector<Visit*> visits;
};

#endif //__PATIENT_H

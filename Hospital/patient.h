#include "Shared/date.h"
#include "Staff/staff.h"
#include "visit.h"

#ifndef __PATIENT_H
#define __PATIENT_H

class Patient
{
public:
    enum eSex
    {
        MALE, FEMALE
    };

    Patient(const Patient& patient);
    Patient(char *name, int id, int yearOfBirth, eSex sex);

    // GETTERS
    int getId();
    char *getName();
    void show();
    eSex getESex();
    char *getDepartmentName();

    // SETTERS
    bool setDepartment(char * departmentName);
    bool addNewVisit(Visit * visit);

    ~Patient();
private:
    char *name;
    int id;
    int yearOfBirth;
    char *departmentName;
    eSex sex;
    Visit ** visits;
    int indexVisits;
    int sizeVisits;

};

#endif //__PATIENT_H

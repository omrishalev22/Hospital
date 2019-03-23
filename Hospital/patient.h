#include "Shared/date.h"
#include "Staff/staff.h"

#ifndef __PATIENT_H
#define __PATIENT_H

class Patient
{
public:
    enum eSex
    {
        MALE, FEMALE
    };

    Patient(const Patient& patient) {
        this->name = patient.name;
        this->id = patient.id;
        this->yearOfBirth = patient.yearOfBirth;
        this->sex = patient.sex;
        this->arrivalDate = patient.arrivalDate;
    }

    Patient(char *name, int id, int yearOfBirth, eSex sex, Date arrivalDate);

    // GETTERS
    int getId();
    char *getName();
    void show();
    eSex getESex();

    // SETTERS
    bool setDepartment(char * departmentName);
    bool setStaffMember(Nurse * nurse);
    bool setStaffMember(Doctor * doctor);

    ~Patient();
private:
    char *name;
    int id;
    int yearOfBirth;
    char *departmentName;
    Date arrivalDate;
    eSex sex;
    Doctor * doctor;
    Nurse * nurse;


};

#endif //__PATIENT_H

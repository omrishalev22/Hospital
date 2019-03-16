#include "date.h"

#ifndef __PATIENT_H
#define __PATIENT_H
enum eSex
{
    MALE, FEMALE
};

class Patient
{
private:
    char *name;
    int id;
    int yearOfBirth;
    char *purpose;
    Date arrivalDate;
    eSex sex;

public:
    Patient(char *name, int id, int yearOfBirth, eSex sex, Date arrivalDate);

    // GETTERS
    int getId();
    char *getName();

    // SETTERS
    bool setVisitPurpose(char * purpose);
};

#endif //__PATIENT_H

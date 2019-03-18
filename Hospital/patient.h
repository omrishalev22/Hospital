#include "date.h"

#ifndef __PATIENT_H
#define __PATIENT_H

class Patient
{
public:
    enum eSex
    {
        MALE, FEMALE
    };

    Patient(char *name, int id, int yearOfBirth, eSex sex, Date arrivalDate);

    // GETTERS
    int getId();
    char *getName();
    void show();
    eSex getESex();

    // SETTERS
    bool setVisitPurpose(char * purpose);
private:
    char *name;
    int id;
    int yearOfBirth;
    char *purpose;
    Date arrivalDate;
    eSex sex;


};

#endif //__PATIENT_H

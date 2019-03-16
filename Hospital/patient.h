#include "date.h"

#ifndef __PATIENT_H
#define __PATIENT_H

class Patient {
    enum eSex { MALE, FEMALE };

private:
    char * name;
    int id;
    int yearOfBirth;
    eSex sex;
    char * purpose;
    Date arrivalDate;

public:
    Patient(char * name,int id, int yearOfBirth, eSex sex, char* purpose, Date arrivalDate);
};
#endif //__PATIENT_H

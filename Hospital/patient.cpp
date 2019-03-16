#include <cstring>
#include "patient.h"

Patient::Patient(char *name, int id, int yearOfBirth, eSex sex, Date arrivalDate)
{
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this->id = id;
    this->yearOfBirth = yearOfBirth;
    this->sex = sex;
    this->arrivalDate = Date(arrivalDate);
}


int Patient::getId()
{
    return id;
}


char *Patient::getName()
{
    return name;
}

bool Patient::setVisitPurpose(char * purpose){
    this->purpose = new char[strlen(purpose) + 1];
    this->purpose = strcpy(this->purpose, purpose);
}
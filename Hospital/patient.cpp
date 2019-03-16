#include <cstring>
#include "patient.h"

Patient::Patient(char *name, int id, int yearOfBirth, Patient::eSex sex, char *purpose, Date arrivalDate) {
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this->id = id;
    this->yearOfBirth = yearOfBirth;
    this-> sex = sex;
    this->purpose = new char[strlen(purpose) + 1];
    this->purpose = strcpy(this->purpose, purpose);
    this->arrivalDate = Date(arrivalDate);
}
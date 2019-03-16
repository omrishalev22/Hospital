#include "patient.h"

Patient::Patient(char *name, int id, int yearOfBirth, Patient::eSex sex, char *purpose, Date arrivalDate) {
    this->name = name;
    this->id = id;
    this->yearOfBirth = yearOfBirth;
    this-> sex = sex;
    this->purpose = purpose;
    this->arrivalDate = Date(arrivalDate);
}
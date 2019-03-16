#include "patient.h"

Patient::Patient(char *name, int id, int yearOfBirth, Patient::eSex sex) {
    this->name = name;
    this->id = id;
    this->yearOfBirth = yearOfBirth;
    this-> sex = sex;
}


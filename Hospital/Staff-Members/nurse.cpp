#include "nurse.h"
#include <string>
#include <iostream>
#include <cstring>

Nurse::Nurse(char *nurseName, int id, int yearsOfExperience) : id(id), yearsOfExperience(yearsOfExperience) {
    delete[]name;
    name = new char[strlen(nurseName)+1];
    strcpy(name, nurseName);
}
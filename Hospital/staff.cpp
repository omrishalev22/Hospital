#include <string>
#include <iostream>
#include "staff.h"

using namespace std;


bool Staff::addNewNurse(Nurse *nurse)
{
    if (this->indexNurses >= this->sizeNurses) {
        Nurse **tempArr = new Nurse *[this->sizeNurses + 2];
        for (int i = 0; i < this->indexNurses; i++)
            tempArr[i] = this->nurses[i];

        delete[] this->nurses;
        this->nurses = tempArr;
        this->sizeNurses += 2;
    }
    this->nurses[this->indexNurses++] = nurse;
}

bool Staff::addNewDoctor(Doctor *doctor)
{
    if (this->indexDoctors >= this->sizeDoctors) {
        Doctor **tempArr = new Doctor *[this->sizeDoctors * 2];
        for (int i = 0; i < this->indexDoctors; i++)
            tempArr[i] = this->doctors[i];

        delete[] this->nurses;
        this->doctors = tempArr;
        this->sizeDoctors *= 2;
    }
    this->doctors[this->indexDoctors++] = doctor;
}


Staff::~Staff()
{
    if (this->nurses != nullptr) {
        for (int i = 0; i < this->indexNurses; i++)
            delete this->nurses[i];
        delete[] this->nurses;
    }

    if (this->doctors != nullptr) {
        for (int i = 0; i < this->indexDoctors; i++)
            delete this->doctors[i];
        delete[] this->doctors;
    }
}


#include <string>
#include <iostream>
#include "staff.h"
#include "consts.h"

using namespace std;

Staff::Staff() {
    this->doctors = new Doctor *[AMOUNT_OF_STARTED_ITEMS];
    this->indexDoctors = 0;
    this->sizeDoctors = AMOUNT_OF_STARTED_ITEMS;

    this->nurses = new Nurse *[AMOUNT_OF_STARTED_ITEMS];
    this->indexNurses = 0;
    this->sizeNurses = AMOUNT_OF_STARTED_ITEMS;
}

void Staff::show() {
    int i;
    cout << "Showing all doctors:" << endl;
    if (indexDoctors == 0) {
        cout << "There are no doctors in the specific department." << endl;
    } else {
        for (i = 0; i < indexDoctors; i++) {
            doctors[i]->show();
        }
    }

    cout << "Showing all nurses:" << endl;
    if (indexNurses == 0) {
        cout << "There are no nurses in the specific department." << endl;
    } else {
        for (i = 0; i < indexNurses; i++) {
            nurses[i]->show();
        }
    }
}

bool Staff::addNewNurse(Nurse *nurse) {
    if (this->indexNurses >= this->sizeNurses) {
        Nurse **tempArr = new Nurse *[this->sizeNurses * 2];
        for (int i = 0; i < this->indexNurses; i++)
            tempArr[i] = this->nurses[i];

        delete[] this->nurses;
        this->nurses = tempArr;
        this->sizeNurses *= 2;
    }
    this->nurses[this->indexNurses++] = nurse;
    return true;
}

bool Staff::addNewDoctor(Doctor *doctor) {
    if (this->indexDoctors >= this->sizeDoctors) {
        Doctor **tempArr = new Doctor *[this->sizeDoctors * 2];
        for (int i = 0; i < this->indexDoctors; i++)
            tempArr[i] = this->doctors[i];

        delete[] this->nurses;
        this->doctors = tempArr;
        this->sizeDoctors *= 2;
    }
    this->doctors[this->indexDoctors++] = doctor;
    return true;
}


Staff::~Staff() {
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


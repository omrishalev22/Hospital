#include <string>
#include <iostream>
#include "staff.h"

using namespace std;


bool Staff::addNewNurse(Nurse nurse){
    nurses[numOfNurses] = nurse; // TODO add this dynamically
    numOfNurses++;
}

bool Staff::addNewDoctor(Doctor doctor){
    doctors[numOfDoctors] = doctor; // TODO add this dynamically
    numOfDoctors++;
}


Staff::~Staff(){
    delete[] nurses;
    delete[] doctors;
}


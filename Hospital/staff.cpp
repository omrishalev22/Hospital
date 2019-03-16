#include <string>
#include <iostream>
#include "staff.h"

using namespace std;

bool Staff::addNewNurse(Nurse nurse){
    nurses[0] = nurse; // TODO add this dynamically
}

Staff::~Staff(){
    delete[] nurses;
    delete[] doctors;
}
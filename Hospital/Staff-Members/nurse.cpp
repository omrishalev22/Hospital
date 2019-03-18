#include "nurse.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Nurse::Nurse(char *name, int id, int yearsOfExperience) {
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this -> id =  id;
    this -> yearsOfExperience =  yearsOfExperience;
}

int Nurse::getID()
{
    return this->id;
}


void Nurse::show()
{
    cout << "[Nurse]" << endl;
    cout << "    Name: " << this->name << endl;
    cout << "    ID: " << this->id << endl;
    cout << "    Years of experience: " << this->yearsOfExperience << endl;
}
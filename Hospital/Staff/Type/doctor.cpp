#include "doctor.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Doctor::Doctor(int id, char *name, char *interField) {
    this->id = id;
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this->internField = new char[strlen(interField) + 1];
    this->internField = strcpy(this->internField, interField);
}

int Doctor::getID() {
    return this->id;
}

void Doctor::show()
{
    cout << "[Doctor]" << endl;
    cout << "    Name: " << this->name << endl;
    cout << "    ID: " << this->id << endl;
    cout << "    Intership field: " << this->internField << endl;
}
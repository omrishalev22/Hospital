#include "Department.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;


Department::Department(char * name) {
        setName(name);
}

void Department::setName(char * departmentName) {
    name = new char[strlen(departmentName) + 1];
    strcpy(name,departmentName);
}

const char * Department::getName() {
    return name;
}

void Department::addNewDoctor(Doctor doctor) {

}


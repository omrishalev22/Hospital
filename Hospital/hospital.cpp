#include <string>
#include <iostream>
#include "hospital.h"
#define SIZE 150
using namespace std;


Hospital::Hospital() {

}

/**
 * Add new department to the hospital
 */
bool Hospital::addNewDepartment(){
    char name[SIZE];
    cout << "Please type the department name:\n";
    cin >> name;
    Department * department = new Department(name);
    departments[0] = *department;
}

/**
 * Add new Nurse to specific department
 */
bool Hospital::addNewNurseToDepartment(){
    int ID,yearsOfExperience;
    char name[SIZE], departmentName[SIZE];

    cout << "Please type the nurse's ID:\n";
    cin >> ID;

    cout << "Please type the nurse's name:\n";
    cin >> name;

    cout << "Please type the nurse's years of experience:\n";
    cin >> yearsOfExperience;

    cout << "Please type the department name you want to attach nurse to:\n";
    cin >> departmentName;

    Nurse * nurse = new Nurse(name,ID,yearsOfExperience);
    departments[0].addNewNurse(*nurse); // TODO get department by NAME
}
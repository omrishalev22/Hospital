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
 * Add new Nurse to a specific department
 */
bool Hospital::addNewNurseToDepartment(){
    int id,yearsOfExperience;
    char name[SIZE], departmentName[SIZE];

    cout << "Please type the nurse's ID:\n";
    cin >> id;

    cout << "Please type the nurse's name:\n";
    cin >> name;

    cout << "Please type the nurse's years of experience:\n";
    cin >> yearsOfExperience;

    cout << "Please type the department name you want to attach nurse to:\n";
    cin >> departmentName;

    Nurse * nurse = new Nurse(name,id,yearsOfExperience);
    departments[0].addNewNurse(*nurse); // TODO get department by NAME
}

/**
 * Add new Doctor to a specific department
 */
bool Hospital::addNewDoctorToDepartment(){
    int id = 0;
    char name[SIZE], departmentName[SIZE], interField[SIZE];

    cout << "Please type the doctor's ID:\n";
    cin >> id;

    cout << "Please type the doctor's name:\n";
    cin >> name;

    cout << "Please type the doctor's internship field:\n";
    cin >> interField;

    cout << "Please type the department name you want to attach doctor to:\n";
    cin >> departmentName;

    Doctor * doctor = new Doctor(id,name,interField);
    departments[0].addNewDoctor(*doctor); // TODO get department by NAME
}
#include <string>
#include <iostream>
#include <cstring>
#include "hospital.h"

#define SIZE 150
using namespace std;

Hospital::Hospital() {

}
/**
 * Add new department to the hospital
 */
bool Hospital::addNewDepartment()
{
    char name[SIZE];
    cout << "Please type the department name:\n";
    cin >> name;

    Department *department = new Department(name);
    if (this->indexDepartments >= this->sizeDepartments) {
        Department **tempArr = new Department *[this->sizeDepartments * 2];
        for (int i = 0; i < this->indexDepartments; i++)
            tempArr[i] = this->departments[i];

        delete[] this->departments;
        this->departments = tempArr;
        this->sizeDepartments *= 2;
    }
    this->departments[this->indexDepartments++] = department;
}

/**
 * Add new Nurse to a specific department
 */
bool Hospital::addNewNurseToDepartment()
{
    int id, yearsOfExperience;
    char name[SIZE], departmentName[SIZE];

    cout << "Please type the nurse's ID:\n";
    cin >> id;

    cout << "Please type the nurse's name:\n";
    cin >> name;

    cout << "Please type the nurse's years of experience:\n";
    cin >> yearsOfExperience;

    cout << "Please type the department name you want to attach nurse to:\n";
    cin >> departmentName;

    Nurse *nurse = new Nurse(name, id, yearsOfExperience);
    getDepartmentByName(departmentName)->addNewNurse(nurse);
}

/**
 * Add new Doctor to a specific department
 */
bool Hospital::addNewDoctorToDepartment()
{
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

    Doctor *doctor = new Doctor(id, name, interField);
    getDepartmentByName(departmentName)->addNewDoctor(doctor);
}

Department *Hospital::getDepartmentByName(char *name)
{
    if (this->sizeDepartments > 0) {
        for (int i = 0; i < sizeDepartments; i++) {
            if (strcmp(departments[i]->getDepartmentName(), name) > 0) {
                return departments[i];
            }
        }
    }
    cout << " couldn't find the department you are searching for\n";
}
#include <string>
#include <iostream>
#include <cstring>
#include "hospital.h"
#include "patient.h"
#include "date.h"

#define SIZE 150
using namespace std;

Hospital::Hospital() = default;

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
            if (strcmp(departments[i]->getName(), name) > 0) {
                return departments[i];
            }
        }
    }
    cout << " couldn't find the department you are searching for\n";
    return nullptr;
}

bool Hospital::addNewPatientVisit()
{
    bool isFirstVisit;
    Patient *patient;
    int id;
    char * visitPurpose;
    Date *today = new Date();

    cout << "Is this your first time here? 1 = yes , 0 = no";
    cin >> isFirstVisit;

    if (isFirstVisit) {
        char *name = nullptr;
        int yearOfBirth;
        int gender;
        cout << "What is your name?";
        cin >> name;

        cout << "What is your id?";
        cin >> id;

        cout << "What is your year of birth?";
        cin >> yearOfBirth;

        cout << "What is your gender? 1 = female, 0 = male";
        cin >> gender;

        patient = new Patient(name, id, yearOfBirth, (gender ? Patient::eSex::FEMALE : Patient::eSex::MALE), *today);
    }

    cout << "What is your id number?";
    cin >> id;
    cout << "Getting your documents from last visit...";
    patient = this->getPatientById(id);
    cout << "Thank you " << patient->getName();

    cout << "Whats the purpose of the visit?";
    cin >> visitPurpose;
    patient->setVisitPurpose(visitPurpose);
    // TODO add to patient the staff member incarge of him
}

/**
 * Get a patient object by it's ID.
 * Will return nullptr if not found.
 * @param id
 * @return
 */
Patient * Hospital::getPatientById(int id)
{
    if (this->sizePatients > 0) {
        for (int i = 0; i < sizePatients; i++) {
            if (patients[i]->getId() == id) {
                return patients[i];
            }
        }
    }

    return nullptr;
}


/**
 * Gets all researchers in the hospital.
 * @return
 */
Researcher** Hospital::getResearchers()
{
    return this->researchers;
}

/**
 * This method get a new researcher from the user's input.
 * Will return a pointer of the created object.
 * @return
 */
Researcher* Hospital::getNewResearcher()
{
    int id;
    char* name;

    cout << "Enter the name of the researcher: ";
    cin.getline(name, 200);

    cout << "Enter the ID of the researcher: ";
    cin >> id;

    return new Researcher(name, id);
}

/**
 * This method get a created researcher and add him to the internal researchers list.
 * Will extend the list space if needed.
 * @param newResearcher
 * @return
 */
bool Hospital::addNewResearcher(Researcher* newResearcher)
{
    if (this->indexResearchers >= this->sizeResearchers)
    {
        Researcher ** tempArr = new Researcher*[this->sizeResearchers * 2];
        for (int i = 0; i < this->indexResearchers; i++)
            tempArr[i] = this->researchers[i];

        delete [] this->researchers;
        this->researchers = tempArr;
        this->sizeResearchers *= 2;
    }
    this->researchers[this->indexResearchers++] = newResearcher;
    return true;
}

/**
 * Get a Date object from the user.
 * @return
 */
Date Hospital::getDateFromUser()
{
    char * inputDay,  * inputMonth, * inputYear;
    int day, month, year;

    cout << "Day: ";
    cin >> inputDay;
    cout << "Month: ";
    cin >> inputMonth;
    cout << "Year: ";
    cin >> inputYear;

    // Convert to int
    day = atoi(inputDay);
    month = atoi(inputMonth);
    year = atoi(inputYear);


    return Date(year, month, day);
}

/**
 * This method get a new article from the user.
 * Will return a pointer to a created article.
 * @return
 */
Article* Hospital::getNewArticle()
{
    char* name;
    char* magazine;
    Date releaseDate;

    cout << "Enter the name of the article: ";
    cin.getline(name, 200);

    cout << "Enter the name of the article: ";
    cin.getline(magazine, 200);

    cout << "Enter the release date of the article: ";
    releaseDate = getDateFromUser();

    return new Article(name, magazine, releaseDate);
}

/**
 * Add a new patient to the list of the patients in the hospital.
 * @param newPatient
 * @return
 */
bool Hospital::addNewPatient(Patient *newPatient)
{
    if (this->indexPatients >= this->sizePatients)
    {
        Patient ** tempArr = new Patient*[this->sizePatients * 2];
        for (int i = 0; i < this->indexPatients; i++)
            tempArr[i] = this->patients[i];

        delete [] this->patients;
        this->patients = tempArr;
        this->sizePatients *= 2;
    }
    this->patients[this->indexPatients++] = newPatient;
    return true;
}

/**
 * Show / Print all researchers to the output.
 */
void Hospital::showAllResearchers()
{
    cout << "Showing all researchers in the hospital: " << endl;
    for(int i = 0; i < indexResearchers; i++) {
        researchers[i]->show();
    }
}

/**
 * The main loop method of the hospital application
 */
void Hospital::runLoop()
{
    int userInput;

    do {
        cout << MENU_TEXT;
        cin >> userInput;
        switch(userInput) {
            case -1:
                break;
            case 1:
                addNewDepartment();
                break;
            case 2:
                addNewNurseToDepartment();
                break;
            case 3:
                addNewDoctorToDepartment();
                break;
            case 4:
                addNewPatientVisit();
                break;
            case 5:
                addNewResearcher(getNewResearcher());
                break;
            case 6:

                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                showAllResearchers();
                break;
            case 10:
                break;
            default:
                cout << "Command could not be found, Please try something else\n";
                break;
        }
    } while (userInput != -1);
}

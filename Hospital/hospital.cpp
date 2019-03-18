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
 * Get a new department from user input.
 * @return
 */
Department* Hospital::getNewDepartment()
{
    char name[SIZE];
    cout << "Please type the department name:\n";
    cin >> name;

    return new Department(name);
}

/**
 * Add new department to the hospital
 */
bool Hospital::addNewDepartment(Department * newDepartment)
{
    if (this->indexDepartments >= this->sizeDepartments) {
        Department **tempArr = new Department *[this->sizeDepartments + 2];
        for (int i = 0; i < this->indexDepartments; i++)
            tempArr[i] = this->departments[i];

        delete[] this->departments;
        this->departments = tempArr;
        this->sizeDepartments += 2;
    }
    this->departments[this->indexDepartments++] = newDepartment;
    return true;
}

/**
 * Get new Nurse from user input.
 */
 Nurse* Hospital::getNewNurse()
{
    int id, yearsOfExperience;
    char name[SIZE];

    cout << "Please type the nurse's ID:\n";
    cin >> id;

    cout << "Please type the nurse's name:\n";
    cin >> name;

    cout << "Please type the nurse's years of experience:\n";
    cin >> yearsOfExperience;

    return new Nurse(name, id, yearsOfExperience);
}

/**
 * Add new Nurse to a specific department
 */
bool Hospital::addNewNurseToDepartment()
{
    char departmentName[SIZE];

    cout << "Please type the department name you want to attach nurse to:\n";
    cin >> departmentName;

    Nurse *nurse = getNewNurse();
    getDepartmentByName(departmentName)->addNewNurse(nurse);
}

/**
 * Get a new doctor by user input.
 * @return
 */
Doctor* Hospital::getNewDoctor()
{
    int id = 0;
    char name[SIZE], departmentName[SIZE], interField[SIZE];

    cout << "Please type the doctor's ID:\n";
    cin >> id;

    cout << "Please type the doctor's name:\n";
    cin >> name;

    cout << "Please type the doctor's internship field:\n";
    cin >> interField;

    return new Doctor(id, name, interField);
}

/**
 * Add new Doctor to a specific department
 */
bool Hospital::addNewDoctorToDepartment()
{
    char departmentName[SIZE];

    cout << "Please type the department name you want to attach doctor to:\n";
    cin >> departmentName;

    Doctor *doctor = getNewDoctor();
    getDepartmentByName(departmentName)->addNewDoctor(doctor);
    return true;
}

Department *Hospital::getDepartmentByName(char *name)
{
    if (this->indexDepartments > 0) {
        for (int i = 0; i < this->indexDepartments; i++) {
            if (strcmp(departments[i]->getName(), name) == 0) {
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
    int id;
    Patient *patient = nullptr;
    char *requiredDepartment = nullptr;

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
    } else {
        cout << "What is your id number?";
        cin >> id;
        cout << "Getting your documents from last visit...";
        patient = this->getPatientById(id);
        cout << "Thank you " << patient->getName();
    }

    cout << "Whats the purpose of the visit?";
    cin >> requiredDepartment;

    // attaching department both to patient and to wanted department
    patient->setRequiredDepartment(requiredDepartment);
    Department *department = getDepartmentByName(requiredDepartment);
    department->addNewPatient(*patient);

    return true;

}

/**
 * Get a patient object by it's ID.
 * Will return nullptr if not found.
 * @param id
 * @return
 */
Patient *Hospital::getPatientById(int id)
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
Researcher **Hospital::getResearchers()
{
    return this->researchers;
}

/**
 * This method get a new researcher from the user's input.
 * Will return a pointer of the created object.
 * @return
 */
Researcher *Hospital::getNewResearcher()
{
    int id;
    char name[SIZE];

    cout << "Enter the name of the researcher: ";
    cin >> name;

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
bool Hospital::addNewResearcher(Researcher *newResearcher)
{
    if (this->indexResearchers >= this->sizeResearchers) {
        Researcher **tempArr = new Researcher *[this->sizeResearchers * 2];
        for (int i = 0; i < this->indexResearchers; i++)
            tempArr[i] = this->researchers[i];

        delete[] this->researchers;
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
    // Todo: add validation for input of the date numbers
    int day, month, year;

    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;

    return Date(year, month, day);
}

/**
 * This method get a new article from the user.
 * Will return a pointer to a created article.
 * @return
 */
Article *Hospital::getNewArticle()
{
    char name[SIZE], magazine[SIZE];
    Date releaseDate;

    cout << "Enter the name of the article: ";
    cin >> name;

    cout << "Enter the name of the article: ";
    cin >> magazine;

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
    if (this->indexPatients >= this->sizePatients) {
        Patient **tempArr = new Patient *[this->sizePatients * 2];
        for (int i = 0; i < this->indexPatients; i++)
            tempArr[i] = this->patients[i];

        delete[] this->patients;
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
    for (int i = 0; i < indexResearchers; i++) {
        researchers[i]->show();
    }
}

/**
 * Get ID by user input and show the patient information, if exists.
 */
void Hospital::showPatientByID()
{
    int patientId;
    Patient * foundPatient;
    cout << "What is your id number?";
    // Todo: add validation for good ID
    cin >> patientId;
    foundPatient = this->getPatientById(patientId);

    if (foundPatient == nullptr) {
        cout << "Could not find a patient with ID " << patientId;
    } else {
        foundPatient->show();
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
        switch (userInput) {
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
                showPatientByID();
                break;
            default:
                cout << "Command could not be found, Please try something else\n";
                break;
        }
    } while (userInput != -1);
}

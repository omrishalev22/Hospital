#include <string>
#include <iostream>
#include <cstring>
#include "hospital.h"
#include "patient.h"
#include "Shared/date.h"
#include "Shared/consts.h"
#include "Shared/validator.h"

using namespace std;

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
                addNewDepartment(getNewDepartment());
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
                addNewArticleToResearcher();
                break;
            case 7:
                showPatientsByDepartment();
                break;
            case 8:
                showAllHospitalStaff();
                break;
            case 9:
                showAllResearchers();
                break;
            case 10:
                showPatientByID();
                break;
            default:
                cout << "Command could not be found, Please try something else" << endl;
                break;
        }
    } while (userInput != -1);
}

Hospital::Hospital()
{
    this->departments = new Department *[AMOUNT_OF_STARTED_ITEMS];
    this->indexDepartments = 0;
    this->sizeDepartments = AMOUNT_OF_STARTED_ITEMS;

    this->patients = new Patient *[AMOUNT_OF_STARTED_ITEMS];
    this->indexPatients = 0;
    this->sizePatients = AMOUNT_OF_STARTED_ITEMS;

    this->researchers = new Researcher *[AMOUNT_OF_STARTED_ITEMS];
    this->indexResearchers = 0;
    this->sizeResearchers = AMOUNT_OF_STARTED_ITEMS;
};


/**
 * Get a new department from user input.
 * @return
 */
Department *Hospital::getNewDepartment()
{
    char name[SIZE];
    cout << "Please type the department name:" << endl;
    cin >> name;
    return new Department(name);
}

/**
 * Add new department to the hospital
 */
bool Hospital::addNewDepartment(Department *newDepartment)
{
    if (this->indexDepartments >= this->sizeDepartments) {
        Department **tempArr = new Department *[this->sizeDepartments * 2];
        for (int i = 0; i < this->indexDepartments; i++)
            tempArr[i] = this->departments[i];

        delete[] this->departments;
        this->departments = tempArr;
        this->sizeDepartments *= 2;
    }
    this->departments[this->indexDepartments++] = newDepartment;
    return true;
}

/**
 * Get new Nurse from user input.
 */
Nurse *Hospital::getNewNurse()
{
    int id, yearsOfExperience;
    char name[SIZE];

    // Todo: add validations to all fields - in terms of types we dont need to validate
    // TODO we need to validate stuff like is nurse exists in system and stuff like this. what do you think?

    cout << "Please type the nurse's ID:" << endl;
    cin >> id;

    cout << "Please type the nurse's name:" << endl;
    cin >> name;

    cout << "Please type the nurse's years of experience:" << endl;
    cin >> yearsOfExperience;

    return new Nurse(name, id, yearsOfExperience);
}

/**
 * Add new Nurse to a specific department
 */
bool Hospital::addNewNurseToDepartment()
{
    char departmentName[SIZE];

    cout << "Please type the department name you want to attach nurse to:" << endl;
    cin >> departmentName;
    Department *foundDepartment = getDepartmentByName(departmentName);

    if (foundDepartment == nullptr) {
        cout << "Could not find department: " << departmentName << endl;
        return false;
    } else {
        Nurse *nurse = getNewNurse();
        foundDepartment->addNewNurse(nurse);
        cout << "Successfully added new nurse (ID " << nurse->getID() << ") to department: " << departmentName << endl;
        return true;
    }
}

/**
 * Get a new doctor by user input.
 * @return Doctor
 */
Doctor *Hospital::getNewDoctor()
{
    int id;
    char name[SIZE], interField[SIZE];

    // Todo: add validations for all fields

    cout << "Please type the doctor's ID:" << endl;
    cin >> id;

    cout << "Please type the doctor's name:" << endl;
    cin >> name;

    cout << "Please type the doctor's internship field:" << endl;
    cin >> interField;

    return new Doctor(id, name, interField);
}

/**
 * Add new Doctor to a specific department
 */
bool Hospital::addNewDoctorToDepartment()
{
    char departmentName[SIZE];

    cout << "Please type the department name you want to attach doctor to:" << endl;
    cin >> departmentName;

    Department *foundDepartment = getDepartmentByName(departmentName);
    if (foundDepartment == nullptr) {
        cout << "Could not find department: " << departmentName << endl;
        return false;
    } else {
        Doctor *doctor = getNewDoctor();
        foundDepartment->addNewDoctor(doctor);
        cout << "Successfully added new doctor (ID " << doctor->getID() << ") to department: " << departmentName
             << endl;
        return true;
    }
}

/**
 * Get an existing department object by it's name.
 * @param name
 * @return Department
 */
Department *Hospital::getDepartmentByName(char *name)
{
    for (int i = 0; i < this->indexDepartments; i++) {
        if (strcmp(departments[i]->getName(), name) == 0) {
            return departments[i];
        }
    }
    return nullptr;
}


/**
 * Get a patient object from user input.
 * @return
 */
Patient *Hospital::getNewPatient()
{
    char name[SIZE];
    int yearOfBirth;
    int id, gender;

    // Todo: enter validations for all fields

    cout << "What is your name?" << endl;
    cin >> name;

    cout << "What is your id?" << endl;
    cin >> id;

    cout << "What is your year of birth?" << endl;
    cin >> yearOfBirth;

    cout << "What is your gender? 1 = female, 0 = male" << endl;
    cin >> gender;

    return new Patient(name, id, yearOfBirth, (gender ? Patient::eSex::FEMALE : Patient::eSex::MALE));
}

/**
 * Add a new Patient visit. Patient new or old will be attached to a department
 * and an available staff member of that department.
 * @return
 */
bool Hospital::addNewPatientVisit()
{
    bool isFirstVisit;
    int id;
    Patient *patient = nullptr;
    char requiredDepartment[SIZE];
    Department *department = nullptr;

    cout << "Is this your first time here? 1 = yes , 0 = no" << endl;
    cin >> isFirstVisit;

    // In case it's a new visit , we need to fill out patient's data
    if (isFirstVisit) {
        patient = getNewPatient();

        // Attaching the patient to a department
        cout << "What department are you looking for?" << endl;
        cin >> requiredDepartment;

        // attaching department both to patient and to wanted department
        department = getDepartmentByName(requiredDepartment);

        if (department == nullptr) {
            cout << "Could not find the department: " << requiredDepartment << endl;
            if (isFirstVisit) {
                delete patient;
            }
            return false;
        }

        patient->setDepartment(requiredDepartment);
    } else {
        // Get patient data by ID
        cout << "Enter the patient ID: " << endl;
        cin >> id;
        patient = this->getPatientById(id);
        if (patient == nullptr) {
            cout << "Could not find patient with ID " << id << ". The new visit process will stop now." << endl;
            return false;
        } else {
            cout << "Thank you " << patient->getName() << endl;
        }
    }

    // Adding a new visit to the patient
    Visit * visit = getNewVisit(patient);
    if (visit == nullptr) {
        cout << "Since there were validation issues upon the visit data, all data will not be saved at all (including the new patient information)" << endl;
        if (isFirstVisit) {
            delete patient;
        }
        return false;
    }

    // Only for new patients - adding the new patient to the right places
    if (isFirstVisit) {
        department = getDepartmentByName(requiredDepartment);
        department->addNewPatient(patient); // will automatically attach him to available staff member
        cout << "Patient " << patient->getName() << " has been added to department " << department->getName() << endl;

        this->addNewPatient(patient); // add new patient to the hospital main list of patients
        cout << "Patient " << patient->getName() << " has sucessfully added to the hospital" << endl;
    }

    // Adding new visit the patient
    patient->addNewVisit(visit);
    cout << "New visit has been added to the patient history" << endl;

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
    for (int i = 0; i < indexPatients; i++) {
        if (patients[i]->getId() == id) {
            return patients[i];
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

    cout << "Enter the name of the researcher: " << endl;
    cin >> name;

    cout << "Enter the ID of the researcher: " << endl;
    cin >> id;

    return new Researcher(name, id);
}

Visit* Hospital::getNewVisit(Patient * patient)
{
    int isNurseChosen, personInChargeID;
    char arrivalPurpose[SIZE];

    cout << "Enter the visit / arrival purpose: " << endl;
    cin >> arrivalPurpose;

    cout << "Please the arrival date of the visit:" << endl;
    Date arrivalDate = getDateFromUser();

    cout << "Does the person in charge of this current visit is a doctor or a nurse? doctor = 0, nurse = 1" << endl;
    cin >> isNurseChosen;

    cout << "Please enter the ID of the " << (isNurseChosen == 1 ? "nurse" : "doctor") << " that is in charge:" << endl;
    cin >> personInChargeID;

    // We know that the department name in the patient in valid since we created the object already after validations.
    if (isNurseChosen) {
        Nurse * inChargePerson = this->getDepartmentByName(patient->getDepartmentName())->getStaffMembers()->getNurseByID(personInChargeID);
        if (inChargePerson == nullptr) {
            cout << "Could not find nurse with ID " << personInChargeID << " in department " << patient->getDepartmentName() << endl;
            return nullptr;
        }
        return new Visit(arrivalPurpose, arrivalDate, inChargePerson);
    } else {
        Doctor * inChargePerson = this->getDepartmentByName(patient->getDepartmentName())->getStaffMembers()->getDoctorByID(personInChargeID);
        if (inChargePerson == nullptr) {
            cout << "Could not find doctor with ID " << personInChargeID << " in department " << patient->getDepartmentName() << endl;
            return nullptr;
        }
        return new Visit(arrivalPurpose, arrivalDate, inChargePerson);
    }
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

    cout << "Enter the name of the article: " << endl;
    cin >> name;

    cout << "Enter the name of the magazine the article is in: " << endl;
    cin >> magazine;

    cout << "Enter the release date of the article: " << endl;
    Date releaseDate = getDateFromUser();

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
    if (indexResearchers == 0) {
        cout << "There are no researchers in the hospital." << endl;
    } else {
        cout << "Showing all researchers in the hospital: " << endl;
        for (int i = 0; i < indexResearchers; i++) {
            researchers[i]->show();
        }
    }
}

/**
 * Get ID by user input and show the patient information, if exists.
 */
void Hospital::showPatientByID()
{
    int patientId;
    Patient *foundPatient;
    cout << "What is your id number?";
    // Todo: add validation for good ID
    cin >> patientId;
    foundPatient = this->getPatientById(patientId);

    if (foundPatient == nullptr) {
        cout << "Could not find a patient with ID " << patientId << endl;
    } else {
        foundPatient->show();
    }
}

/**
 * Shows to the user output all of the hospital staff.
 */
void Hospital::showAllHospitalStaff()
{
    for (int i = 0; i < indexDepartments; i++) {
        cout << "About to show all staff members of department: " << departments[i]->getName() << endl;
        departments[i]->getStaffMembers()->show();
    }
}

/**
 * Get a researcher object by it's ID.
 * @param id
 * @return
 */
Researcher *Hospital::getResearcherById(int id)
{
    for (int i = 0; i < indexResearchers; i++) {
        if (researchers[i]->getId() == id) {
            return researchers[i];
        }
    }

    return nullptr;
}

/**
 * Adds a new article to a specific researcher.
 * @return
 */
bool Hospital::addNewArticleToResearcher()
{
    int id;

    // Todo: add validation to user input
    cout << "Please enter researcher ID: " << endl;
    cin >> id;

    Researcher *foundResearcher = getResearcherById(id);
    if (foundResearcher == nullptr) {
        cout << "Could not find a researcher with ID: " << id << endl;
        return false;
    } else {
        foundResearcher->addNewArticle(getNewArticle());
        return true;
    }
}

/**
 * Shows to the user output the patients of a specific department.
 */
void Hospital::showPatientsByDepartment()
{
    char departmentName[SIZE];
    cout << "What is the department name?";
    // Todo: add validation for good name
    cin >> departmentName;

    Department *foundDepartment = this->getDepartmentByName(departmentName);

    if (foundDepartment == nullptr) {
        cout << "Could not find a department with name: " << departmentName << endl;
    } else {
        cout << "Showing patients for department " << foundDepartment->getName() << ":" << endl;
        foundDepartment->showPatients();
    }
}

/**
 * Free all memoery allocation when hospital is destroyed
 */
Hospital::~Hospital()
{
    if (this->researchers != nullptr) {
        for (int i = 0; i < this->indexResearchers; i++)
            delete this->researchers[i];
        delete[] this->researchers;
    }

    if (this->patients != nullptr) {
        for (int i = 0; i < this->indexPatients; i++)
            delete this->patients[i];
        delete[] this->patients;
    }

    if (this->departments != nullptr) {
        for (int i = 0; i < this->indexDepartments; i++)
            delete this->departments[i];
        delete[] this->departments;
    }
}

#include <string>
#include <iostream>
#include <cstring>
#include "hospital.h"
#include "patient.h"
#include "Shared/date.h"
#include "Shared/consts.h"
#include "Shared/validators.h"

using namespace std;
int Hospital::numOfEmployees = 0;

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

        // just to make success/error message show on the screen before jumping back to main menu
        cout << "Press any key to continue.." << endl;
        cin.ignore();
        cin.get();
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

    if (getDepartmentByName(name) != nullptr) {
        cout << "There is already an existing department with the name: " << name << endl;
        return nullptr;
    }
    return new Department(name);
}

/**
 * Add new department to the hospital
 */
bool Hospital::addNewDepartment(Department *newDepartment)
{
    if (newDepartment == nullptr)
        return false;

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
    int yearsOfExperience;
    char name[SIZE];

    // Todo: add validations to all fields - in terms of types we dont need to validate
    // TODO we need to validate stuff like is nurse exists in system and stuff like this. what do you think?

    cout << "Please type the nurse's name:" << endl;
    cin >> name;

    if (!isCharactersOnly(name)) {
        cout << "Please enter a valid name (with letters and spaces only)" << endl;
        return nullptr;
    }

    cout << "Please type the nurse's years of experience:" << endl;
    cin >> yearsOfExperience;

    if (yearsOfExperience < 0 || yearsOfExperience > 120) {
        cout << "Please enter a valid amount of experience years" << endl;
        return nullptr;
    }

    return new Nurse(name, ++numOfEmployees, yearsOfExperience);
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
    char name[SIZE], interField[SIZE];

    // Todo: add validations for all fields

    cout << "Please type the doctor's name:" << endl;
    cin >> name;

    if (!isCharactersOnly(name)) {
        cout << "Please enter a valid name (with letters and spaces only)" << endl;
        return nullptr;
    }

    cout << "Please type the doctor's internship field:" << endl;
    cin.ignore(); // to prevent left overs from previous inputs
    cin.getline(interField, SIZE); // intake entire short description

    if (!isCharactersOnly(interField)) {
        cout << "Please enter a valid intership field (with letters and spaces only)" << endl;
        return nullptr;
    }

    return new Doctor(++numOfEmployees, name, interField);
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

    if (!isCharactersOnly(name)) {
        cout << "Please enter a valid name (with letters and spaces only)" << endl;
        return nullptr;
    }

    cout << "What is your id?" << endl;
    cin >> id;


    if (!isValidID(id)) {
        cout << "Please enter a valid ID number (9 numbers)" << endl;
        return nullptr;
    }

    cout << "What is your year of birth?" << endl;
    cin >> yearOfBirth;

    if (yearOfBirth < 1920 || yearOfBirth > 2019) {
        cout << "Please enter a valid year of birth" << endl;
        return nullptr;
    }

    cout << "What is your gender? 1 = female, 0 = male" << endl;
    cin >> gender;

    if (gender != 0 && gender != 1) {
        cout << "Please enter a valid gender" << endl;
        return nullptr;
    }

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
    Department *department = nullptr;

    cout << "Is this your first time here? 1 = yes , 0 = no" << endl;
    cin >> isFirstVisit;

    // In case it's a new visit , we need to fill out patient's data
    if (isFirstVisit) {
        patient = getNewPatient();
        if (patient == nullptr) {
            return false;
        }

        department = getDepartmentByUserInput();
        if (department) {
            patient->setDepartment(department->getName());
        } else {
            delete patient;
            return false; // in case no department found, stop new visit process
        }

    } else {
        // Get patient data by ID
        cout << "Enter the patient ID: " << endl;
        // Todo do we need to validate ID?
        cin >> id;
        patient = this->getPatientById(id);
        if (patient == nullptr) {
            cout << "Could not find patient with ID " << id << ". The new visit process will stop now." << endl;
            return false;
        } else {
            cout << "Thank you " << patient->getName() << endl;

            // since patient already visited, we make sure he wants to leave current department before moving to a new one
            int isStaying;

            cout << "It seems you are already part of department '" << patient->getDepartmentName()
                 << "' do you want to make a new visit or stay in current department, 1 = Stay , 0 = Change" << endl;
            cin >> isStaying;
            if (isStaying != STAYING) {
                cout << "Releasing patient from '" << patient->getDepartmentName() << "'" << endl;
                Department * newDepartment = getDepartmentByUserInput();
                if (newDepartment) {
                    getDepartmentByName(patient->getDepartmentName())->removePatientByID(patient->getId());
                    patient->setDepartment(newDepartment->getName());
                    newDepartment->addNewPatient(patient);
                    cout << "Patient " << patient->getName() << " has been added to department " << newDepartment->getName() << endl;
                } else {
                    // in case no department found, stop new visit process
                    return false;
                }

            }
        }
    }

    // Adding a new visit to the patient
    Visit *visit = getNewVisit(patient);
    if (visit == nullptr) {
        if (isFirstVisit) {
            delete patient;
        }
        return false;
    }

    // Only new patients should be added to the hospital memory to prevent duplications
    if (isFirstVisit) {
        // add new patient to the hospital main list of patients
        this->addNewPatient(patient);
        cout << "Patient " << patient->getName() << " has sucessfully added to the hospital" << endl;
        department->addNewPatient(patient);
        cout << "Patient " << patient->getName() << " has been added to department " << department->getName() << endl;
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
 * This method get a new researcher from the user's input.
 * Will return a pointer of the created object.
 * @return
 */
Researcher *Hospital::getNewResearcher()
{
    char name[SIZE];

    cout << "Enter the name of the researcher: " << endl;
    cin >> name;

    if (!isCharactersOnly(name)) {
        cout << "The name is invalid (please specify a name with letters and spaces only)" << endl;
        return nullptr;
    }

    return new Researcher(name, ++numOfEmployees);
}

/**
 * Create a new patient's visit and insert it into system.
 * @param patient
 * @return
 */
Visit *Hospital::getNewVisit(Patient *patient)
{
    int isNurseChosen, personInChargeID;
    char arrivalPurpose[SIZE];

    cout << "Enter the visit / arrival purpose: (up to 149 characters) " << endl;
    cin.ignore(); // to prevent left overs from previous inputs
    cin.getline(arrivalPurpose, SIZE); // intake entire short description

    cout << "Please the arrival date of the visit:" << endl;
    Date arrivalDate = getDateFromUser();

    cout << "Does the person in charge of this current visit is a doctor or a nurse? doctor = 0, nurse = 1" << endl;
    cin >> isNurseChosen;

    if (isNurseChosen != 0 && isNurseChosen != 1) {
        cout << "Please enter a valid choice (1/0)" << endl;
        return nullptr;
    }

    cout << "Please enter the ID of the " << (isNurseChosen == 1 ? "nurse" : "doctor") << " that is in charge:" << endl;
    cin >> personInChargeID;

    if (!isValidID(personInChargeID)) {
        cout << "Please enter a valid ID number (9 numbers)" << endl;
        return nullptr;
    }

    // we want to make sure there are members in staff before trying to look for nurse/doctor
    // We also know that the department name in the patient is valid since we created the object already after validations
    Staff *departmentStaff = this->getDepartmentByName(patient->getDepartmentName())->getStaffMembers();
    if (isNurseChosen) {
        Nurse *inChargePerson = departmentStaff ? departmentStaff->getNurseByID(personInChargeID) : nullptr;
        if (inChargePerson == nullptr) {
            cout << "Could not find nurse with ID " << personInChargeID << " in department "
                 << patient->getDepartmentName() << endl;
            return nullptr;
        }
        return new Visit(arrivalPurpose, arrivalDate, inChargePerson);
    } else {
        Doctor *inChargePerson = departmentStaff ? departmentStaff->getDoctorByID(personInChargeID) : nullptr;
        if (inChargePerson == nullptr) {
            cout << "Could not find doctor with ID " << personInChargeID << " in department "
                 << patient->getDepartmentName() << endl;
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
    if (newResearcher == nullptr)
        return false;

    if (this->indexResearchers >= this->sizeResearchers) {
        Researcher **tempArr = new Researcher *[this->sizeResearchers * 2];
        for (int i = 0; i < this->indexResearchers; i++)
            tempArr[i] = this->researchers[i];

        delete[] this->researchers;
        this->researchers = tempArr;
        this->sizeResearchers *= 2;
    }
    this->researchers[this->indexResearchers++] = newResearcher;
    cout << "Successfully added new researcher (ID " << newResearcher->getId() << ")" << endl;
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
    cin.ignore(); // to prevent left overs from previous inputs
    cin.getline(name, SIZE);

    if (!isCharactersOnly(name)) {
        cout << "Please enter a valid article name (with letters and spaces only)" << endl;
        return nullptr;
    }

    cout << "Enter the name of the magazine the article is in: " << endl;
    cin.getline(magazine, SIZE);

    if (!isCharactersOnly(name)) {
        cout << "Please enter a valid magazine name (with letters and spaces only)" << endl;
        return nullptr;
    }

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
    if (newPatient == nullptr)
        return false;

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
        cout << "All staff members from department: " << departments[i]->getName() << endl;
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
 * Search and retrive the patient's wanted department
 * @param isFirstVisit
 * @param patient
 * @return
 */
Department *Hospital::getDepartmentByUserInput()
{
    char requiredDepartment[SIZE];
    Department *department = nullptr;

    // Attaching the patient to a department
    cout << "What department are you looking for?" << endl;
    cin >> requiredDepartment;

    // attaching department both to patient and to wanted department
    department = getDepartmentByName(requiredDepartment);

    if (department == nullptr) {
        cout << "Could not find the department: " << requiredDepartment << endl;
        return department;
    }
    return department;
}


/**
 * Free all memory allocation when hospital is destroyed
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


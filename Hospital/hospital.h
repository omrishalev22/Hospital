#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include "department.h"
#include "ResearchCenter/researcher.h"
#include "patient.h"
#include "ResearchCenter/article.h"
#include "date.h"

#define MENU_TEXT (""\
"\n Welcome to our Hospital, please choose what you wish to do: \n"\
"\n (1) Add a new department\n"\
"\n (2) Add a new nurse and attach her to a department\n"\
"\n (3) Add a new doctor and attach her to a department\n"\
"\n (4) Add a new patient visit\n"\
"\n (5) Add a new researcher to the Research center\n"\
"\n (6) Add a new article to an investigator\n"\
"\n (7) Show all patients by department name\n"\
"\n (8) Show all staff members in the system\n"\
"\n (9) Show all researchers in the Researchers center\n"\
"\n (10) Show patient details by ID\n"\
"\n or enter -1 to exit")

class Hospital
{
private:

    Department ** departments;
    int indexDepartments = 0;
    int sizeDepartments = 0;

    Patient ** patients;
    int indexPatients = 0;
    int sizePatients = 0;

    Researcher** researchers;
    int indexResearchers = 0;
    int sizeResearchers = 0;

public:

    Hospital();

    // Getters
    Researcher ** getResearchers();
    Department * getDepartmentByName(char* name);
    Patient * getPatientById(int id);
    Department * getNewDepartment();
    Researcher * getNewResearcher();
    Article * getNewArticle();
    Doctor * getNewDoctor();
    Nurse * getNewNurse();
    Patient * getNewPatient();
    Date getDateFromUser();
    void showAllResearchers();
    void showPatientByID();

    // Setters
    bool addNewDepartment(Department * newDepartment);
    bool addNewNurseToDepartment();
    bool addNewDoctorToDepartment();
    bool addNewPatientVisit();
    bool addNewPatient(Patient * newPatient);
    bool addNewResearcher(Researcher * newResearcher);

    ~Hospital();

    void runLoop();
};

#endif // __HOSPITAL_H
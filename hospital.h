#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include "department.h"
#include "ResearchCenter/researcher.h"
#include "patient.h"
#include "ResearchCenter/article.h"
#include "Shared/date.h"
#include "visit.h"
void flushBuffer();

#define MENU_TEXT (""\
"\n Welcome to our Hospital, please choose what you wish to do: \n"\
"\n (1) Add a new department\n"\
"\n (2) Add a new nurse and attach her to a department\n"\
"\n (3) Add a new doctor and attach her to a department\n"\
"\n (4) Add a new patient visit\n"\
"\n (5) Add a new researcher to the Research center\n"\
"\n (6) Add a new article to an researcher\n"\
"\n (7) Show all patients by department name\n"\
"\n (8) Show all staff members in the system\n"\
"\n (9) Show all researchers in the Researchers center\n"\
"\n (10) Show all doctor researchers in the Researchers center\n"\
"\n (11) Show patient details by ID\n"\
"\n (12) Show first department in the hospital by using 'operator<<'\n"\
"\n or enter -1 to exit\n")

class Hospital
{
private:
    static int numOfEmployees; // helps in granting employee's ID automatically

    Department ** departments;
    int indexDepartments;
    int sizeDepartments;

    Patient ** patients;
    int indexPatients;
    int sizePatients;

    Researcher** researchers;
    int indexResearchers;
    int sizeResearchers;

public:

    Hospital();

    // Getters
    Researcher ** getResearchers();
    Department * getDepartmentByName(char* name);
    Patient * getPatientById(int id);
    Researcher * getResearcherById(int id);

    Department * getNewDepartment();
    Researcher * getNewResearcher();
    Article * getNewArticle();
    Doctor * getNewDoctor();
    Nurse * getNewNurse();
    Patient * getNewPatient();
    Date getDateFromUser();
    Visit * getNewVisit(Patient * patient);
    Department *getDepartmentByUserInput();

    void showAllResearchers();
	void showAllDoctorResearchers();
    void showPatientByID();
    void showAllHospitalStaff();
    void showPatientsByDepartment();

    // Setters
    bool addNewDepartment(Department * newDepartment);
    bool addNewPatient(Patient * newPatient);
    bool addNewResearcher(Researcher * newResearcher);
    bool addNewNurseToDepartment();
    bool addNewDoctorToDepartment();
    bool addNewPatientVisit();
    bool addNewArticleToResearcher();

    ~Hospital();

    void runLoop();
};

#endif // __HOSPITAL_H
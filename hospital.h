#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include "department.h"
#include "ResearchCenter/researcher.h"
#include "patient.h"
#include "ResearchCenter/article.h"
#include "Shared/date.h"
#include "visit.h"
#include "surgery_visit.h"
#include <vector>
#include <string>
#include "entityGenerator.h"

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

	vector<Department *> departments;
	vector<Patient * > patients;
	vector<Researcher *> researchers;

public:

    // Getters
	Department * getDepartmentByName(const string& name);
	Patient * getPatientById(int id);
	Researcher * getResearcherById(int id);
    Department * getNewDepartment() throw (const char *);
    Researcher * getNewResearcher() throw (const char *);
    Article * getNewArticle() throw (const char *);
    Doctor * getNewDoctor() throw (const char *);
    Nurse * getNewNurse() throw (const char *);
    Patient * getNewPatient() throw (const char *);
    Date getDateFromUser() throw (const char *);
    Visit * getNewVisit(Patient * patient) throw (const char *);
    Department *getDepartmentByUserInput() throw (const char *);

    void showAllResearchers();
	void showAllDoctorResearchers();
    void showPatientByID();
    void showAllHospitalStaff();
    void showPatientsByDepartment();

    // Setters
    bool addNewDepartment(Department * newDepartment);
    bool addNewPatient(Patient * newPatient);
    bool addNewResearcher(Researcher * newResearcher);
	bool addNewNurseToDepartment() throw (const char *);
	bool addNewDoctorToDepartment() throw (const char *);
	bool addNewPatientVisit() throw (const char *);
    bool addNewArticleToResearcher();
	
	void loadFile();
	void saveFile();
    void runLoop();
};

#endif // __HOSPITAL_H
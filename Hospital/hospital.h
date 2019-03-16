#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include "department.h"
#include "research_center.h"
#include "patient.h"

class Hospital
{
private:

    Department departments[20]; // TODO dynamic
    ResearchCenter researchCenter;
    Patient patients[20];

public:

    Hospital();

    // Getters
    Department getDepartmentByName(char* name);
    bool isPatientExists(int id);

    // Setters
    bool addNewDepartment();
    bool addNewNurseToDepartment();
    bool addDoctor();
    bool addPatient();
    bool addVisit();

};

#endif // __HOSPITAL_H
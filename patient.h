#include "Shared/date.h"
#include "visit.h"
#include "person.h"
#include <vector>

#ifndef __PATIENT_H
#define __PATIENT_H

class Patient : public Person
{
public:
    enum eSex
    {
        MALE, FEMALE
    };
	
    Patient(const Patient& patient);
    Patient(int id, const string& name, int yearOfBirth, eSex sex);
	Patient(ifstream& inFile);
	void save(ofstream& outFile) const;

    // GETTERS
    void show();
    eSex getESex();
    const string& getDepartmentName();

    // SETTERS
    bool setDepartment(const string& departmentName);
    bool addNewVisit(Visit * visit);

    ~Patient();
private:
    int yearOfBirth;
    std::string departmentName;
    eSex sex;
    vector<Entity *> visits;
};

#endif //__PATIENT_H

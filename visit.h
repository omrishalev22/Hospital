#ifndef __VISIT_H
#define __VISIT_H

#include "Shared/date.h"
#include "Staff/staff.h"
#include "Staff/Type/nurse.h"
#include "person.h"
#include <string>

using namespace std;

class Visit
{
public:

    Visit(const string& arrivalPurpose, Date &arrivalDate, Person * personInCharge);

    // GETTERS
    virtual void show();

    // SETTERS
    bool setArrivalPurpose(const std::string& arrivalPurpose);

    ~Visit();
private:
    Date arrivalDate;
    string arrivalPurpose;
	Person * personInCharge;


};

#endif //__VISIT_H

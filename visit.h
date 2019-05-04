#ifndef __VISIT_H
#define __VISIT_H

#include "Shared/date.h"
#include "Staff/staff.h"
#include "Staff/Type/nurse.h"
#include "person.h"

class Visit
{
public:

    Visit(char * arrivalPurpose, Date &arrivalDate, Person * personInCharge);

    // GETTERS
    virtual void show();

    // SETTERS
    bool setArrivalPurpose(char * arrivalPurpose);

    ~Visit();
private:
    Date arrivalDate;
    char *arrivalPurpose;
	Person * personInCharge;


};

#endif //__VISIT_H

#include "Shared/date.h"
#include "Staff/staff.h"


#ifndef __VISIT_H
#define __VISIT_H

class Visit
{
public:

    Visit(char * arrivalPurpose, Date &arrivalDate, Doctor * doctorInCharge);
    Visit(char * arrivalPurpose, Date &arrivalDate, Nurse * nurseInCharge);

    // GETTERS
    void show();

    // SETTERS
    bool setArrivalPurpose(char * arrivalPurpose);

    ~Visit();
private:
    Date arrivalDate;
    char *arrivalPurpose;
    Doctor * doctorInCharge;
    Nurse * nurseInCharge;


};

#endif //__VISIT_H

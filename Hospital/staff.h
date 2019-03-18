
#ifndef __STAFF_H
#define __STAFF_H

#include "Staff-Members/doctor.h"
#include "Staff-Members/nurse.h"

class Staff {
private :
    Nurse ** nurses;
    Doctor ** doctors;

    int indexDoctors = 0,sizeDoctors = 0;
    int indexNurses = 0,sizeNurses = 0;

public:
    // Setters
    bool addNewNurse(Nurse * nurse);
    bool addNewDoctor(Doctor * doctor);
    ~Staff();
};

#endif //__STAFF_H

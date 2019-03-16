
#ifndef __STAFF_H
#define __STAFF_H

#include "Staff-Members/doctor.h"
#include "Staff-Members/nurse.h"

class Staff {
private :
    Nurse ** nurses;
    Doctor ** doctors;

    int indexDoctors,sizeDoctors;
    int indexNurses,sizeNurses;

public:
    // Setters
    bool addNewNurse(Nurse * nurse);
    bool addNewDoctor(Doctor * doctor);
    ~Staff();
};

#endif //__STAFF_H

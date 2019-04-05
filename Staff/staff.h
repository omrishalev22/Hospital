
#ifndef __STAFF_H
#define __STAFF_H

#include "Type/doctor.h"
#include "Type/nurse.h"

class Staff {
private :
    Nurse ** nurses;
    Doctor ** doctors;

    int indexDoctors, sizeDoctors;
    int indexNurses, sizeNurses;

public:
    // Getters
    Staff();
    void show();
    Nurse * getNurseByID(int id);
    Doctor * getDoctorByID(int id);

    // Setters
    bool addNewNurse(Nurse * nurse);
    bool addNewDoctor(Doctor * doctor);
    ~Staff();
};

#endif //__STAFF_H

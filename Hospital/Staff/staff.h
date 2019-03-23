
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
    int getNumberOfDoctors();
    int getNumberOfNurses();
    Nurse * getNurseByIndex(int index);
    Doctor * getDoctorByIndex(int index);

    // Setters
    bool addNewNurse(Nurse * nurse);
    bool addNewDoctor(Doctor * doctor);
    ~Staff();
};

#endif //__STAFF_H

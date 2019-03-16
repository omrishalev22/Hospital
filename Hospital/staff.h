
#ifndef __STAFF_H
#define __STAFF_H

#include "Staff-Members/doctor.h"
#include "Staff-Members/nurse.h"

class Staff {
private :
    Doctor * doctors;
    Nurse * nurses;
    int numOfDoctors;
    int numOfNurses;
public:
    Staff(){
        numOfDoctors = 0;
        numOfNurses = 0;
        // TODO wait for keren answer on vector - bad practice
        nurses = new Nurse[20];
        doctors = new Doctor[20];
    }
    ~Staff();
    bool addNewNurse(Nurse nurse);
    bool addNewDoctor(Doctor doctor);

};

#endif //__STAFF_H


#ifndef __STAFF_H
#define __STAFF_H

#include "Staff-Members/doctor.h"
#include "Staff-Members/nurse.h"

class Staff {
private :
    Doctor * doctors;
    Nurse * nurses;
    int size;
public:
    Staff(int size = 0){}
    ~Staff();
    bool addNewNurse(Nurse nurse);
    bool addNewDoctor(Doctor doctor);

};

#endif //__STAFF_H

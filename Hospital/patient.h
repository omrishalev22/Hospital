

#ifndef __PATIENT_H
#define __PATIENT_H

class Patient {
    enum eSex { MALE, FEMALE };

private:
    char * name;
    int id;
    int yearOfBirth;
    eSex sex;

public:
    Patient(){};
    Patient(char * name,int id, int yearOfBirth, eSex sex);
};
#endif //__PATIENT_H



#ifndef __PATIENT_H
#define __PATIENT_H

class Patient {
private:
    char * name;
    int id;
    int yearOfBirth;
    eSex sex;

public:
    enum eSex { MALE, FEMALE };
    Patient(char * name,int id, int yearOfBirth, eSex sex);
};
#endif //__PATIENT_H

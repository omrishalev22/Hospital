

#ifndef __NURSE_H
#define __NURSE_H

class Nurse {
private:
    char * name;
    int id;
    int yearsOfExperience;
public :
    Nurse(){}; // TODO not safe should not init witout params - did to create new Nurse in staff.cpp
    Nurse(char * name,int id, int yearsOfExperience);
};
#endif //__NURSE_H

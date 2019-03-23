

#ifndef __NURSE_H
#define __NURSE_H

class Nurse {
private:
    char * name;
    int id;
    int yearsOfExperience;
public :
    Nurse(char * name,int id, int yearsOfExperience);
    int getID();
    void show();

};
#endif //__NURSE_H

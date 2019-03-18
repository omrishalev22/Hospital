//
// Created by shalevo on 3/16/19.
//

#ifndef __DOCTOR_H
#define __DOCTOR_H

class Doctor {
private:
    char *name;
    int id;
    char *interField;
public:
    Doctor(int id, char *name, char *interField);
    int getID();
    void show();
};

#endif //__DOCTOR_H

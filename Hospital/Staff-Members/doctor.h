//
// Created by shalevo on 3/16/19.
//

#ifndef __DOCTOR_H
#define __DOCTOR_H

class Doctor {
private:
    char * name;
    int id;
    char * interField;
public:
    Doctor(){}; // TODO wait for keren answer on vector
    Doctor(int id, char * name, char * interField);

    const char * getName();
    bool * setName();
};
#endif //__DOCTOR_H

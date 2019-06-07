//
// Created by shalevo on 3/16/19.
//

#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "../../person.h"

class Doctor : public Person {
protected:
	string internField;
public:
	Doctor(int id, string name, string interField);
	void show();
};

#endif //__DOCTOR_H

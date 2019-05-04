//
// Created by shalevo on 3/16/19.
//

#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "../../person.h"

class Doctor : public Person {
protected:
	char *internField;
public:
	Doctor(int id, char *name, char *interField);
	void show();
};

#endif //__DOCTOR_H

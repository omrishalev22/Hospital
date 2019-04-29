

#ifndef __NURSE_H
#define __NURSE_H

#include "../../person.h"

class Nurse : public Person {
private:
	int yearsOfExperience;
public:
	Nurse(int id, char * name, int yearsOfExperience);
	void show();

};
#endif //__NURSE_H

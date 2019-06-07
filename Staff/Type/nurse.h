

#ifndef __NURSE_H
#define __NURSE_H

#include "../../person.h"

class Nurse : public Person {
private:
	int yearsOfExperience;
public:
	Nurse(int id, const string& name, int yearsOfExperience);
	void show();

};
#endif //__NURSE_H

#ifndef __DOCTOR_SURGENT_H
#define __DOCTOR_SURGENT_H

#include "doctor.h"

class Surgent : public Doctor {
private:
	int numOfOperations;
public:
	Surgent(const Doctor& doctor, int numOfOperations);
	int getNumOfOperations();
	bool setNumOfOperations();
};

#endif //__DOCTOR_SURGENT_H

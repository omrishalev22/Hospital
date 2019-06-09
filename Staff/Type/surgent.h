#ifndef __DOCTOR_SURGENT_H
#define __DOCTOR_SURGENT_H

#include "doctor.h"

class Surgent : public Doctor {
private:
	int numOfOperations;
public:
	Surgent(const Doctor& doctor, int numOfOperations);
	Surgent(ifstream& inFile);
	void save(ofstream& outFile) const;

	int getNumOfOperations();
	bool setNumOfOperations();
};

#endif //__DOCTOR_SURGENT_H

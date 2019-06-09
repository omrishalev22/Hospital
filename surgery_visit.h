#ifndef __SURGERY_VISIT_H
#define __SURGERY_VISIT_H

#include "visit.h"

class SurgeryVisit : public Visit
{
public:
	SurgeryVisit(const string& arrivalPurpose, Date &arrivalDate, Person * personInCharge, int roomNumber, bool isFeasting);
	SurgeryVisit(ifstream& inFile);
	void save(ofstream& outFile) const;
	void show();

private:
	int roomNumber;
	bool isFeasting;
};

#endif //__SURGERY_VISIT_H

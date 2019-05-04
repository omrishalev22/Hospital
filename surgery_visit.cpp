#include "surgery_visit.h"

SurgeryVisit::SurgeryVisit(char * arrivalPurpose, Date &arrivalDate, Person * personInCharge, int roomNumber, bool isFeasting) : Visit(arrivalPurpose, arrivalDate, personInCharge)
{
	this->roomNumber = roomNumber;
	this->isFeasting = isFeasting;
}

void SurgeryVisit::show()
{
	this->Visit::show();
	cout << "        Surgery room number: " << roomNumber << endl;
	cout << "        Is feasting: " << (isFeasting ? "true" : "false") << endl;
}
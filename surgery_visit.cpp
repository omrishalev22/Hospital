#include "surgery_visit.h"

SurgeryVisit::SurgeryVisit(const string& arrivalPurpose, Date &arrivalDate, Person * personInCharge, int roomNumber, bool isFeasting) : Visit(arrivalPurpose, arrivalDate, personInCharge)
{
	this->roomNumber = roomNumber;
	this->isFeasting = isFeasting;
}

SurgeryVisit::SurgeryVisit(ifstream& inFile) : Visit(inFile)
{
	inFile.read((char *)&roomNumber, sizeof(roomNumber));
	inFile.read((char *)&isFeasting, sizeof(isFeasting));
}

void SurgeryVisit::save(ofstream& outFile) const
{
	Visit::save(outFile);
	outFile.write((const char *)&roomNumber, sizeof(roomNumber));
	outFile.write((const char *)&isFeasting, sizeof(isFeasting));
}

void SurgeryVisit::show()
{
	this->Visit::show();
	cout << "        Surgery room number: " << roomNumber << endl;
	cout << "        Is feasting: " << (isFeasting ? "true" : "false") << endl;
}
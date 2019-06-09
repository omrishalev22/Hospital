#include "Shared/date.h"
#include "visit.h"
#include <cstring>
#include <iostream>

using namespace std;

Visit::Visit(const string& arrivalPurpose, Date &arrivalDate, Person * personInCharge)
{
    this->setArrivalPurpose(arrivalPurpose);
    this->arrivalDate = Date(arrivalDate);
    this->personInCharge = personInCharge->getName();
}

Visit::Visit(ifstream& inFile)
{
	getline(inFile, arrivalPurpose);
	this->arrivalDate = Date::loadDate(inFile);
	getline(inFile, personInCharge);
}

void Visit::save(ofstream& outFile) const
{
	outFile << arrivalPurpose << endl;
	arrivalDate.save(outFile);
	outFile << personInCharge << endl;
}

/*
 * Set visit arrival purpose
 */
bool Visit::setArrivalPurpose(const std::string& arrivalPurpose)
{
    this->arrivalPurpose = arrivalPurpose;
    return true;
}

/*
 * Print to output all the details on current visit
 */
void Visit::show()
{
    cout << "       [" << typeid(*this).name() + 6 << "]" << endl;
    cout << "        Arrival purpose: " << this->arrivalPurpose << endl;
    cout << "        Arrival date: " << arrivalDate << endl;
	cout << "        Staff member in charge: " << this->personInCharge << endl;
}

Visit::~Visit()
{
}
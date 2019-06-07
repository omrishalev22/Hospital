#include "Shared/date.h"
#include "Staff/staff.h"
#include "visit.h"
#include <cstring>
#include <iostream>

using namespace std;

Visit::Visit(const string& arrivalPurpose, Date &arrivalDate, Person * personInCharge)
{
    this->setArrivalPurpose(arrivalPurpose);
    this->arrivalDate = Date(arrivalDate);
    this->personInCharge = personInCharge;
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
	cout << "        " << typeid(*personInCharge).name() + 6 << " in charge ID: " << this->personInCharge->getID() << endl;
}

Visit::~Visit()
{
    delete this->personInCharge;
}
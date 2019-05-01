#include "Shared/date.h"
#include "Staff/staff.h"
#include "visit.h"
#include <cstring>
#include <iostream>

using namespace std;

Visit::Visit(char *arrivalPurpose, Date &arrivalDate, Person * personInCharge)
{
    this->setArrivalPurpose(arrivalPurpose);
    this->arrivalDate = Date(arrivalDate);
    this->personInCharge = personInCharge;
}

/*
 * Set visit arrival purpose
 */
bool Visit::setArrivalPurpose(char *arrivalPurpose)
{
    this->arrivalPurpose = new char[strlen(arrivalPurpose) + 1];
    this->arrivalPurpose = strcpy(this->arrivalPurpose, arrivalPurpose);
    return true;
}

/*
 * Print to output all the details on current visit
 */
void Visit::show()
{
    cout << "        [Visit]" << endl;
    cout << "        Arrival purpose: " << this->arrivalPurpose << endl;
    cout << "        Arrival date: ";
    this->arrivalDate.show();
    cout << endl;
	cout << "        " << typeid(*personInCharge).name() + 6 << " in charge ID: " << this->personInCharge->getID() << endl;
    cout << endl;
}

Visit::~Visit()
{
    delete[] this->arrivalPurpose;
    delete this->personInCharge;
}
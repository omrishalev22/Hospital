#include "Shared/date.h"
#include "Staff/staff.h"
#include "visit.h"
#include <cstring>
#include <iostream>

using namespace std;

Visit::Visit(char *arrivalPurpose, Date &arrivalDate, Nurse *nurseInCharge)
{
    this->setArrivalPurpose(arrivalPurpose);
    this->arrivalDate = Date(arrivalDate);
    this->nurseInCharge = nurseInCharge;
    this->doctorInCharge = nullptr;
}

Visit::Visit(char *arrivalPurpose, Date &arrivalDate, Doctor *doctorInCharge)
{
    this->setArrivalPurpose(arrivalPurpose);
    this->arrivalDate = Date(arrivalDate);
    this->doctorInCharge = doctorInCharge;
    this->nurseInCharge = nullptr;
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

    if (this->doctorInCharge == nullptr) {
        cout << "        Nurse in charge ID: " << this->nurseInCharge->getID() << endl;
    } else {
        cout << "        Doctor in charge ID: " << this->doctorInCharge->getID() << endl;
    }
    cout << endl;
}

Visit::~Visit()
{
    delete[] this->arrivalPurpose;
    delete this->nurseInCharge;
    delete this->doctorInCharge;
}
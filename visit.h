#ifndef __VISIT_H
#define __VISIT_H
#include "entity.h"
#include "Shared/date.h"
#include "Staff/Type/nurse.h"
#include "person.h"
#include <string>

using namespace std;

class Visit : public Entity
{
public:

    Visit(const string& arrivalPurpose, Date &arrivalDate, Person * personInCharge);
	Visit(ifstream& inFile);

    // GETTERS
    virtual void show();

    // SETTERS
    bool setArrivalPurpose(const std::string& arrivalPurpose);
	void save(ofstream& outFile) const;
    ~Visit();
private:
    Date arrivalDate;
    string arrivalPurpose;
	string personInCharge;


};

#endif //__VISIT_H

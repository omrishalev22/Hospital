
#ifndef __STAFF_H
#define __STAFF_H

#include "../person.h"
#include "../Shared/Array.h"

class Staff {
private :
	Array<Person*> members;
    
public:
    // Getters
	bool isEmpty();
    void show();
	Person * getStaffMemberByID(int id);

    // Setters
	bool addNewStaffMember(Person * member);

};

#endif //__STAFF_H

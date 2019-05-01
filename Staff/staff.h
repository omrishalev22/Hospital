
#ifndef __STAFF_H
#define __STAFF_H

#include "../person.h"

class Staff {
private :
	Person ** members;
	int indexMembers, sizeMembers;
    
public:
    // Getters
    Staff();
    void show();
	Person * getStaffMemberByID(int id);

    // Setters
	bool addNewStaffMember(Person * member);

    ~Staff();
};

#endif //__STAFF_H

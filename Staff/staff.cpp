#include <string>
#include <iostream>
#include "staff.h"
#include "../Shared/consts.h"

using namespace std;

bool Staff::isEmpty()
{
	return this->members.getSize() == 0;
}

void Staff::show()
{
    int i;
    cout << "Showing all staff members:" << endl;
	if (members.getSize() == 0) {
		cout << "There are no staff members in the specific department." << endl;
	}
	else {
		for (i = 0; i < members.getSize(); i++) {
			members[i]->show();
		}
	}
}

bool Staff::addNewStaffMember(Person * member)
{
	this->members += member;
	return true;
}

Person * Staff::getStaffMemberByID(int id)
{
	for (int i = 0; i < members.getSize(); i++) {
		if (members[i]->getID() == id) {
			return members[i];
		}
	}

	return nullptr;
}

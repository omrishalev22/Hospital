#include <string>
#include <iostream>
#include "staff.h"
#include "../Shared/consts.h"

using namespace std;

bool Staff::isEmpty()
{
	return this->members.size() == 0;
}

void Staff::show()
{
    int i;
    cout << "Showing all staff members:" << endl;
	if (this->members.size() == 0) {
		cout << "There are no staff members in the specific department." << endl;
	}
	else {
		for (i = 0; i < members.size(); i++) {
			members[i]->show();
		}
	}
}

bool Staff::addNewStaffMember(Person * member)
{
	this->members.push_back(member);
	return true;
}

Person * Staff::getStaffMemberByID(int id)
{
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->getID() == id) {
			return members[i];
		}
	}

	return nullptr;
}

#include <string>
#include <iostream>
#include "staff.h"
#include "../Shared/consts.h"

using namespace std;

Staff::Staff()
{
	this->members = new Person *[AMOUNT_OF_STARTED_ITEMS];
	this->indexMembers = 0;
	this->sizeMembers = AMOUNT_OF_STARTED_ITEMS;
}

bool Staff::isEmpty()
{
	return this->indexMembers == 0;
}

void Staff::show()
{
    int i;
    cout << "Showing all staff members:" << endl;
	if (indexMembers == 0) {
		cout << "There are no staff members in the specific department." << endl;
	}
	else {
		for (i = 0; i < indexMembers; i++) {
			members[i]->show();
		}
	}
}

bool Staff::addNewStaffMember(Person * member)
{
	if (member == nullptr)
		return false;

	if (this->indexMembers >= this->sizeMembers) {
		Person **tempArr = new Person *[this->sizeMembers * 2];
		for (int i = 0; i < this->indexMembers; i++)
			tempArr[i] = this->members[i];

		delete[] this->members;
		this->members = tempArr;
		this->sizeMembers *= 2;
	}
	this->members[this->indexMembers++] = member;
	return true;
}

Person * Staff::getStaffMemberByID(int id)
{
	for (int i = 0; i < indexMembers; i++) {
		if (members[i]->getID() == id) {
			return members[i];
		}
	}

	return nullptr;
}

Staff::~Staff()
{
	if (this->members != nullptr) {
		for (int i = 0; i < this->indexMembers; i++)
			delete this->members[i];
		delete[] this->members;
	}
}
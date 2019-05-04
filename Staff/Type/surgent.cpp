#include "surgent.h"


Surgent::Surgent(const Doctor& doctor, int numOfOperations): Doctor(doctor)
{
	this->numOfOperations = numOfOperations;
}

int Surgent::getNumOfOperations()
{
	return 0;
}

bool Surgent::setNumOfOperations()
{
	return false;
}

#include "surgent.h"


Surgent::Surgent(const Doctor& doctor, int numOfOperations): Doctor(doctor)
{
	this->numOfOperations = numOfOperations;
}

Surgent::Surgent(ifstream& inFile) : Doctor(inFile)
{
	inFile.read((char *)&numOfOperations, sizeof(numOfOperations));
}

void Surgent::save(ofstream& outFile) const
{
	Doctor::save(outFile);
	outFile.write((const char *)&numOfOperations, sizeof(numOfOperations));
}

int Surgent::getNumOfOperations()
{
	return 0;
}

bool Surgent::setNumOfOperations()
{
	return false;
}

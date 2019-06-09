#ifndef __ENTITY_H
#define __ENTITY_H
#include "entityGenerator.h"
#include <fstream>

using namespace std;

class Entity {
public:
	Entity() {};
	Entity(ifstream& inFile);
	void saveType(ofstream& outFile) const;
	virtual void save(ofstream& outFile) const = 0;
	virtual void show() {};
};

#endif //__ENTITYGENERATOR_H

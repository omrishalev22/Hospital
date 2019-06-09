#ifndef __ENTITYGENERATOR_H
#define __ENTITYGENERATOR_H
#include <fstream>

using namespace std;

class Entity;

class EntityGenerator {
public:
	enum EntityType { UNKNOWN, DEPARTMENT, DOCTOR, NURSE, SURGENT, RESEARCHER, ARTICLE, PATIENT, VISIT, SURGERY_VISIT};
	static Entity * loadEntity(ifstream& inFile);
	static EntityType getType(const Entity * e);
};

#endif //__ENTITYGENERATOR_H

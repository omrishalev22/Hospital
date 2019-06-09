#include "entity.h"

Entity::Entity(ifstream& inFile)
{

}

void Entity::saveType(ofstream& outFile) const
{
	EntityGenerator::EntityType type = EntityGenerator::getType(this);
	outFile.write((const char*)&type, sizeof(EntityGenerator::EntityType));
}


#include "entityGenerator.h"
#include "patient.h"
#include "visit.h"
#include "surgery_visit.h"
#include "department.h"
#include "Staff\Type\doctor.h"
#include "Staff\Type\nurse.h"
#include "Staff\Type\surgent.h"
#include "ResearchCenter\article.h"
#include "ResearchCenter\researcher.h"

Entity * EntityGenerator::loadEntity(ifstream& inFile)
{
	EntityType type;
	inFile.read((char*)&type, sizeof(int));
	if (type == PATIENT) {
		return new Patient(inFile);
	}
	else if (type == VISIT) {
		return new Visit(inFile);
	}
	else if (type == SURGERY_VISIT) {
		return new SurgeryVisit(inFile);
	}
	else if (type == DEPARTMENT) {
		return new Department(inFile);
	}
	else if (type == DOCTOR) {
		return new Doctor(inFile);
	}
	else if (type == NURSE) {
		return new Nurse(inFile);
	}
	else if (type == SURGENT) {
		return new Surgent(inFile);
	}
	else if (type == ARTICLE) {
		return new Article(inFile);
	}
	else if (type == RESEARCHER) {
		return new Researcher(inFile);
	}
	else {
		return NULL;
	}
}

EntityGenerator::EntityType EntityGenerator::getType(const Entity * e)
{
	if (typeid(*e) == typeid(Patient)) {
		return EntityType::PATIENT;
	}
	else if (typeid(*e) == typeid(Researcher)) {
		return EntityType::RESEARCHER;
	}
	else if (typeid(*e) == typeid(SurgeryVisit)) {
		return EntityType::SURGERY_VISIT;
	}
	else if (typeid(*e) == typeid(Visit)) {
		return EntityType::VISIT;
	}
	else if (typeid(*e) == typeid(Department)) {
		return EntityType::DEPARTMENT;
	}
	else if (typeid(*e) == typeid(Surgent)) {
		return EntityType::SURGENT;
	}
	else if (typeid(*e) == typeid(Doctor)) {
		return EntityType::DOCTOR;
	}
	else if (typeid(*e) == typeid(Nurse)) {
		return EntityType::NURSE;
	}
	else if (typeid(*e) == typeid(Article)) {
		return EntityType::ARTICLE;
	}
	else {
		return EntityType::UNKNOWN;
	}
}
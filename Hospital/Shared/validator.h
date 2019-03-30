#ifndef _VALIDATOR_H
#define _VALIDATOR_H
#include "../patient.h"

bool isCharactersOnly(char *input, unsigned int length);
bool isPatientWillingToChangeDepartment(Patient *patient);
bool isValidDate(Date date);

#endif //_VALIDATOR_H

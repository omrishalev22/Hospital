#ifndef _VALIDATOR_H
#define _VALIDATOR_H

#include "../patient.h"

class Validator
{
public:
    bool isCharactersOnly(char *string, unsigned int length);
    bool isPatientWillingToChangeDepartment(Patient * patient);
};

#endif //_VALIDATOR_H

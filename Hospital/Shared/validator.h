#ifndef _VALIDATOR_H
#define _VALIDATOR_H
#include "../patient.h"

bool isCharactersOnly(char *input, unsigned int length);
bool isValidDate(Date date);
bool isValidYear(int year);

#endif //_VALIDATOR_H

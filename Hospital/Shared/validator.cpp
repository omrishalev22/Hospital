#include <string>
#include <iostream>
#include "validator.h"

using namespace std;

bool Validator::isCharactersOnly(char *input, unsigned int length)
{
    for (int i = 0; i < length; i++) {
        int uppercaseChar = toupper(input[i]); //Convert character to upper case
        if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
            return false;
    }

    return true;

}

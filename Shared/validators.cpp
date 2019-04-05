#include "validators.h"
#include <ctype.h>
#include <cstring>

/*
 * Check string contains only characters - no numeric values
 */
bool isCharactersOnly(char * text) {
    for (int i = 0; i < (int)strlen(text); i++) {
        if (!((isalpha(text[i]))|| (text[i]=='.') || (isspace(text[i])))) {
            return false;
        }
    }

    return true;
}

/*
 * Check id range is valid
 */
bool isValidID(int id) {
    return !(id < 100000000 || id > 999999999);
}

/*
 * Validates date
 */
bool isValidDate(Date date) {
    int day = date.getDay();
    int month = date.getMonth();
    int year = date.getYear();

    return !(day < 1 || day > 31 || month < 1 || month > 31 || year < 1900);
}
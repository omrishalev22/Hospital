#include "validators.h"
#include "consts.h"
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
    return !(id < MIN_ID || id > MAX_ID);
}

/*
 * Validates date
 */
bool isValidDate(Date date) {
    int day = date.getDay();
    int month = date.getMonth();
    int year = date.getYear();

    return !(day < MIN_DAY || day > MAX_DAY || month < MIN_MONTH || month > MAX_MONTH || year < MIN_YEAR);
}
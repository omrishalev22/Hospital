#include "validators.h"
#include "consts.h"
#include <ctype.h>
#include <cstring>

/*
 * Check string contains only characters - no numeric values
 */
bool isCharactersOnly(const string& text) {
    for (char c : text) {
        if (!((isalpha(c))|| (c=='.') || (isspace(c)))) {
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
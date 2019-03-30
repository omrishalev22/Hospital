#include "validators.h"
#include <ctype.h>
#include <cstring>

bool isCharactersOnly(char * text) {
    for (int i = 0; i < strlen(text); i++) {
        if (!((isalpha(text[i]))|| (text[i]=='.') || (isspace(text[i])))) {
            return false;
        }
    }

    return true;
}

bool isValidID(int id) {
    return !(id < 100000000 || id > 999999999);
}

bool isValidDate(Date date) {
    int day = date.getDay();
    int month = date.getMonth();
    int year = date.getYear();

    return !(day < 1 || day > 31 || month < 1 || month > 31 || year < 1900);
}
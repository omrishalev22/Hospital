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
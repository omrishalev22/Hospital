#include "doctor.h"
#include <string>
#include <iostream>

using namespace std;

Doctor::Doctor(int id, char *name, char *interField) {
        this-> id = id;
        this-> name = name;
        this-> interField = interField;
}

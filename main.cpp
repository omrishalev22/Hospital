#include <iostream>
#include "Hospital/hospital.h"

#define SIZE 150
using namespace std;

int main() {
    Hospital * hospital = new Hospital();
    hospital->runLoop();
    return 0;
}

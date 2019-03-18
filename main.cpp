#include "Hospital/hospital.h"

int main() {
    // Create new hospital, and run the menu loop
    Hospital * hospital = new Hospital();
    hospital->runLoop();
    return 0;
}

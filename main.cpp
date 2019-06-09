#include "hospital.h"

int main() {
    // Create new hospital, and run the menu loop
    Hospital * hospital = new Hospital();
	hospital->loadFile();
    hospital->runLoop();
	hospital->saveFile();
    return 0;
}

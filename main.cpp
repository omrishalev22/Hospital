#include <iostream>
#include "Hospital/department.h"
#include "Hospital/hospital.h"

#define SIZE 150
using namespace std;

void Dispatcher(int command);


Hospital * hospital = new Hospital();

int main() {
    int userInput;

    do {
        cout << "Welcome to our Hospital, please choose what you wish to do:\n";
        cout << "(1) Add a new department\n";
        cout << "(2) Add a new nurse and attach her to a department\n";
        cout << "(3) Add a new doctor and attach her to a department\n";
        cout << "(4) Add a new patient visit\n";
        cout << "(5) Add a new researcher to the Research center\n";
        cout << "(6) Add a new article to an investigator\n";
        cout << "(7) Show all patients by department name\n";
        cout << "(8) Show all staff members in the system\n";
        cout << "(9) Show all researchers in the Researchers center\n";
        cout << "(10) Show patient details by ID\n";
        cout << "or enter -1 to exit\n";
        cin >> userInput;
        if(userInput != -1) Dispatcher(userInput);
    } while (userInput != -1);

    return 0;
}


void Dispatcher(int command) {
    switch(command) {
        case 1:
            hospital->addNewDepartment();
            break;
        case 2:
            hospital->addNewNurseToDepartment();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            cout << "Command could not be found, Please try something else\n";
            break;
    }
}


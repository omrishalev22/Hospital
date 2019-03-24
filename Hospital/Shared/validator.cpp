#include <string>
#include <iostream>
#include "validator.h"
#include "consts.h"

using namespace std;

bool Validator::isCharactersOnly(char *input, unsigned int length)
{
    for (int i = 0; i < length; i++) {
        int uppercaseChar = toupper(input[i]); //Convert character to upper case
        if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
            return false;
    }

    return true;

}

/**
 * Validating patient is willing to move between departments. Relevant for patients
 * who already visited the hospital -> since we don't have any release policy for this software.
 * @param patient
 * @return
 */
bool Validator::isPatientWillingToChangeDepartment(Patient *patient)
{
    int isStaying;

    cout << "It seems you are already part of department '" << patient->getDepartmentName()
         << "' do you want to make a new visit or stay in current department, 1 = Stay , 0 = Change" << endl;
    cin >> isStaying;
    if (isStaying == STAYING) {
        cout << "Please return to your current department" << endl;
        return false;
    } else {
        cout << "Releasing patient from '" << patient->getDepartmentName() << "'" << endl;
        return true;
    }
}
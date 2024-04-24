//
// Created by Omar Hboubati on 4/24/24.
//

#include <iostream>
#include "PersonType.h"
using namespace std;

// I added a test person driving code in order to test the class. You can delete it after
// Also Jetbrains CLion is WAY better than xCode

int main() {
    PersonType personType1;
    cout << personType1.getSSN() << endl << personType1.getFirstName() << endl << personType1.getLastName();
    return 0;
}

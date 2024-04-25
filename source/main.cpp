//
// Created by Omar Hboubati on 4/24/24.
//

#include <iostream>
#include "PersonType.h"
using namespace std;

// I added a test person driving code in order to test the class. You can delete it after
// Also Jetbrains CLion is WAY better than xCode
// I also added the 3 print functions that we had left to finish part A

int main() {
    // using default constructor
    PersonType personType1;
    personType1.printPersonInfo();
    personType1.setPersonInfo("Ibrahim", "Memon", 989898989);
    personType1.printPersonInfo();

    cout << endl;

    // using overloaded constructor
    PersonType personType2("Omar", "Hboubati", 849839823);
    personType2.printPersonInfo();

    return 0;
}

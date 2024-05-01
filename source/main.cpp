//
// Created by Omar Hboubati on 4/24/24.
//

#include <iostream>
#include "PersonType.h"
using namespace std;

// TODO: BetterImp commenting


int main() {
    // using default constructor
    PersonType personType1;
    personType1.setPersonInfo("Ibrahim", "Memon", 989898989);
    personType1.printPersonInfo();

    cout << endl;

    // using overloaded constructor
    PersonType personType2("Omar", "Hbo", 123456789);
    personType2.printPersonInfo();

    return 0;
}

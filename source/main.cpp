/*
 * FILENAME: main.cpp
 */

// importing iostream library for cout
#include <iostream>
// importing PersonType class
#include "PersonType/PersonType.h"
using namespace std;


// Driver function to test PersonType class
int main() {
    // testing default constructor
    PersonType personType1;
    // testing setPersonInfo
    personType1.setPersonInfo("Ibrahim", "Memon", 989898989);
    // testing printPersonInfo
    personType1.printPersonInfo();

    // newline
    cout << endl;

    // testing overloaded constructor
    PersonType personType2("Omar", "Hbo", 123456789);
    // calling printPersonInfo
    personType2.printPersonInfo();

    return 0;
}

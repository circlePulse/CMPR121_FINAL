#include "PersonType.h"
#include <iostream>
#include <string>
using namespace std;
/*
 * Data:
 * std::string fName
 * std::string lName
 * int SSN
 */

// default constructor
PersonType::PersonType() {
    SSN = 0;
}

// overloaded constructor
PersonType::PersonType(const string &newfName, const string &newlName, int newSSN) {
    fName = newfName;
    lName = newlName;
    SSN = newSSN;
}

// Settors

void PersonType::setPersonInfo(const string &newfName, const string &newlName, int newSSN) {
    fName = newfName;
    lName = newlName;
    SSN = newSSN;
}

void PersonType::printName() const {
    cout << lName << ", " << fName;
}

void PersonType::printSSN() const {
    cout << to_string(SSN).substr(0, 3) << "-" << to_string(SSN).substr(4, 2) << "-" << to_string(SSN).substr(6, 4);
}

// Printing

void PersonType::printPersonInfo() const {
    printSSN();
    cout << " " << fName << " " << lName;
}

// Gettors

string PersonType::getFirstName() {
    return fName;
}

string PersonType::getLastName() {
    return lName;
}

int PersonType::getSSN() const {
    return SSN;
}


PersonType::~PersonType() = default;

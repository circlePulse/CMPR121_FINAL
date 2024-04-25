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
PersonType::PersonType(const std::string &newfName, const std::string &newlName, int newSSN) {
    fName = newfName;
    lName = newlName;
    SSN = newSSN;
}

// Settors

void PersonType::setPersonInfo(const std::string &newfName, const std::string &newlName, int newSSN) {
    fName = newfName;
    lName = newlName;
    SSN = newSSN;
}

void PersonType::printName() const {
    std::cout << lName << ", " << fName;
}

// Printing

void PersonType::printPersonInfo() const {
    printSSN();
    cout << " " << fName << " " << lName;
}

void PersonType::printSSN() {
    cout << to_string(SSN).substr(0,3) << "-" << to_string(SSN).substr(4,2) << "-" << to_string(SSN).substr(6,4);
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

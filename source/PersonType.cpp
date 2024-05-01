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
    this->SSN = 0;
}

// overloaded constructor
PersonType::PersonType(const string &fName, const string &lName, int SSN) {
    this->fName = fName;
    this->lName = lName;
    this->SSN = SSN;
}

// Settors

void PersonType::setPersonInfo(const string &fName, const string &lName, int SSN) {
    this->fName = fName;
    this->lName = lName;
    this->SSN = SSN;
}

void PersonType::printName() const {
    cout << lName << ", " << fName;
}

void PersonType::printSSN() const {
    cout << to_string(SSN).substr(0, 3) << "-" << to_string(SSN).substr(3, 3) << "-" << to_string(SSN).substr(6, 4);
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


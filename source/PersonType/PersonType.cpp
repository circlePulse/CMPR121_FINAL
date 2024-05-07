/*
 * FILENAME: PersonType/PersonType.cpp
 *
 * Data:
 * string fName
 * string lName
 * int SSN
 */

// importing PersonType header file
#include "PersonType.h"
// importing iostream library for cout
#include <iostream>
// importing string library
#include <string>
#include <utility>
using namespace std;


// default constructor -- called if no arguments are passed
PersonType::PersonType(): SSN(0) {
}

// overloaded constructor -- called if arguments are passed
// accepts 3 arguments: fName, lName, SSN
PersonType::PersonType(string fName, string lName, const int SSN) : fName(move(fName)), lName(move(lName)), SSN(SSN) {
}

// Settors
// accepts 3 arguments: fName, lName, SSN
void PersonType::setPersonInfo(const string &fName, const string &lName, const int SSN) {
    this->fName = fName;
    this->lName = lName;
    this->SSN = SSN;
}

// printers
void PersonType::printName() const {
    cout << lName << ", " << fName;
}

void PersonType::printSSN() const {
    const string stringSSN = to_string(SSN);
    cout << stringSSN.substr(0, 3) << "-" << stringSSN.substr(3, 3) << "-" << stringSSN.substr(6, 4);
}

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

// Destructor -- called when object is destroyed
PersonType::~PersonType() = default;


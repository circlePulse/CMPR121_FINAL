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
    const string SSN_string = to_string(SSN);
    cout << SSN_string[0] << SSN_string[1] << SSN_string[2];
    cout << "-";
    cout << SSN_string[3] << SSN_string[4] << SSN_string[5];
    cout << "-";
    cout << SSN_string[6] << SSN_string[7] << SSN_string[8];
    /*cout << SSN_string.substr(0, 3) << "-"
            << SSN_string.substr(3, 2) << "-"
            << SSN_string.substr(5, 4);*/
    //cout << to_string(SSN).substr(0, 3) << "-" << to_string(SSN).substr(4, 2) << "-" << to_string(SSN).substr(6, 4);
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

int PersonType::getSSN() {
    return SSN;
}


PersonType::~PersonType() = default;

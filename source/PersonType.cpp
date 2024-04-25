#include "PersonType.h"
#include <iostream>

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
    std::cout << " " << fName << " " << lName;
}

void PersonType::printSSN() const {
    std::cout << SSN;
}

// Gettors

std::string PersonType::getFirstName() {
    return fName;
}

std::string PersonType::getLastName() {
    return lName;
}

int PersonType::getSSN() const {
    return SSN;
}


PersonType::~PersonType() = default;

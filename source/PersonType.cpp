#include "PersonType.h"
#include <iostream>

/*
 * Data:
 * std::string fName
 * std::string lName
 * int SSN
 */

PersonType::PersonType() {
    SSN = 0;
}

PersonType::PersonType(const std::string &newfName, const std::string &newlName, int newSSN) {
    fName = newfName;
    lName = newlName;
    SSN = newSSN;
}

void PersonType::setPersonInfo(const std::string &newfName, const std::string &newlName, int newSSN) {
    fName = newfName;
    lName = newlName;
    SSN = newSSN;
}

void PersonType::printName() const {
    std::cout << lName << ", " << fName;
}

void PersonType::printPersonInfo() const {
    printSSN();
    std::cout << " " << fName << " " << lName;
}

void PersonType::printSSN() const {
    std::cout << SSN;
}

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

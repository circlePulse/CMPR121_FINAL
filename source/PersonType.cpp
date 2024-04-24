#include "PersonType.h"
#include <iostream>

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

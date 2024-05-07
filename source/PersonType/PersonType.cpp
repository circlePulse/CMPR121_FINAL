/*
 * FILENAME: PersonType/PersonType.cpp
 * DESC: Implementation of PersonType class
 *
 * DATA:
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


// default constructor -- called if no arguments are passed
PersonType::PersonType(): SSN(0) {
}

// overloaded constructor -- called if arguments are passed
// accepts 3 arguments: fName, lName, SSN
PersonType::PersonType(std::string fName, std::string lName, const int SSN) : fName(move(fName)), lName(move(lName)),
                                                                              SSN(SSN) {
}

// Settors
// accepts 3 arguments: fName, lName, SSN
void PersonType::setPersonInfo(const std::string &fName, const std::string &lName, const int SSN) {
    this->fName = fName;
    this->lName = lName;
    this->SSN = SSN;
}

// printers
void PersonType::printName() const {
    std::cout << lName << ", " << fName;
}

void PersonType::printSSN() const {
    const std::string stringSSN = std::to_string(SSN);
    std::cout << stringSSN.substr(0, 3) << "-" << stringSSN.substr(3, 3) << "-" << stringSSN.substr(6, 4);
}

void PersonType::printPersonInfo() const {
    printSSN();
    std::cout << " " << fName << " " << lName << std::endl;
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

// Destructor -- called when object is destroyed
PersonType::~PersonType() = default;


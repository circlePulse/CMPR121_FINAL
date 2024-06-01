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


// default constructor -- called if no arguments are passed
PersonType::PersonType() {
    this->SSN = 0;
}

// overloaded constructor -- called if arguments are passed
// accepts 3 arguments: fName, lName, SSN
PersonType::PersonType(const std::string &fName, const std::string &lName, const int SSN) {
    this->fName = fName;
    this->lName = lName;
    this->SSN = SSN;
}

// Settors
// accepts 3 arguments: fName, lName, SSN
void PersonType::setPersonInfo(const std::string &fName, const std::string &lName, const int SSN) {
    this->fName = fName;
    this->lName = lName;
    this->SSN = SSN;
}

void PersonType::setName(const std::string &fName, const std::string &lName) {
    this->fName = fName;
    this->lName = lName;
}

void PersonType::setSSN(int const SSN) {
    this->SSN = SSN;
}

// printers
void PersonType::printName() const {
    std::cout << lName << ", " << fName;
}

std::string PersonType::getFormattedName() const {
    return lName + ", " + fName;
}

void PersonType::printSSN() const {
    const std::string stringSSN = std::to_string(SSN);
    std::cout << stringSSN.substr(0, 3) << "-" << stringSSN.substr(3, 2) << "-" << stringSSN.substr(5, 4);
}

void PersonType::printPersonInfo() const {
    printSSN();
    std::cout << " " << fName << " " << lName << std::endl;
}

// Gettors

std::string PersonType::getFirstName() {
    return this->fName;
}

std::string PersonType::getLastName() {
    return this->lName;
}

int PersonType::getSSN() const {
    return SSN;
}

// Destructor -- called when object is destroyed
PersonType::~PersonType() = default;


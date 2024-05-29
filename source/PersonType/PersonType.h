/*
 * FILENAME: PersonType/PersonType.h
 * DESC: Specification file for PersonType class
 */

// making sure the header file is included only once
#ifndef PERSONTYPE_H
#define PERSONTYPE_H

// importing string library
#include <string>


class PersonType {
public:
    // Default constructor
    PersonType();

    // Overloaded Constructor
    PersonType(std::string fName, std::string lName, int SSN);

    // Settors
    void setPersonInfo(const std::string &fName, const std::string &lName, int SSN);

    void setName(const std::string &fName, const std::string &lName);

    void setSSN(int SSN);

    // printers
    void printPersonInfo() const;

    void printName() const;

    std::string getFormattedName() const;

    void printSSN() const;

    // Gettors
    std::string getFirstName();

    std::string getLastName();

    [[nodiscard]] int getSSN() const;


    // Destructor
    ~PersonType();

private:
    std::string fName;
    std::string lName;
    int SSN;
};


#endif //PERSONTYPE_H

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>


class PersonType {
public:
    // Default constructor
    PersonType();

    // Overloaded Constructor
    PersonType(const std::string &fName, const std::string &lName, int SSN);

    // Settors
    void setPersonInfo(const std::string &fName, const std::string &lName, int SSN);

    // printers
    void printPersonInfo() const;

    void printName() const;

    void printSSN() const;

    // Gettors
    std::string getFirstName();

    std::string getLastName();

    int getSSN() const;


    // Destructor
    ~PersonType();

private:
    std::string fName;
    std::string lName;
    int SSN;
};


#endif //PERSONTYPE_H

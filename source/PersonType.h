//
// Created by Omar Hboubati on 4/24/24.
//

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>


class PersonType {
public:
    // Default constructor
    PersonType();

    // Overloaded Constructor
    PersonType(const std::string &newfName, const std::string &newlName, int newSSN);

    // Settors
    void setPersonInfo(const std::string &newfName, const std::string &newlName, int newSSN);

    // printers
    

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

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

using namespace std;


class PersonType {
public:
    // Default constructor
    PersonType();

    // Overloaded Constructor
    PersonType(const string &newfName, const string &newlName, int newSSN);

    // Settors
    void setPersonInfo(const string &newfName, const string &newlName, int newSSN);

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
    string fName;
    string lName;
    int SSN;
};


#endif //PERSONTYPE_H

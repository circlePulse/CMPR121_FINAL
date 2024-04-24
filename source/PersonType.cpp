//
// Created by Omar Hboubati on 4/24/24.
//

#include "PersonType.h"

PersonType::PersonType() {
    SSN = 0;
}

PersonType::PersonType(const std::string &newfName, const std::string &newlName, int newSSN) {
    fName = newfName;
    lName = newlName;
    SSN = newSSN;
}

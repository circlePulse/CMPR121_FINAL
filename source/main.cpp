/*
 * FILENAME: main.cpp
 */

// importing iostream library for cout
#include <iostream>
// importing PersonType class
#include "CandidateType/CandidateType.h"
#include "PersonType/PersonType.h"
using namespace std;


int main() {
    // Test PersonType class
    cout << "Testing PersonType class" << endl;
    // testing default constructor
    PersonType personType1;
    // testing setPersonInfo
    personType1.setPersonInfo("Ibrahim", "Memon", 989898989);
    // testing printPersonInfo
    personType1.printPersonInfo();


    // testing overloaded constructor
    const PersonType personType2("Omar", "Hbo", 123456789);
    // calling printPersonInfo
    personType2.printPersonInfo();

    cout << "\n" << endl;


    // Test CandidateType class
    cout << "Testing CandidateType class" << endl;

    CandidateType candidateType1;
    candidateType1.setPersonInfo("John", "Doe", 111223333);
    candidateType1.updateVotesByCampus(0, 25);
    candidateType1.updateVotesByCampus(1, 15);
    cout << "Total votes for candidate " << candidateType1.getFirstName() << ": " << candidateType1.getTotalVotes() <<
            endl;

    candidateType1.printCandidateInfo();

    for (int i = 0; i < NUM_OF_CAMPUSES; ++i) {
        cout << "Votes from campus " << i << ": " << candidateType1.getVotesByCampus(i) << endl;
    }

    return 0;
}

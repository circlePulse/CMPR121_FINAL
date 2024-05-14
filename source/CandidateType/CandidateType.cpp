/*
 * FILENAME: CandidateType/CandidateType.cpp
 * DESC: Implementation of CandidateType class
 *
 * DATA:
 * Parent: PersonType
 * string fName
 * string lName
 * int SSN
 *
 * int[] campusVotes
 * int votes
 *
 */
#include "CandidateType.h"
#include <iostream>

CandidateType::CandidateType() {
    for (int &campusVote: this->campusVotes) {
        campusVote = 0;
    }
    this->votes = 0;
    this->setSSN(0);
}

CandidateType::CandidateType(std::string fName, std::string lName, const int SSN) : PersonType(
    std::move(fName), std::move(lName),
    SSN) {
    for (int &campusVote: this->campusVotes) {
        campusVote = 0;
    }
    this->votes = 0;
}

void CandidateType::updateVotesByCampus(const int campus, const int votes) {
    if (campus < 0 || campus >= NUM_OF_CAMPUSES) {
        throw std::out_of_range("Invalid Campus");
    }
    this->campusVotes[campus] = votes;
    this->p_updateVotes();
}

int CandidateType::getTotalVotes() const {
    return this->votes;
}

int CandidateType::getVotesByCampus(const int campus) const {
    if (campus < 0 || campus >= NUM_OF_CAMPUSES) {
        throw std::out_of_range("Invalid Campus");
    }
    return this->campusVotes[campus];
}

void CandidateType::printCandidateInfo() const {
    this->printPersonInfo();
}

void CandidateType::printCandidateTotalVotes() {
    std::cout << this->getFirstName() << ", " << this->getLastName() << "\n     -> Total Votes (all campuses): " << this
            ->
            votes <<
            "\n";
}

void CandidateType::printCandidateCampusVotes() {
    std::cout << this->getFirstName() << ", " << this->getLastName() << "\n";
    for (int i = 0; i < NUM_OF_CAMPUSES; i++) {
        std::cout << "     -> Campus " << (i + 1) << " total votes: " << this->campusVotes[i] << "\n";
    }
}

void CandidateType::p_updateVotes() {
    this->votes = 0;

    for (const int i: campusVotes) {
        this->votes += i;
    }
}

CandidateType::~CandidateType() = default;

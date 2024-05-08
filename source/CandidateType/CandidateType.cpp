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

// default constructor -- called if no arguments are passed
CandidateType::CandidateType() {
 for (int i = 0; i < NUM_OF_CAMPUSES; i++) {
  this->campusVotes[i] = 0;
 }
 this->votes = 0;
 this->SSN = 0;
}

// settors
void CandidateType::updateVotesByCampus(const int campus, const int votes) {
 if (campus < 0 || campus >= NUM_OF_CAMPUSES) {
  throw std::out_of_range("Invalid Campus");
 }
 this->campusVotes[campus] = votes;
 this->p_updateVotes();
}

// gettors

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

void CandidateType::printCandidateTotalVotes() const {
 std::cout << this->fName << ", " << this->lName << "\n     -> Total Votes (all campuses): " << this->votes << "\n";
}

void CandidateType::printCandidateCampusVotes() const {
 std::cout << this->fName << ", " << this->lName << "\n";
 for (int i = 0; i < NUM_OF_CAMPUSES; i++) {
  std::cout << "     -> Campus " << (i + 1) << " total votes: " << this->campusVotes[i] << "\n";
 }
}

// private function to update votes
void CandidateType::p_updateVotes() {
 this->votes = 0;

 for (int i: campusVotes) {
  this->votes += i;
 }
}

// Destructor
CandidateType::~CandidateType() = default;

/*
 * FILENAME: CandidateType/CandidateType.cpp
 *
 * Data:
 * Parent: PersonType
 * string fName
 * string lName
 * int SSN
 *
 *
 */
#include "CandidateType.h"

// default constructor -- called if no arguments are passed
CandidateType::CandidateType() : campusVotes{0}, votes(0) {
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

// private function to update votes
void CandidateType::p_updateVotes() {
 this->votes = 0;

 for (int i: campusVotes) {
  this->votes += i;
 }
}

// Destructor
CandidateType::~CandidateType() = default;

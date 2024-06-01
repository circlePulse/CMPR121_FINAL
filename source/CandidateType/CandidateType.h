/*
 * FILENAME: CandidateType/CandidateType.h
 * DESC: Specification file for CandidateType class
 */

#pragma once
#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H
#include "../PersonType/PersonType.h"
#include <string>

constexpr int NUM_OF_CAMPUSES = 4;


class CandidateType : public PersonType {
public:
    // default constructor
    CandidateType();

    CandidateType(const std::string &fName, const std::string &lName, int SSN);

    // settors
    void updateVotesByCampus(int campus, int votes);

    // gettors
    [[nodiscard]] int getTotalVotes() const;

    [[nodiscard]] int getVotesByCampus(int campus) const;

    // printers
    void printCandidateInfo() const;

    void printCandidateTotalVotes();

    void printCandidateCampusVotes();

    // destructor
    ~CandidateType();

private:
    int campusVotes[NUM_OF_CAMPUSES]{};
    int votes;

    void p_updateVotes();
};


#endif //CANDIDATETYPE_H

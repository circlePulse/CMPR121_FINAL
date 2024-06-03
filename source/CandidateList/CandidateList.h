#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "../CandidateType/CandidateType.h"
#include "../Node/Node.h"

class CandidateList {
private:
    Node *first;
    Node *last;
    int count;

public:
    CandidateList();

    void addCandidate(const CandidateType &candidate);

    [[nodiscard]] int getWinner() const;

    [[nodiscard]] bool searchCandidate(int ssn) const;

    void printCandidateName(int ssn) const;

    void printAllCandidates() const;

    void printCandidateCampusVotes(int ssn, int campus) const;

    void printCandidateTotalVotes(int ssn) const;

    void printFinalResults() const;

    void destroyList();

    ~CandidateList();
};

#endif

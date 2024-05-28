#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "../CandidateType/CandidateType.h"
#include "../Node/Node.h"

class CandidateList {
public:
    CandidateList();
    ~CandidateList();
    void addCandidate(const CandidateType& candidate);
    int getWinner() const;
    bool searchCandidate(int ssn) const;
    void printCandidateName(int ssn) const;
    void printAllCandidates() const;
    void printCandidateCampusVotes(int ssn, int campus) const;
    void printCandidateTotalVotes(int ssn) const;
    void printFinalResults() const;
    void destroyList();

private:
    Node* first;
    Node* last;
    int count;
};

#endif

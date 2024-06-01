#pragma once
#ifndef NODE_H
#define NODE_H

#include "../CandidateType/CandidateType.h"


class Node {
public:
    Node() : link(nullptr) {
    }

    Node(const CandidateType &votes, Node *theLink)
        : candidate(votes), link(theLink) {
    }

    [[nodiscard]] Node *getLink() const;

    [[nodiscard]] CandidateType getCandidate() const;

    void setCandidate(const CandidateType &votes);

    void setLink(Node *theLink);

    ~Node() = default;

private:
    CandidateType candidate;
    Node *link; //pointer that points to next node
};


#endif

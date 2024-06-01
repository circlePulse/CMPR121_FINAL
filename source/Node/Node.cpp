//
// Created by Omar Hboubati on 5/31/24.
//

#include "Node.h"

Node *Node::getLink() const {
    return link;
}

CandidateType Node::getCandidate() const { return candidate; }

void Node::setCandidate(const CandidateType &votes) { candidate = votes; }

void Node::setLink(Node *theLink) { link = theLink; }

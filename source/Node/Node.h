#include "../CandidateType/CandidateType.h"


class Node {
public:
    Node() : link(nullptr) {
    }

    Node(const CandidateType &votes, Node *theLink)
        : candidate(votes), link(theLink) {
    }

    [[nodiscard]] Node *getLink() const { return link; }
    [[nodiscard]] CandidateType getCandidate() const { return candidate; }
    void setCandidate(const CandidateType &votes) { candidate = votes; }
    void setLink(Node *theLink) { link = theLink; }

    ~Node() = default;

private:
    CandidateType candidate;
    Node *link; //pointer that points to next node
};


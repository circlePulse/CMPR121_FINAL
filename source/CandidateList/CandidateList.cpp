#include "CandidateList.h"
#include <iostream>

// Default constructor
CandidateList::CandidateList() : first(nullptr), last(nullptr), count(0) {}

// Destructor
CandidateList::~CandidateList() {
    destroyList();
}

// Add a candidate to the list
void CandidateList::addCandidate(const CandidateType& candidate) {
    Node* newNode = new Node(candidate, nullptr);
    if (first == nullptr) {
        first = last = newNode;
    } else {
        last->setLink(newNode);
        last = newNode;
    }
    count++;
}

// Get the SSN of the candidate with the highest votes
int CandidateList::getWinner() const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return 0;
    }

    Node* current = first;
    Node* winner = first;

    while (current != nullptr) {
        if (current->getCandidate().getTotalVotes() > winner->getCandidate().getTotalVotes()) {
            winner = current;
        }
        current = current->getLink();
    }

    return winner->getCandidate().getSSN();
}

// Search for a candidate by SSN
bool CandidateList::searchCandidate(int ssn) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return false;
    }

    Node* current = first;
    while (current != nullptr) {
        if (current->getCandidate().getSSN() == ssn) {
            return true;
        }
        current = current->getLink();
    }

    std::cout << "=> SSN not in the list" << std::endl;
    return false;
}

// Print the name of a candidate by SSN
void CandidateList::printCandidateName(int ssn) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    Node* current = first;
    while (current != nullptr) {
        if (current->getCandidate().getSSN() == ssn) {
            current->getCandidate().printName();
            return;
        }
        current = current->getLink();
    }

    std::cout << "=> SSN not in the list" << std::endl;
}

// Print all candidates in the list
void CandidateList::printAllCandidates() const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    Node* current = first;
    while (current != nullptr) {
        current->getCandidate().printCandidateInfo();
        current = current->getLink();
    }
}

// Print campus votes for a specific candidate
void CandidateList::printCandidateCampusVotes(int ssn, int campus) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    Node* current = first;
    while (current != nullptr) {
        if (current->getCandidate().getSSN() == ssn) {
            current->getCandidate().getVotesByCampus(campus - 1);
            return;
        }
        current = current->getLink();
    }

    std::cout << "=> SSN not in the list" << std::endl;
}

// Print total votes for a specific candidate
void CandidateList::printCandidateTotalVotes(int ssn) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    Node* current = first;
    while (current != nullptr) {
        if (current->getCandidate().getSSN() == ssn) {
            current->getCandidate().getTotalVotes();
            return;
        }
        current = current->getLink();
    }

    std::cout << "=> SSN not in the list" << std::endl;
}

// Print total votes for a specific candidate
void CandidateList::printFinalResults() const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    Node* current = first;
    while (current != nullptr) {
        std::cout << "Candidate Name: ";
        current->getCandidate().printName();
        std::cout << " Total Votes: " << current->getCandidate().getTotalVotes() << std::endl;
        current = current->getLink();
    }
}

// Delete all nodes in the list and reset member variables
void CandidateList::destroyList() {
    Node* temp;

    while (first != nullptr) {
        temp = first;
        first = first->getLink();
        delete temp;
    }

    last = nullptr;
    count = 0;
}

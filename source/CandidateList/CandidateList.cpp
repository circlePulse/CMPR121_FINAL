#include "CandidateList.h"
#include <iostream>
#include <iomanip>

// Default constructor
CandidateList::CandidateList() : first(nullptr), last(nullptr), count(0) {
}

// Destructor
CandidateList::~CandidateList() {
    destroyList();
}

// Add a candidate to the list
void CandidateList::addCandidate(const CandidateType &candidate) {
    Node *newNode = new Node(candidate, nullptr);
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

    const Node *current = first;
    const Node *winner = first;

    while (current != nullptr) {
        if (current->getCandidate().getTotalVotes() > winner->getCandidate().getTotalVotes()) {
            winner = current;
        }
        current = current->getLink();
    }

    return winner->getCandidate().getSSN();
}

// Search for a candidate by SSN
bool CandidateList::searchCandidate(int const ssn) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return false;
    }

    const Node *current = first;
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
void CandidateList::printCandidateName(int const ssn) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    const Node *current = first;
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

    const Node *current = first;
    while (current != nullptr) {
        current->getCandidate().printCandidateInfo();
        current = current->getLink();
    }
}

// Print campus votes for a specific candidate
void CandidateList::printCandidateCampusVotes(int const ssn, int const campus) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    Node const *current = first;
    while (current != nullptr) {
        if (current->getCandidate().getSSN() == ssn) {
            std::cout << "\nCampus " << campus + 1 << " Votes: " << current->getCandidate().getVotesByCampus(campus);
            return;
        }
        current = current->getLink();
    }

    std::cout << "=> SSN not in the list" << std::endl;
}

// Print total votes for a specific candidate
void CandidateList::printCandidateTotalVotes(int const ssn) const {
    if (first == nullptr) {
        std::cout << "=> List is empty" << std::endl;
        return;
    }

    Node const *current = first;
    while (current != nullptr) {
        if (current->getCandidate().getSSN() == ssn) {
            std::cout << current->getCandidate().getTotalVotes();
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

    const Node *current = first;
    std::cout << std::left << std::setw(25) << "Candidate Name" << std::setw(20) << "Total Votes" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    while (current != nullptr) {
        std::cout << std::left << std::setw(25) << current->getCandidate().getFormattedName() << std::setw(15) <<
                current->getCandidate().getTotalVotes() << std::endl;
        current = current->getLink();
    }
}

// Delete all nodes in the list and reset member variables
void CandidateList::destroyList() {
    while (first != nullptr) {
        const Node *temp = first;
        first = first->getLink();
        delete temp;
    }

    last = nullptr;
    count = 0;
}

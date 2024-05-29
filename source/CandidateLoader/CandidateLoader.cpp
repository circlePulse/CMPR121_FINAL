#include "../CandidateList/CandidateList.h"
#include "CandidateLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Function to load candidates from file
void loadCandidatesFromFile(CandidateList& candidateList, const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line == "-999") break;

        std::istringstream iss(line);
        int ssn;
        std::string fName, lName;
        int votes[4];

        iss >> ssn >> fName >> lName >> votes[0] >> votes[1] >> votes[2] >> votes[3];

        CandidateType candidate(fName, lName, ssn);
        candidateList.addCandidate(candidate);
    }
}

void initializeCandidates(CandidateList& candidateList) {
    std::string filename = "../../Resources/Candidate_data.txt";
    loadCandidatesFromFile(candidateList, filename);
}
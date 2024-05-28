
#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include "../CandidateList/CandidateList.h"


void createCandidateList(std::ifstream& infile, CandidateList& candidateList)
{
	int ssn = 0;
	int allVotes[NUM_OF_CAMPUSES];
	std::string  fName, lName;

	infile >> ssn;

	while (ssn != -999)
	{
		CandidateType newCandidate;

		infile >> fName;
		infile >> lName;
		newCandidate.setPersonInfo(fName, lName, ssn);

		for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
		{
			infile >> allVotes[i];
			newCandidate.updateVotesByCampus(i, allVotes[i]);
		}

		candidateList.addCandidate(newCandidate);


		infile >> ssn;
	}
}

void readCandidateData(CandidateList& candidateList)
{
    std::ifstream infile;

    // Adjust the file path here
    infile.open("../Resources/Candidate_data.txt");

    if (!infile)
    {
        std::cout << "Input file does not exist." << std::endl;
        exit(1);
    }

    createCandidateList(infile, candidateList);

    infile.close();
}

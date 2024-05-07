/*
 * FILENAME: CandidateType/CandidateType.h
 */

#pragma once
#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H
#include "../PersonType/PersonType.h"

const int NUM_OF_CAMPUSES = 4;


class CandidateType : public PersonType {
public:
private:
 int votes;
};


#endif //CANDIDATETYPE_H

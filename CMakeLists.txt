cmake_minimum_required(VERSION 3.28)
project(CMPR121_FINAL)

set(CMAKE_CXX_STANDARD 26)

add_executable(CMPR121_FINAL source/main.cpp
        source/PersonType/PersonType.h
        source/PersonType/PersonType.cpp
        source/CandidateType/CandidateType.cpp
        source/CandidateType/CandidateType.h
        source/CandidateList/CandidateList.cpp
)

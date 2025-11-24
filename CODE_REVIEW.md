# Code Review - CMPR121 Final Project

**Project**: Election Voting System
**Group**: Right Twix
**Reviewers**: Ibrahim Memon, Omar Hboubati, Luke Nguyen, Fernando Resendiz

---

## Overview
The project successfully implements a linked-list based election management system. The code compiles and runs correctly, demonstrating good understanding of OOP principles, inheritance, and data structures.

---

## Critical Issues ⚠️

### 1. **DATA CORRUPTION** - Line 3 in Candidate_data.txt
**Location**: `Resources/Candidate_data.txt:3`
**Issue**: Name shows as "WCatelyn Stark" instead of "Catelyn Stark"
```
342772712 WCatelyn Stark 34 4 6 56
```
**Fix**: Remove the extra "W" at the beginning of "Catelyn"

### 2. **Code Duplication in Input Validation**
**Location**: `source/main.cpp:52-69` and `source/main.cpp:140-157`
**Issue**: The exact same input validation code appears twice in processChoice()

**Recommendation**: Extract to a helper function:
```cpp
int getValidMenuChoice() {
    int choice = 0;
    string unFormattedChoice;
    bool isInputValid = false;

    while (!isInputValid) {
        cout << "\nEnter your choice: ";
        cin >> unFormattedChoice;
        if (unFormattedChoice.length() == 1) {
            if (isdigit(unFormattedChoice[0])) {
                choice = stoi(unFormattedChoice);
                if (choice >= 1 && choice <= 6) {
                    isInputValid = true;
                } else {
                    cout << "Invalid input. Please enter a number between 1 and 6." << endl;
                }
            } else {
                cout << "Invalid input. Please enter a number." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a single digit." << endl;
        }
    }
    return choice;
}
```

### 3. **Hardcoded Relative File Path**
**Location**: `source/InputHandler/InputHandler.h:41`
**Issue**: Path `"../Resources/Candidate_data.txt"` may fail in different build configurations

**Recommendation**: Consider making it configurable or using an absolute path

---

## Design Issues 🔧

### 4. **Inefficient Object Copying**
**Location**: `source/Node/Node.h:19`
**Issue**: `getCandidate()` returns by value, causing unnecessary copying
```cpp
[[nodiscard]] CandidateType getCandidate() const;  // Returns copy
```

**Impact**: Every time you access a candidate from a node, the entire object is copied (name, SSN, votes array)

**Recommendation**: Return by const reference:
```cpp
[[nodiscard]] const CandidateType& getCandidate() const;
```
Then update Node.cpp:
```cpp
const CandidateType& Node::getCandidate() const { return candidate; }
```

### 5. **Missing const Qualifiers**
**Location**: `source/PersonType/PersonType.h:40-42`
**Issue**: Getter methods should be const since they don't modify the object
```cpp
std::string getFirstName();      // Should be const
std::string getLastName();       // Should be const
```

**Fix**: Add const and make them return by const reference to avoid copying:
```cpp
[[nodiscard]] const std::string& getFirstName() const;
[[nodiscard]] const std::string& getLastName() const;
```

### 6. **Commented Code in Function Signature**
**Location**: `source/main.cpp:47`
```cpp
void processChoice(CandidateList /*const*/ &candidateList)
```
**Issue**: The commented `const` suggests uncertainty about the design

**Recommendation**: Either add the const or remove the comment completely

### 7. **Unused Member Variable**
**Location**: `source/CandidateList/CandidateList.h:11`
**Issue**: `count` is incremented but never used

**Options**:
- Remove it if not needed
- Add a `getCount()` method if it might be useful
- Use it for optimization (checking if list is empty)

---

## Style & Best Practices 📝

### 8. **Redundant Header Guards**
**Location**: `source/PersonType/PersonType.h:7-9`
```cpp
#pragma once
#ifndef PERSONTYPE_H  // Redundant - #pragma once already does this
#define PERSONTYPE_H
```

**Recommendation**: Use either `#pragma once` OR include guards, not both. Modern C++ prefers `#pragma once`.

### 9. **Non-Standard C++ Version**
**Location**: `CMakeLists.txt:4`
```cmake
set(CMAKE_CXX_STANDARD 26)
```

**Issue**: C++26 is not finalized yet and may not be supported by all compilers

**Recommendation**: Use C++17 or C++20:
```cmake
set(CMAKE_CXX_STANDARD 20)
```

### 10. **Typo in Comments**
**Location**: Multiple files
**Issue**: "Settors" should be "Setters"

Examples:
- `source/PersonType/PersonType.cpp:32`
- `source/CandidateType/CandidateType.h:22`

---

## Security Considerations 🔒

### 11. **No Bounds Checking on SSN String Operations**
**Location**: `source/PersonType/PersonType.cpp:59-60`
```cpp
std::cout << stringSSN.substr(0, 3) << "-"
          << stringSSN.substr(3, 2) << "-"
          << stringSSN.substr(5, 4);
```

**Issue**: If SSN is less than 9 digits, this will crash

**Recommendation**: Add validation:
```cpp
void PersonType::printSSN() const {
    const std::string stringSSN = std::to_string(SSN);
    if (stringSSN.length() != 9) {
        std::cout << "Invalid SSN";
        return;
    }
    std::cout << stringSSN.substr(0, 3) << "-"
              << stringSSN.substr(3, 2) << "-"
              << stringSSN.substr(5, 4);
}
```

---

## What You Did Well ✅

1. **Clean Architecture**: Good separation of concerns with PersonType → CandidateType inheritance
2. **Memory Management**: Proper destructor implementation with `destroyList()`
3. **Input Validation**: Comprehensive input checking in main.cpp
4. **Error Handling**: Good use of exceptions in `updateVotesByCampus()` and `getVotesByCampus()`
5. **Code Organization**: Logical folder structure with separate directories for each class
6. **Documentation**: Good file headers and inline comments
7. **Modern C++ Features**: Use of `[[nodiscard]]` attribute, range-based for loops, and `= default` destructors
8. **Const Correctness**: Many methods properly marked as const
9. **Encapsulation**: Private data members with public interfaces

---

## Testing Recommendations 🧪

1. Test with empty list (no candidates)
2. Test with invalid SSN inputs (letters, negative numbers)
3. Test with SSN that doesn't exist
4. Test with duplicate SSN values
5. Test with tied vote counts
6. Test edge cases: 0 votes, very large vote counts

---

## Priority Fixes (Before Submission)

**Must Fix**:
1. Fix "WCatelyn" typo in data file (Issue #1)

**Should Fix**:
2. Extract duplicate input validation code (Issue #2)
3. Fix Node::getCandidate() return type (Issue #4)
4. Add const to getFirstName/getLastName (Issue #5)
5. Add SSN validation in printSSN (Issue #11)

**Nice to Have**:
6. Remove redundant header guards (Issue #8)
7. Change C++ standard to 20 (Issue #9)
8. Fix "settors" → "setters" typo (Issue #10)

---

## Grade Impact Assessment

**Current State**: B+ to A-

**Potential Issues**:
- Data file typo might look unprofessional (-5%)
- Code duplication suggests lack of refactoring (-5%)
- Performance issue with getCandidate() (minor, but shows understanding)

**With Priority Fixes**: A to A+

---

## Final Thoughts

This is solid work that demonstrates good understanding of:
- Object-oriented programming
- Inheritance
- Linked list data structures
- Memory management in C++
- Separation of concerns

The issues found are mostly minor and easily fixable. Great job overall!

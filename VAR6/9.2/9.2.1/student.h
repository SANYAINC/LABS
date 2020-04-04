#pragma once

#include <iostream>
using namespace std;

class student {
public:
    string mName;
    string mSurname;

    int mAge;
    double mAvgGP;
    int mCourse;

    student();
};

student::student() {
    mName = "UNKNOWN";
    mSurname = "UNKNOWN";
    mAge = 0;
    mAvgGP = 0;
    mCourse = 0;
}
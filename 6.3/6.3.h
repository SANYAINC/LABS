#pragma once

#include <iostream>
#include <cstring>
#define NAME_MAX_LEN 25

using namespace std;


class student {
public:
    char mName[NAME_MAX_LEN];
    char mLastName[NAME_MAX_LEN];
    char mPatronymic[NAME_MAX_LEN];
    int mAge;
    char mSex;
    int mCourse;
    double mAvgGP;

    student();
    student(char name[NAME_MAX_LEN], char lastName[NAME_MAX_LEN], char patronymic[NAME_MAX_LEN],
            int age, char sex, int course, double avgGP);

    void print();
};
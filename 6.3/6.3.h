#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#define NAME_MAX_LEN 25

using namespace std;

//TODO Переделать в стринг?

class student {
    static int lastID;
    int mID;
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

    bool appendDB(string &databaseName);
    bool appendDBBin(string &databaseName);

    void print();

    static bool selectGoodFromAll(string &databaseName, string &newDBName);
    static bool selectGoodFromAllBIN(string &databaseName, string &newDBName);
};

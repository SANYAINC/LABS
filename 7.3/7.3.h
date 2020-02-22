#pragma once

#include <iostream>
#include <cstring>
#include <windows.h>
#define MAX_CHARACTERS 25
#define CURRENT_YEAR 2020

using namespace std;

class date {
    union dateUNION{
        unsigned short int dateEncrypted;
        struct {
            unsigned short int year:7;
            unsigned short int month:4;
            unsigned short int day:5;
        };
    };

    dateUNION mDate;

    bool validate(int day, int month, int year);

public:
    date();
    date(int day, int month, int year);

    date &operator = (date date2);

    void setDate(int day, int month, int year);

    unsigned short int getDateEncrypted();
    int getYear();
    int getMonth();
    int getDay();

    void print();
    void showEncrypted();
};

class student {
    char mName[MAX_CHARACTERS];
    char mLastName[MAX_CHARACTERS];
    char mPatronymic[MAX_CHARACTERS];
    date mBirthDate;
    int mCourse;
    double mAvgGP;
public:
    student();
    student(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP);

    student& operator = (student student1);

    void updateInfo(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP);

    char *getLastName();
    double getAvg();

    void print();
};

class list {
    class unit {
    public:
        student mData;
        unit *mNextPtr;
        unit(student data, unit *nextPtr = nullptr);
    };

    unit *mHead;
    int mSize;

    void error(int type);
public:
    list();
    void pushBack(student person);
    void pushAt(student person, int index);
    void pushAlphabetically(student person);
    void moveGoodToAnotherList(list &list2);
    void removeAt(int index);
    int getSize();

    void clear();

    student& operator [] (int index);
};
#pragma once

#include <iostream>
#include <cstring>
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
    //TODO Перегрузить для строк
    char mName[MAX_CHARACTERS];
    char mLastName[MAX_CHARACTERS];
    char mPatronymic[MAX_CHARACTERS];
    date mBirthDate;
    int mCourse;
    double mAvgGP;
public:
    //TODO Валидатор
    student();
    student(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP);

    student& operator = (student student1);

    void updateInfo(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP);

    void print();
};
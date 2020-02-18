#include "7.3.h"


date::date() {
    mDate.year = 120;
    mDate.month = 1;
    mDate.day = 1;
}
date::date(int day, int month, int year) {
    if (validate(day, month, year)) {
        mDate.year = CURRENT_YEAR - year;
        mDate.month = month;
        mDate.day = day;
    } else {
        mDate.year = 120;
        mDate.month = 1;
        mDate.day = 1;
    }
}

date &date::operator = (date date2) {
    mDate.dateEncrypted = date2.mDate.dateEncrypted;
    return *this;
}

bool date::validate(int day, int month, int year) {
    return !(day > 31 or day < 1 or month > 12 or month < 1 or year > CURRENT_YEAR or year < 1900);
}

void date::setDate(int day, int month, int year) {
    if (validate(day, month, year)) {
        mDate.year = CURRENT_YEAR - year;
        mDate.month = month;
        mDate.day = day;
    } else {
        mDate.year = 120;
        mDate.month = 1;
        mDate.day = 1;
    }
}

unsigned short int date::getDateEncrypted() {
    return mDate.dateEncrypted;
}
int date::getYear() {
    return CURRENT_YEAR - mDate.year;
}
int date::getMonth() {
    return mDate.month;
}
int date::getDay() {
    return mDate.day;
}

void date::print() {
    printf("%02u.%02u.%d\n", mDate.day, mDate.month, CURRENT_YEAR - mDate.year);
}
void date::showEncrypted() {
    printf("%u\n", mDate.dateEncrypted);
}





student::student() {
    strcpy(mName, "UNKNOWN");
    strcpy(mLastName, "UNKNOWN");
    strcpy(mPatronymic, "UNKNOWN");
    mCourse = -1;
    mAvgGP = 0;
}
student::student(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP) {
    strcpy(mName, name);
    strcpy(mLastName, lastName);
    strcpy(mPatronymic, patronymic);
    mBirthDate = birthDate;
    mCourse = course;
    mAvgGP = avgGP;
}

student &student::operator = (student student1) {
    strcpy(mName, student1.mName);
    strcpy(mLastName, student1.mLastName);
    strcpy(mPatronymic, student1.mPatronymic);
    mBirthDate = student1.mBirthDate;
    mCourse = student1.mCourse;
    mAvgGP = student1.mAvgGP;
    return *this;
}

void student::print() {
    printf("NAME: %s\nLAST NAME: %s\nPATRONYMIC: %s\nBIRTH DATE: %02u.%02u.%d\nCOURSE: %d\nAVERAGE GRADE POINT: %lf\n",
            mName, mLastName, mPatronymic, mBirthDate.getDay(), mBirthDate.getMonth(), mBirthDate.getYear(), mCourse,
            mAvgGP);
}

void student::updateInfo(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP) {
    strcpy(mName, name);
    strcpy(mLastName, lastName);
    strcpy(mPatronymic, patronymic);
    mBirthDate = birthDate;
    mCourse = course;
    mAvgGP = avgGP;
}

#include "6.3.h"

student::student() {
    strcpy(mName, "UNKNOWN");
    strcpy(mLastName, "UNKNOWN");
    strcpy(mPatronymic, "UNKNOWN");
    mAge = -1;
    mSex = '?';
    mCourse = -1;
    mAvgGP = 0;
}
student::student(char name[NAME_MAX_LEN], char lastName[NAME_MAX_LEN], char patronymic[NAME_MAX_LEN],
        int age, char sex, int course, double avgGP) {
    strcpy(mName, name);
    strcpy(mLastName, lastName);
    strcpy(mPatronymic, patronymic);
    mAge = age;
    mSex = sex;
    mCourse = course;
    mAvgGP = avgGP;
}
void student::print() {
    printf("Name: %s\nLast name: %s\nPatronymic: %s\nAge: %d\nSex: %c\nCourse: %d\nAverage Grade Point: %lf\n\n",
           mName, mLastName, mPatronymic, mAge, mSex, mCourse, mAvgGP);
}
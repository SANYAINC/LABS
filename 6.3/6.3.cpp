#include "6.3.h"

student::student() {
    lastID++;
    mID = lastID;
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
    lastID++;
    mID = lastID;
    strcpy(mName, name);
    strcpy(mLastName, lastName);
    strcpy(mPatronymic, patronymic);
    mAge = age;
    mSex = sex;
    mCourse = course;
    mAvgGP = avgGP;
}

void student::print() {
    printf("ID: %d\nName: %s\nLast name: %s\nPatronymic: %s\nAge: %d\nSex: %c\nCourse: %d\nAverage Grade Point: %lf\n\n",
           mID, mName, mLastName, mPatronymic, mAge, mSex, mCourse, mAvgGP);
}

bool student::appendDB(string &databaseName) {
    if (databaseName[databaseName.length() - 3] != 't') {
        return false;
    }

    ofstream f;
    bool isDone = true;
    f.open("../6.3/" + databaseName, ios::app);
    if (!f.is_open()) {
        isDone = false;
    } else {
        f << "ID: " << mID << endl;
        f << "NAME: " << mName << endl;
        f << "LAST NAME: " << mLastName << endl;
        f << "PATRONYMIC: " << mPatronymic << endl;
        f << "AGE: " << mAge << endl;
        f << "SEX: " << mSex << endl;
        f << "COURSE: " << mCourse << endl;
        f << "AVERAGE GRADE POINT: " << mAvgGP << endl << endl;
        f.close();
    }
    return isDone;
}
bool student::appendDBBin(string &databaseName) {
    if (databaseName[databaseName.length() - 3] != 'b') {
        return false;
    }

    ofstream f;
    bool isDone = true;
    f.open("../6.3/" + databaseName, ios::app | ios::binary);
    if (!f.is_open()) {
        isDone = false;
    } else {
        f.write(reinterpret_cast<char*>(this), sizeof(student));
        f.close();
    }
    return isDone;
}

bool student::selectGoodFromAllBIN(string &databaseName, string &newDBName) {
    if (databaseName[databaseName.length() - 3] != 'b' or newDBName[newDBName.length() - 3] != 'b') {
        return false;
    }

    ifstream f;
    student *studentTMP = new student;
    student::lastID--;
    bool isDone = true;

    f.open("../6.3/"+ databaseName);
    if (!f.is_open()) {
        isDone = false;
    } else {
        while (f.read(reinterpret_cast<char *>(studentTMP), sizeof(student))) {
            if (studentTMP->mAvgGP > 7) {
                studentTMP->appendDBBin(newDBName);
            }
        }
        f.close();
    }
    return isDone;
}
bool student::selectGoodFromAll(string &databaseName, string &newDBName) {
    if (databaseName[databaseName.length() - 3] != 't' or newDBName[newDBName.length() - 3] != 't') {
        return false;
    }

    ifstream f;
    student *studentTMP = new student;
    student::lastID--;
    bool isDone = true;
    string buffer;
    int bufLen;
    char numberBuffer[10];
    int bufIndex = 0;
    bool eos = false;

    f.open("../6.3/" + databaseName);
    if (!f.is_open()) {
        isDone = false;
    } else {
        while (getline(f, buffer)) {
            if (buffer.empty() and !f.eof()) {
                continue;
            }
            bufLen = buffer.length();
            switch (buffer[0]) {
                case 'I': {
                    for (int i = 4; i < bufLen; ++i) {
                        numberBuffer[bufIndex++] = buffer[i];
                    }
                    numberBuffer[bufIndex] = 0;
                    studentTMP->mID = stoi(numberBuffer);
                    bufIndex = 0;
                    break;
                }
                case 'N': {
                    for (int i = 6; i < bufLen; ++i) {
                        studentTMP->mName[bufIndex++] = buffer[i];
                    }
                    studentTMP->mName[bufIndex] = 0;
                    bufIndex = 0;
                    break;
                }
                case 'L': {
                    for (int i = 11; i < bufLen; ++i) {
                        studentTMP->mLastName[bufIndex++] = buffer[i];
                    }
                    studentTMP->mLastName[bufIndex] = 0;
                    bufIndex = 0;
                    break;
                }
                case 'P': {
                    for (int i = 12; i < bufLen; ++i) {
                        studentTMP->mPatronymic[bufIndex++] = buffer[i];
                    }
                    studentTMP->mPatronymic[bufIndex] = 0;
                    bufIndex = 0;
                    break;
                }
                case 'A': {
                    switch (buffer[1]) {
                        case 'G': {
                            for (int i = 5; i < bufLen; ++i) {
                                numberBuffer[bufIndex++] = buffer[i];
                            }
                            numberBuffer[bufIndex] = 0;
                            studentTMP->mAge = stoi(numberBuffer);
                            bufIndex = 0;
                            break;
                        }
                        case 'V': {
                            for (int i = 21; i < bufLen; ++i) {
                                numberBuffer[bufIndex++] = buffer[i];
                            }
                            numberBuffer[bufIndex] = 0;
                            studentTMP->mAvgGP = stod(numberBuffer);
                            bufIndex = 0;
                            eos = true;
                            break;
                        }
                    }
                    break;
                }
                case 'S': {
                    studentTMP->mSex = buffer[5];
                    break;
                }
                case 'C': {
                    for (int i = 8; i < bufLen; ++i) {
                        numberBuffer[bufIndex++] = buffer[i];
                    }
                    numberBuffer[bufIndex] = 0;
                    studentTMP->mCourse = stoi(numberBuffer);
                    bufIndex = 0;
                    break;
                }
            }
            if (eos and studentTMP->mAvgGP > 6) {
                studentTMP->print();
                studentTMP->appendDB(newDBName);
                eos = false;
            }
        }
        f.close();
    }
    delete studentTMP;
    return isDone;
}
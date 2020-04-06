#include <iostream>
#include <list>
#include <vector>
#include "student.h"

using namespace std;

//Требуется вставка и удаление данных. Эти операции имеют константную сложность в list

//List - лучший выбор

void insertAlphabetically(student& person, list<student>& database);
void insertAlphabetically(student& person, vector<student>& database);

void show(list<student>& database);
void show(vector<student>& dataBase);

void cutGoodStudents(list<student>& database, list<student>& goodStudents);
void cutGoodStudents(vector<student>& database, vector<student>& goodStudents);

int main() {
    list<student> dbL;
    vector<student> dbV;
    student a; a.mSurname = "Armor"; a.mAvgGP = 4;
    student b; b.mSurname = "Brad"; b.mAvgGP = 6.45;
    student c; c.mSurname = "Coin"; c.mAvgGP = 2;
    student d; d.mSurname = "Disk"; d.mAvgGP = 10;
    student e; e.mSurname = "Enumeration"; e.mAvgGP = 6.67;
    student f; f.mSurname = "Focus"; f.mAvgGP = 5.5;

    insertAlphabetically(f, dbL);
    insertAlphabetically(a, dbL);
    insertAlphabetically(e, dbL);
    insertAlphabetically(b, dbL);
    insertAlphabetically(d, dbL);
    insertAlphabetically(c, dbL);

    insertAlphabetically(f, dbV);
    insertAlphabetically(c, dbV);
    insertAlphabetically(e, dbV);
    insertAlphabetically(b, dbV);
    insertAlphabetically(d, dbV);
    insertAlphabetically(a, dbV);

    list<student> goodStudentsL;
    vector<student> goodStudentsV;
    cout << "All List:" << endl;
    show(dbL);
    cout << "All Vector:" << endl;
    show(dbV);
    cutGoodStudents(dbL, goodStudentsL);
    cutGoodStudents(dbV, goodStudentsV);
    cout << "Good list: " << endl;
    show(goodStudentsL);
    cout << "Good vector: " << endl;
    show(goodStudentsV);
    cout << "Bad list: " << endl;
    show(dbL);
    cout << "Bad vector: " << endl;
    show(dbV);

    return 0;
}

void insertAlphabetically(student& person, list<student>& database) {
    if (database.empty()) {
        database.push_back(person);
        return;
    }

    list<student>::iterator beg = database.begin();
    list<student>::iterator end = database.end();
    --end;

    if (end->mSurname <= person.mSurname) {
        database.push_back(person);
        return;
    }
    if (beg->mSurname >= person.mSurname) {
        database.push_front(person);
        return;
    }

    for (; beg != database.end(); ++beg) {
        if (person.mSurname > beg++->mSurname and person.mSurname < beg--->mSurname) {
            database.insert(++beg, person);
            return;
        }
    }
}
void insertAlphabetically(student& person, vector<student>& database) {
    if (database.empty()) {
        database.push_back(person);
        return;
    }

    vector<student>::iterator beg = database.begin();
    vector<student>::iterator end = database.end();
    --end;

    if (end->mSurname <= person.mSurname) {
        database.push_back(person);
        return;
    }
    if (beg->mSurname >= person.mSurname) {
        database.insert(database.begin(), person);
        return;
    }

    for (; beg != database.end(); ++beg) {
        if (person.mSurname > beg++->mSurname and person.mSurname < beg--->mSurname) {
            database.insert(++beg, person);
            return;
        }
    }
}
void show(list<student>& database) {
    for (list<student>::iterator elem = database.begin(); elem != database.end(); ++elem) {
        cout << elem->mSurname << ": " << elem->mAvgGP << endl;
    }
    cout << endl;
}
void show(vector<student>& database) {
    for (vector<student>::iterator elem = database.begin(); elem != database.end(); ++elem) {
        cout << elem->mSurname << ": " << elem->mAvgGP << endl;
    }
    cout << endl;
}
void cutGoodStudents(list<student>& database, list<student>& goodStudents) {
    for (list<student>::iterator elem = database.begin(); elem != database.end() ; ++elem) {
        if (elem->mAvgGP > 6) {
            insertAlphabetically(*elem, goodStudents);
            elem = --database.erase(elem);
        }
    }
}
void cutGoodStudents(vector<student>& database, vector<student>& goodStudents) {
    for (vector<student>::iterator elem = database.begin(); elem != database.end() ; ++elem) {
        if (elem->mAvgGP > 6) {
            insertAlphabetically(*elem, goodStudents);
            elem = --database.erase(elem);
        }
    }
}
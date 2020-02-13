#include <iostream>
#include "6.3.h"

using namespace std;

int student::lastID = 0;

int main() {
    string database = "db.txt";
    string database2 = "db2.txt";
    string databaseBin = "db.bin";
    string database2Bin = "db2.bin";

    /*student students[20];
    for (int i = 0; i < 20; ++i) {
        students[i].mAvgGP = rand()%6+5;
        students[i].appendDB(database);
        students[i].appendDBBin(databaseBin);
    }*/

    student::selectGoodFromAll(database, database2);
    student::selectGoodFromAllBIN(databaseBin, database2Bin);

    return 0;
}
#include <fstream>
#include <ctime>
#include "9.1.h"

bool fileInit(char *fileName) {
    ofstream f;
    srand(time(nullptr));
    f.open(fileName);
    if (!f.is_open()) {
        return false;
    }
    for (int i = 0; i < AMOUNT; ++i) {
        f << rand() % RANGE + 1 << endl;
    }
    f.close();
    return true;
}
vector<int> getRepeats(char* fileName) {
    vector<int> range(RANGE, 0);
    vector<int> result;

    ifstream f(fileName);
    ifstream file(fileName);
    if (!file.is_open()) {
        return result;
    }
    int buffer;
    while (!file.eof()) {
        file >> buffer;
        if (range[buffer - 1] == 1) {
            range[buffer - 1] = 2;
        }
        if (range[buffer - 1] == 0) {
            range[buffer - 1] = 1;
        }
    }
    for (int j = 0; j < RANGE; ++j) {
        if (range[j] == 2) {
            result.push_back(j + 1);
        }
    }
    return result;
}
#include "8.1.h"

bool fileInit(char *fileName) {
    ofstream f;
    srand(time(nullptr));
    f.open(fileName);
    if (!f.is_open()) {
        return false;
    }
    for (int i = 0; i < AMOUNT; ++i) {
        f << rand()%RANGE+1 << endl;
    }
    f.close();
    return true;
}
vector getRepeats(char *fileName) {
    vector range(RANGE);
    vector result;
    ifstream file(fileName);
    int buffer;
    int bufferIndexInRange;
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
            result.pushBack(j + 1);
        }
    }
    return result;
}


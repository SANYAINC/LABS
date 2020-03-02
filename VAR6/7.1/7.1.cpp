#include "7.1.h"
#include "../../common/common.h"

bool createFileWithIntegers(string &name, int amount) {
    ofstream f;
    srand(time(nullptr));
    f.open("../VAR6/7.1/" + name);
    if (!f.is_open()) {
        return false;
    }
    for (int i = 0; i < amount; ++i) {
        f << rand()%RANGE+1 << endl;
    }
    f.close();
    return true;
}

int* createFileWithRepeats(string &rd) {
    ifstream fRead;
    fRead.open("../VAR6/7.1/" + rd);
    if (!fRead.is_open()) {
        return nullptr;
    }
    string buffer;
    int *range = new int[RANGE];
    for (int i = 0; i < RANGE; ++i) {
        range[i] = i + 1;
    }
    int *array = new int[2];
    array[0] = 1;
    int arrayLen = 2;
    int arrayIndex = 1;
    int bufferPos;
    int intBuffer;
    while (getline(fRead, buffer)) {
        intBuffer = stoi(buffer);
        bufferPos = arrays::find(range, intBuffer, RANGE);
        if (bufferPos != -1) {
            range[bufferPos] = 0;
        } else {
            if (arrays::find(array, intBuffer, arrayLen, 1) == -1) {
                array[arrayIndex] = intBuffer;
                arrayIndex++;
                array[0]++;
            }
            if (arrayIndex == arrayLen) {
                expandMemory(array, arrayLen, arrayLen * 2);
                arrayLen *= 2;
            }
        }
    }
    sorts::quickSort(array, arrayIndex - 1, 1);
    return array;

}

void copyArrays(int *ar1, int *ar2, int size) {
    for (int i = 0; i < size; ++i) {
        ar2[i] = ar1[1];
    }
}

void expandMemory(int *&array, int oldSize, int newSize) {
    int *newAr = new int[newSize];
    for (int i = 0; i < oldSize; ++i) {
        newAr[i] = array[i];
    }
    delete [] array;
    array = newAr;
}

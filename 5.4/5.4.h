int isInArray(int num, const int *array, int size) {

    ///Returns element's index, or -1

    for (int i = 0; i < size; ++i) {
        if (array[i] == num) {
            return i;
        }
    }
    return -1;
}

int &refMaxFib(int *array, int size) {
    int max = array[0];
    int maxIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
    }
    int fibCur = 1;
    int fibPrev = 1;
    int maxFib = 0;
    int maxFibIndex = 0;
    int curFibIndex = 0;
    while (fibCur <= max) {
        curFibIndex = isInArray(fibCur, array, size);
        if (curFibIndex != -1 and fibCur > maxFib) {
            maxFib = fibCur;
            maxFibIndex = curFibIndex;
        }
        fibCur = fibCur + fibPrev;
        fibPrev = fibCur - fibPrev;
    }
    if (!maxFib) {
        return array[maxIndex];
    } else {
        return array[maxFibIndex];
    }
}
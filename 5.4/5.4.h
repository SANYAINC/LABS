int isInArray(int num, const int *array, int size) {

    ///Returns element's index, or -1

    for (int i = 0; i < size; ++i) {
        if (array[i] == num) {
            return i;
        }
    }
    return -1;
}
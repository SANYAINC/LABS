#pragma once
#include <cstring>

template <class T>
void merge(T *array, int left, int split, int right) {
    int indexFirst = left;
    int indexSecond = split + 1;

    int indexBuf = 0;
    T *buf = new T[right - left + 1];

    while (indexFirst <= split and indexSecond <= right) {
        if (array[indexFirst] < array[indexSecond]) {
            buf[indexBuf++] = array[indexFirst++];
        } else {
            buf[indexBuf++] = array[indexSecond++];
        }
    }

    while (indexFirst <= split) {
        buf[indexBuf++] = array[indexFirst++];
    }
    while (indexSecond <= right) {
        buf[indexBuf++] = array[indexSecond++];
    }

    for (indexBuf = 0; indexBuf <= right - left; ++indexBuf) {
        array[left + indexBuf] = buf[indexBuf];
    }
}

template <class T>
void mergeSort(T * array, int right, int left = 0) {
    int split;
    if (left < right) {
        split = (left + right) / 2;

        mergeSort(array, split, left);
        mergeSort(array, right, split + 1);

        merge(array, left, split, right);
    }
}
void mergeSort(char **strings, int wordsAmount) {
    int len;
    for (int i = 0; i < wordsAmount; ++i) {
        len = strlen(strings[i]);
        mergeSort(strings[i], len - 1);
    }
}

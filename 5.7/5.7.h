#include <iostream>

using namespace std;

template <class T>
void quickSort(T *array, int &couCom, int &couMov, int right, int left = 0) {
    int leftPtr = left;
    int rightPtr = right;
    int basis = array[(leftPtr + rightPtr) / 2];
    while (leftPtr <= rightPtr) {
        while (array[leftPtr] < basis) {
            leftPtr++;
            couCom++;
        }
        couCom++;
        while (array[rightPtr] > basis) {
            rightPtr--;
            couCom++;
        }
        couCom++;
        if (leftPtr <= rightPtr) {
            swap(array[leftPtr], array[rightPtr]);
            leftPtr++;
            rightPtr--;
            couMov++;
        }
    }
    if (left < rightPtr) {
        quickSort(array, couCom, couMov, rightPtr, left);
    }
    if (right > leftPtr) {
        quickSort(array, couCom, couMov, right, leftPtr);
    }
}

template <class T>
void bubbleSort(T *array, int &couCom, int &couMov, int size) {
    int index = 0;
    int seria = 0;
    for (int i = 0; i < size - 1; ++i) {
        while (index + 1 < size) {
            if (array[index] > array[index+1]) {
                swap(array[index], array[index+1]);
                couMov++;
            } else {
                seria++;
            }
            index++;
            couCom++;
        }
        if (seria == size - 1) {
            break;
        }
        index = 0;
        seria = 0;
    }
}

template <class T>
void insertionSort(T *array, int &couCom, int &couMov, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; ++couCom and j > 0 and array[j-1] > array[j]; j--) {
            swap(array[j], array[j-1]);
            couMov++;
        }
    }
}
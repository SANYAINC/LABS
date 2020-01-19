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
void quickSort(T *array, int right, int left = 0) {
    int leftPtr = left;
    int rightPtr = right;
    int basis = array[(leftPtr + rightPtr) / 2];
    while (leftPtr <= rightPtr) {
        while (array[leftPtr] < basis) {
            leftPtr++;
        }
        while (array[rightPtr] > basis) {
            rightPtr--;
        }
        if (leftPtr <= rightPtr) {
            swap(array[leftPtr], array[rightPtr]);
            leftPtr++;
            rightPtr--;
        }
    }
    if (left < rightPtr) {
        quickSort(array, rightPtr, left);
    }
    if (right > leftPtr) {
        quickSort(array, right, leftPtr);
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
void bubbleSort(T *array, int size) {
    int index = 0;
    int seria = 0;
    for (int i = 0; i < size - 1; ++i) {
        while (index + 1 < size) {
            if (array[index] > array[index+1]) {
                swap(array[index], array[index+1]);
            } else {
                seria++;
            }
            index++;
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
template <class T>
void insertionSort(T *array, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0 and array[j-1] > array[j]; j--) {
            swap(array[j], array[j-1]);
        }
    }
}

template <class T>
void binInsertionSort(T *array, int &couCom, int &couMov, int size) {
    T temp;
    int left;
    int right;
    int mid;
    for (int i = 1;  i < size; i++)
        if (++couCom and array[i-1] > array[i]){
            temp = array[i];
            left = 0;
            right = i-1;
            do {
                mid = (left + right) / 2;
                if  (array[mid] < temp ) {
                    left = mid + 1;
                } else  {
                    right = mid - 1;
                }
                couCom++;
            } while (left <= right);
            for (int j = i-1; j>=left; j--) {
                array[j + 1] = array[j];
                couMov++;
            }
            array[left] = temp;
        }
}
template <class T>
void binInsertionSort(T *array, int size) {
    T temp;
    int left;
    int right;
    int mid;
    for (int i = 1;  i < size; i++)
        if (array[i-1] > array[i]){
            temp = array[i];
            left = 0;
            right = i-1;
            do {
                mid = (left + right) / 2;
                if  (array[mid] < temp ) {
                    left = mid + 1;
                } else  {
                    right = mid - 1;
                }
            } while (left <= right);
            for (int j = i-1; j>=left; j--) {
                array[j + 1] = array[j];
            }
            array[left] = temp;
        }
}

template <class T>
void selectionSort(T *array, int &couCom, int &couMov, int size) {
    int left = 0;
    int right = size - 1;
    int minIndex = 0;
    while (left != right) {
        for (int i = left; i <= right; ++i) {
            if (++couCom and array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        swap(array[left], array[minIndex]);
        couMov++;
        left++;
        minIndex = left;
    }
}
template <class T>
void selectionSort(T *array, int size) {
    int left = 0;
    int right = size - 1;
    int minIndex = 0;
    while (left != right) {
        for (int i = left; i <= right; ++i) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        swap(array[left], array[minIndex]);
        left++;
        minIndex = left;
    }
}

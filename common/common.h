#pragma once

template <class T> //Создание указателя на size элементов
T* createArray(int size);

template <class T> //Освобождение памяти
void deleteArray(T *array);

template <class T> //Вывести массив
void showArray(T *array, int size);

template <class T> //Заполнить массив случайными числами
void fillArrRand(T *array, int size);

template <class T> //Заполнить массив с клавиатуры
void fillArrayKeyboard(T *array, int size);

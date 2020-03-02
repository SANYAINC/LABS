#include <iostream>
#include "../../common/common.h"
#include "5.8.h"

using namespace std;


int main() {
    cout << "Please enter N: ";
    int n;
    cin >> n;
    cout << endl;

    //Создание и заполнение
    int *array = arrays::create<int>(n);
    arrays::fillRnd(array, n);

    mergeSort(array, n - 1);

    arrays::show(array, n);
    arrays::free(array);

    cout << "Please, enter number of words: ";
    int wordsAmount;
    cin >> wordsAmount;
    cout << endl;

    char **words = matrix::create<char>(wordsAmount, WORD_LEN); //Создание массива слов

    //Ввод слов с клавиатуры
    cin.get(); //Забираем из буфера \n
    for (int i = 0; i < wordsAmount; ++i) {
        cout << "Please, enter a word: ";
        cin.getline(words[i], WORD_LEN);
        cout << endl;
    }

    mergeSort(words, wordsAmount - 1);

    matrix::showWords(words, wordsAmount);
    matrix::free(words, wordsAmount);
    return 0;
}
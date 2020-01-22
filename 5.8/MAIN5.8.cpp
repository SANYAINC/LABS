#include "5.8.h"
#include "../common/common.h"
#include <limits>

using namespace std;

int main() {
    cout << "Please enter N: ";
    int n;
    cin >> n;
    cout << endl;

    int *array = arrays::createArray<int>(n);
    arrays::fillArrayRand(array, n);
    mergeSort(array, n - 1);
    arrays::showArray(array, n);
    arrays::deleteArray(array);

    cout << "Please, enter number of words: ";
    int wordsAmount;
    cin >> wordsAmount;
    cout << endl;
    cout << "Please, enter words length: ";
    int wordsLength;
    cin >> wordsLength;
    cout << endl;

    char **words = matrix::createMatrix<char>(wordsAmount, wordsLength);
    char buf[wordsLength];
    for (int i = 0; i < 3; ++i) {
        cout << "Please, enter a word: ";
        cin >> buf;
        cout << endl;
        strncpy(words[i], buf, 10);
        words[i][9] = 0;
        if (cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        }
    }
    cout << endl;
    mergeSort(words, wordsAmount);
    matrix::showWords(words, wordsAmount);
    matrix::deleteMatrix(words, wordsAmount);

    return 0;
}
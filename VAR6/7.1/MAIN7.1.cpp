#include <iostream>
#include "7.1.h"

using namespace std;

int main() {

    string s1 = "f.txt";
    createFileWithIntegers(s1, AMOUNT);

    int *repeatsAr = createFileWithRepeats(s1);
    int repeats = repeatsAr[0];

    for (int i = 1; i < repeats; ++i) {
        cout << repeatsAr[i] << ' ';
    }


    delete [] repeatsAr;
    return 0;
}
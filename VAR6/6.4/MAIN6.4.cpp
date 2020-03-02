#include <iostream>
#include <algorithm>
#include "../../common/common.h"
#include "6.4.h"
using namespace std;

const int n = 20;

int main() {
    srand(time(nullptr));


    char num[9];
    num[6] = '-';
    num[8] = 0;

    plateNumber numbersArray[n];

    printf("Union size: %d\nC-string size: %d\n\n", sizeof(numbersArray[0]), sizeof(num));

    for (int i = 0; i < n; ++i) {
        num[0] = rand()%10 + 48;
        num[1] = rand()%10 + 48;
        num[2] = rand()%10 + 48;
        num[3] = rand()%10 + 48;
        num[4] = rand()%26 + 65;
        num[5] = rand()%26 + 65;
        num[7] = rand()%7 + 49;
        numbersArray[i].setPlateNumber(num);
    }


    plateNumber::printList(numbersArray, n);
    sort(numbersArray, numbersArray + n, plateNumber::compare);
    cout << endl;
    plateNumber::printList(numbersArray, n);

    cout << endl;

    for (int i = 0; i < n; ++i) {
        if (i + 1 < n and numbersArray[i] == numbersArray[i + 1]) {
            numbersArray[i].print();
            while ((++i + 1) < n and numbersArray[i] == numbersArray[i + 1]);
            i++;
        }
    }

    return 0;
}
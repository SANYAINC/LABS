#include <iostream>
#include <algorithm>
#include "../common/common.h"
#include "6.4.h"
using namespace std;

const int n = 10000;

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

    char car1[] = "1337MK-7";
    char car2[] = "1111AZ-4";
    char carNull1[] = "?";
    char car3[] = "9999ZZ-7";
    numbersArray[0].setPlateNumber(car1);
    numbersArray[12].setPlateNumber(car1);
    numbersArray[213].setPlateNumber(car1);
    numbersArray[750].setPlateNumber(car2);
    numbersArray[3498].setPlateNumber(car2);
    numbersArray[4678].setPlateNumber(car2);
    numbersArray[456].setPlateNumber(carNull1);
    numbersArray[574].setPlateNumber(carNull1);
    numbersArray[n-1].setPlateNumber(car3);
    numbersArray[n-2].setPlateNumber(car3);


    //plateNumber::printList(numbersArray, n);
    sort(numbersArray, numbersArray + n, plateNumber::compare);
    //plateNumber::printList(numbersArray, n);

    for (int i = 0; i < n; ++i) {
        if (i + 1 < n and numbersArray[i] == numbersArray[i + 1]) {
            numbersArray[i].print();
            while ((++i + 1) < n and numbersArray[i] == numbersArray[i + 1]);
            i++;
        }
    }

    return 0;
}
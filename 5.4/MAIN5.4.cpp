#include <iostream>
#include "../common/common.h"
#include "5.4.h"
using namespace std;

int main() {
    cout << "Please, enter array size: ";
    int n;
    cin >> n;
    cout << endl;

    //Создание массива int на n элементов
    int *ar = arrays::create<int>(n);
    arrays::fillRnd(ar, n);
    //fillArrayKeyboard(ar, n);
    arrays::show(ar, n);

    int &max = refMaxFib(ar, n);
    max = 0;

    arrays::show(ar, n);

    arrays::free(ar);
    return 0;
}
#include <iostream>
#include "class.h"

using namespace std;


int main() {
    int n = 8;
    //cin >> n;
    list <int> list1(n);

    //Ввод чисел (Для проверки - (5 7 8 11 9 1 5 7) = -56)
    for (int i = 0; i < n ; ++i) {
        cin >> list1[i];
    }

    list1.print();
    cout << endl;
    cout << list1.getProd() << endl;

    system("pause");
    return 0;
}
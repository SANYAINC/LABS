#include <iostream>
#include "class.h"

using namespace std;


int main() {
    int n = 8;
    //cin >> n;
    list <int> list1(n);

    //Ввод чисел
    for (int i = 0; i < n ; ++i) {
        cin >> list1[i];
    }

    list1.print();
    cout << endl;
    cout << list1.getProd();

    return 0;
}
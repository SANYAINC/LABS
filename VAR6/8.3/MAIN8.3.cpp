#include <iostream>
#include "class.h"

using namespace std;


int main() {
    uInt d1(16);

    cout << d1;

    cout << (d1 << 3);
    cout << (d1 >> 3);

    cout << ((d1 >> 3) << 3);




    return 0;
}


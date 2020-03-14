#include <iostream>
#include "class.h"

using namespace std;


int main() {
    uInt v1(1);
    uInt v2(1);

    v1 = (v1 << 249) - (v1 << 6) + 7;
    v2 = (v2 << 108) - 1;

    cout << v1.gcd(v2);

    return 0;
}


#include <iostream>
#include "7.7.h"

using namespace std;

int main() {

    tree<int>binTree1;
    binTree1.push(5);
    binTree1.push(3);
    binTree1.push(6);
    binTree1.push(1);
    binTree1.push(8);
    binTree1.push(0);

    binTree1.show();

    cout << binTree1.find(3);
    return 0;
}
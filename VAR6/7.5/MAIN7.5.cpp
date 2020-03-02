#include <iostream>
#include "7.5.h"

using namespace std;

int main() {
    list l1(10);
    l1.pushBack('m');
    l1.pushBack('g');
    l1.pushBack('h');
    l1.pushBack('t');
    l1.pushBack('r');
    l1.pushBack('a');

    list l2(10);

    l2.pushBack('k');
    l2.pushBack('a');
    l2.pushBack('g');
    l2.pushBack('q');
    l2.pushBack('h');
    l2.pushBack('a');

    list l3(10);
    l3.pushRepeatsFrom(l1, l2);
    for (int i = 0; i < l3.getSize(); ++i) {
        cout << l3[i];
    }

    return 0;
}


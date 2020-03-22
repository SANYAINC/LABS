#include <iostream>
#include "class.h"

using namespace std;

int main() {

    graph <char> g1(7);

    g1.connect(1,4);
    g1.connect(4,6);
    g1.connect(4,2);
    g1.connect(6,5);
    g1.connect(0,1);
    g1.connect(0,5);
    g1.connect(5,3);
    g1.connect(0,3);
    g1.connect(3,2);
    g1.connect(2,0);

    g1.show();

    g1.showLongestPath();

    return 0;
}


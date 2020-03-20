#include <iostream>
#include "class.h"

using namespace std;

int main() {

    graph g1(4);
    g1.connect(0,1);
    g1.connect(1,2);
    g1.connect(2,0);
    g1.connect(2,3);

    int PTV[1] = {1};
    int PBV[2] = {0,2};

    graph g2 = g1;
    g1.pushVertex(1, PTV, 2, PBV);
    g2.removeVertex(2);

    g1.show();
    g2.show();

    return 0;
}


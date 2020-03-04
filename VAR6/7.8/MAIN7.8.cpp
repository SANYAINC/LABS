#include <iostream>
#include "7.8.h"

using namespace std;

int main() {
    graphAdjMx g1(7);
    g1.pushVertex();

    g1.show();
    g1.showLongestPath();

    system("pause");

    return 0;
}

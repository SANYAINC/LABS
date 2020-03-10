#include <iostream>
#include "7.8.h"

using namespace std;

int main() {

    graphAdjList g1(4);
    g1.show();
    cout << endl;
    g1.pushVertex();
    g1.show();
    g1.showLongestPath();

    system("pause");

    return 0;
}

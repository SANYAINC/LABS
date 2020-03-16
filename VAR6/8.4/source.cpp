#include <ostream>
#include "class.h"

using namespace std;


int main() {
    srand(time(nullptr));

    int size = 25;
    //cin >> size;
    list <char> L1(size, '0');
    list <char> L2(size, '0');

    L1.fillRandom();
    L2.fillRandom();

    L1.show();
    cout << endl;
    L2.show();
    cout << endl;

    list <char> L3;
    L3.pushRepeatsFrom(L1, L2);
    L3.show();

    cout << endl;
    system("pause");
    return 0;
}

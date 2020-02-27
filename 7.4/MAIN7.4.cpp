#include <iostream>
#include "7.4.h"

using namespace std;


int main() {

    list l1;
    l1.pushBack('s');l1.pushBack('a');l1.pushBack('n');l1.pushBack('y');l1.pushBack('a');l1.pushBack('1');l1.pushBack('5');l1.pushBack('7');
    for (int i = 0; i < l1.getSize(); ++i) {
        cout << l1[i];
    }
    cout << endl;

    list l2;
    l2.pushBack('v');l2.pushBack('a');l2.pushBack('n');l2.pushBack('5');l2.pushBack('a');l2.pushBack('2');l2.pushBack('y');l2.pushBack('a');
    for (int i = 0; i < l2.getSize(); ++i) {
        cout << l2[i];
    }
    cout << endl;


    list l3;
    l3.pushRepeatsFrom(l1, l2);
    for (int j = 0; j < l3.getSize(); ++j) {
        cout << l3[j];
    }
    return 0;
}
#include <iostream>
#include "class.h"

using namespace std;

int main() {

    tree <int> t1;
    tree <int> ::invalidData = 0;

    t1.push(56);
    t1.push(100);
    t1.push(35);
    t1.push(1);
    t1.push(48);
    t1.push(21);
    t1.push(41);
    t1.push(69);
    t1.push(18);

    tree <int> t2 = t1;

    t1.show();
    t1.showLeaves();
    t1.clear();
    t1.show();
    t1.showLeaves();

    t2.removeLeaf(18);
    t2.removeLeaf(69);
    t2.show();


    return 0;
}
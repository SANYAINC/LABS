#include <iostream>
#include "class.h"

using namespace std;

int main() {

    tree <int> t1;

    t1.push(10);
    t1.push(5);
    t1.push(13);
    t1.push(2);
    t1.push(11);
    t1.push(14);

    t1.showLeaves();
    t1.removeLeaf(2);
    t1.removeLeaf(11);
    t1.showLeaves();

    t1.clear();




    return 0;
}
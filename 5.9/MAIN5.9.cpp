#include <iostream>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board1;
    board board2;
    int cou1 = 0;
    int cou2 = 0;
    v1::solve(board1, cou1);
    v3::solve(board2, 0, cou2);
    cout << cou1 << endl << cou2;
    return 0;
}

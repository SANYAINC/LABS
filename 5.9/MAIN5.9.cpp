#include <iostream>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board;
    int cou1 = 0;
    int cou2 = 0;

    v1::solve(board, cou1);
    board.clear();
    v3::solve(board, 0, cou2);

    cout << cou1 << endl << cou2;
    return 0;
}

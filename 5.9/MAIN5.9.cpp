#include <iostream>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board;

    cout << v1::solve(board) << endl;
    board.clear();
    cout << v2::solve(board) << endl;
    board.clear();
    cout << v3::solve(board) << endl;
    board.clear();
    return 0;
}

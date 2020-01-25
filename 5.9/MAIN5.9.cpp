#include <iostream>
#include <ctime>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board;
    clock_t start = clock();

    //cout << v1::solve(board) << endl;
    board.clear();
    //cout << v2::solve(board) << endl;
    board.clear();
    //cout << v3::solve(board) << endl;
    board.clear();
    //cout << v4::solve(board) << endl;
    board.clear();

    clock_t stop = clock();
    int elapsed = (int) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %i sec.\n", elapsed);
    return 0;
}

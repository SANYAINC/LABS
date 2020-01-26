#include <iostream>
#include <ctime>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board;
    clock_t start = clock();

    cout << "Solutions found for var 1: " << v1::solve(board) << endl;
    cout << "Solutions found for var 2: " << v2::solve(board) << endl;
    cout << "Solutions found for var 3: " << v3::solve(board) << endl;
    //cout << v4::solve(board) << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %f sec.\n", elapsed);
    return 0;
}

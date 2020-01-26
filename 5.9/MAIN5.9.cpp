#include <iostream>
#include <ctime>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board;

    clock_t start = clock();
    clock_t START = start;
    cout << "Solutions found for var 1: " << v1::solve(board) << endl;
    clock_t stop = clock();
    cout << "Time: " << double ((stop - start)) / CLOCKS_PER_SEC << endl << endl;

    start = stop;
    cout << "Solutions found for var 2: " << v2::solve(board, true) << endl;
    stop = clock();
    cout << "Time: " << double ((stop - start)) / CLOCKS_PER_SEC << endl << endl;

    start = stop;
    cout << "Solutions found for var 3: " << v3::solve(board) << endl;
    stop = clock();
    cout << "Time: " << double ((stop - start)) / CLOCKS_PER_SEC << endl << endl;


    //cout << v4::solve(board) << endl;

    cout << "\n\nTotal time: " << double((stop - START)) / CLOCKS_PER_SEC << endl << endl;

    return 0;
}

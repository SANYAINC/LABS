#include <iostream>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board;
    int counter = 0;
    v1::solve(board, counter);
    cout << counter;
    return 0;
}

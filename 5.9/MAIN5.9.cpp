#include <iostream>
#include "class.h"
#include "5.9.h"

using namespace std;

int main() {
    board board;
    int counter = 0;
    v3::solve(board, 150, counter);

    return 0;
}

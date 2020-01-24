#include <iostream>
#include "5.9.h"
using namespace std;

void v3::transformNumber(int &n) {
    if (n > 92 or n < 1) {
        n = 92;
    }
}
bool v3::solve(board board, int arrangementsNumber, int &arrangementsCou, int level) {
    transformNumber(arrangementsNumber);
    if (level == 8) {
        if (arrangementsCou == arrangementsNumber) {
            return true;
        }
        cout << arrangementsCou + 1 << endl;
        arrangementsCou++;
        board.show('C');
        return true;
    }
    for (int j = 0; j < 8; ++j) {
        if (board.field[level][j].underAttackTimes == 0) {
            board.setUnit('Q', level, j);
            if (solve(board, arrangementsNumber, arrangementsCou, level + 1)) {
                board.removeUnit('Q', level, j);
                continue;
            } else {
                board.removeUnit('Q', level, j);
            }
        }
    }
    return false;
}
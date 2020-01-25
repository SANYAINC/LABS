#include "iostream"
#include "5.9.h"
using namespace std;

int v1::solve(board board) {
    int arrangementsCou = 0;
    findSolution(board, arrangementsCou);
    return arrangementsCou;
}
bool v1::findSolution(board board, int &arrangementsCou, int level) {
    if (level == N) {
        if (SHOW1) {
            cout << arrangementsCou + 1 << endl;
            board.show();
        }
        arrangementsCou++;
        return true;
    }
    for (int j = 0; j < N; ++j) {
        if (board.field[level][j].isEmpty and board.field[level][j].underAttackTimes == 0) {
            board.setUnit('R', level, j);
            if (findSolution(board, arrangementsCou, level + 1)) {
                board.removeUnit('R', level, j);
                continue;
            } else {
                board.removeUnit('R', level, j);
            }
        }
    }
    return false;
}

int v2::solve(board board) {
    int arrangementsCounter = 0;
    int bishopsCounter = 0;
    findSolution(board, arrangementsCounter, bishopsCounter);
    return arrangementsCounter;
}
bool v2::findSolution(board board, int &arrangementsNumber, int &bishopsCou, char color) {
    if (bishopsCou >= N/2) {
        color = 'B';
    }
    if (bishopsCou == N) {
        arrangementsNumber++;
        if (SHOW2) {
            board.show();
        }
        return true;
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].color == color and board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('B', m, k);
                bishopsCou++;
                if ((bishopsCou == N or bishopsCou == N/2) and !board.colorIsUnderAttack(color)) {
                    board.removeUnit('B', m, k);
                    bishopsCou--;
                    continue;
                }
                findSolution(board, arrangementsNumber, bishopsCou, color);
                board.removeUnit('B', m, k);
                bishopsCou--;
            }
        }
    }
    return false;
}

int v3::solve(board board, int n) {
    int arrangementsNumber = 0;
    if (n > 92 or n < 1) {
        n = 92;
    }
    findSolution(board, n, arrangementsNumber);
    return arrangementsNumber;
}
bool v3::findSolution(board board, int arrangementsNumber, int &arrangementsCou, int level) {
    if (level == N) {
        if (arrangementsCou == arrangementsNumber) {
            return true;
        }
        if (SHOW3) {
            cout << arrangementsCou + 1 << endl;
            board.show();
        }
        arrangementsCou++;
        return true;
    }
    for (int j = 0; j < N; ++j) {
        if (board.field[level][j].isEmpty and board.field[level][j].underAttackTimes == 0) {
            board.setUnit('Q', level, j);
            findSolution(board, arrangementsNumber, arrangementsCou, level + 1);
            board.removeUnit('Q', level, j);
        }
    }
    return false;
}

int v4::solve(board board) {
    int arrangementsNumber = 0;
    int queensSet = 0;
    findSolution(board, arrangementsNumber, queensSet);
    return arrangementsNumber;
}
bool v4::findSolution(board board, int &arrangementsNumber, int &queensCou) {
    if (queensCou == 5) {
        arrangementsNumber++;
        if (SHOW4) {
            board.show();
        }
        return true;
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('Q', m, k);
                queensCou++;
                if (queensCou == 5 and !board.fieldIsUnderAttack()) {
                    board.removeUnit('Q', m, k);
                    queensCou--;
                    continue;
                }
                findSolution(board, arrangementsNumber, queensCou);
                board.removeUnit('Q', m, k);
                queensCou--;
            }
        }
    }
    return false;
}
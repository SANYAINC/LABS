#include "iostream"
#include "5.9.h"
using namespace std;

int v1::solve(board board) {
    int arrangementsCou = 0;
    findSolution(board, arrangementsCou);
    return arrangementsCou;
}
bool v1::findSolution(board board,int &arrangementsCou, int level) {
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
    solutions solutions;
    solveForWhite(board, solutions, arrangementsCounter, bishopsCounter);
    //arrangementsCounter - число всех расстоновок полученных бектрекингом, содержит копии решений
    //solutions.index - число уникальных решений
    return solutions.index;
}
bool v2::solveForBlack(board board, solutions &sols, int &arrangementsNumber, int &bishopCou) {
    if (N == 1) {
        arrangementsNumber++;
        return true;
    }
    if (bishopCou == N) {
        return board.colorIsUnderAttack('B');
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].color == 'B' and board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('B', m, k);
                bishopCou++;
                if (solveForBlack(board, sols, arrangementsNumber, bishopCou)) {
                    if (sols.appendSolution(board)) {
                        if (SHOW2) {
                            cout << sols.index << endl;
                            board.show();
                        }
                    }
                    arrangementsNumber++;
                    board.removeUnit('B', m, k);
                    bishopCou--;
                } else {
                    board.removeUnit('B', m, k);
                    bishopCou--;
                }
            }
        }
    }
    return false;
}
bool v2::solveForWhite(board board, solutions &sols, int &arrangementsNumber, int &bishopCou) {
    if (N != 5) {
        if (bishopCou == N / 2) {
            return board.colorIsUnderAttack('W');
        }
    } else {
        if (bishopCou == N / 2 + 1) {
            return board.colorIsUnderAttack('W');
        }
    }

    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].color == 'W' and board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('B', m, k);
                bishopCou++;
                if (solveForWhite(board, sols, arrangementsNumber, bishopCou)) {
                    solveForBlack(board, sols, arrangementsNumber, bishopCou);
                    board.removeUnit('B', m, k);
                    bishopCou--;
                } else {
                    board.removeUnit('B', m, k);
                    bishopCou--;
                }
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
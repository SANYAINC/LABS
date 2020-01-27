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

int v2::solve(board &board, bool areUnderAttack) {
    int bishopsCounter = 0;
    solutions sols;
    if (areUnderAttack) {
        solveExpanded(board, sols, bishopsCounter);
    } else {
        solveForWhite(board, sols, bishopsCounter);
    }
    return sols.index;
}
bool v2::solveForBlack(board &board, solutions &sols, int &bishopCou) {
    if (N == 1) {
        sols.index++;
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
                if (solveForBlack(board, sols, bishopCou)) {
                    if (sols.appendSolution(board)) {
                        if (SHOW2) {
                            cout << sols.index << endl;
                            board.show();
                        }
                    }
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
bool v2::solveForWhite(board &board, solutions &sols, int &bishopCou) {
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
                if (solveForWhite(board, sols, bishopCou)) {
                    solveForBlack(board, sols, bishopCou);
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
bool v2::solveExpanded(board &board, solutions &sols, int &bishopCou) {
    if (bishopCou == N) {
        return board.fieldIsUnderAttack();
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].isEmpty) {
                board.setUnit('B', m, k);
                bishopCou++;
                if (solveExpanded(board, sols, bishopCou) and sols.appendSolution(board)) {
                    if (SHOW2) {
                        cout << sols.index << endl;
                        board.show();
                    }
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

int v3::solve(board &board, int n) {
    int arrangementsNumber = 0;
    if (n > 92 or n < 1) {
        n = 92;
    }
    findSolution(board, n, arrangementsNumber);
    return arrangementsNumber;
}
bool v3::findSolution(board &board, int arrangementsNumber, int &arrangementsCou, int level) {
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

int v4::solve(board &board) {
    int queensSet = 0;
    solutions sols;
    findSolution(board, sols, queensSet);
    return sols.index;
}
bool v4::findSolution(board &board, solutions &sols, int &queensCou) {
    /*if (sols.index == 1) {
        return false;
    }*/
    if (queensCou == Q_NUMBER4) {
        return board.fieldIsUnderAttack();
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].isEmpty) {
                board.setUnit('Q', m, k);
                queensCou++;
                if (findSolution(board, sols, queensCou) and sols.appendSolution(board)) {
                    if (SHOW4) {
                        board.show();
                    }
                }
                board.removeUnit('Q', m, k);
                queensCou--;
            }
        }
    }
    return false;
}
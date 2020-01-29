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
            findSolution(board, arrangementsCou, level + 1);
            board.removeUnit('R', level, j);
        }
    }
    return false;
}

int v2::solve(board &board) {
    int bishopsCounter = 0;
    solutions sols;
    solveForWhite(board, sols, bishopsCounter);
    return sols.index;
}
bool v2::solveForBlack(board &board, solutions &sols, int &bishopCou) {
    if (sols.index == 1) {
        return false;
        //Находить только одно решение
    }
    if (bishopCou == N) {
        return board.colorIsUnderAttack('B');
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].color == 'B' and board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('B', m, k);
                bishopCou++;
                if (solveForBlack(board, sols, bishopCou) and sols.appendSolution(board)) {
                    if (SHOW2) {
                        cout << sols.index << endl;
                        board.show();
                    }
                }
                board.removeUnit('B', m, k);
                bishopCou--;
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
                }
                board.removeUnit('B', m, k);
                bishopCou--;
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
    if (sols.index == 1) {
        return false;
        //Находить одно решение
    }
    if (queensCou == Q_NUMBER4) {
        return board.fieldIsUnderAttack();
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('Q', m, k);
                queensCou++;
                if (findSolution(board, sols, queensCou) and sols.appendSolution(board)) {
                    if (SHOW4) {
                        cout << sols.index << endl;
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

int v5::solve(board board) {
    int arrangementsNumber = 0;
    int step = 1;
    int solsTotal = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            findSolution(board, arrangementsNumber, step, i, j);
            if (arrangementsNumber == 1) {
                return 1;
            }
            solsTotal += arrangementsNumber;
            step = 1;
            arrangementsNumber = 0;
            board.clear();
        }
    }
    return solsTotal;
}
bool v5::findSolution(board &board, int &arrangementsNumber, int &step, int i0, int j0, int iPrev, int jPrev) {
    if (arrangementsNumber == 1) {
        return false;
    }
    if (!board.movesExistTR(iPrev, jPrev)) {
        return board.finishedTR();
    }
    if (step == 1) {
        board.field[i0][j0].underAttackTimes = 1;
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 1) {
                board.field[m][k].isEmpty = false;
                board.field[m][k].stepNumber = step;
                step++;
                board.markSpotsTR(m, k);
                if (step != 2) {
                    board.unmarkSpots(iPrev, jPrev);
                } else {
                    board.field[i0][j0].underAttackTimes = 0;
                }
                //TODO Можно оптимизировать (помеять местами i0 j0 с m k)
                if (findSolution(board, arrangementsNumber, step, i0, j0, m, k)) {
                    arrangementsNumber++;
                    if (SHOW5) {
                        cout << arrangementsNumber << endl;
                        board.showTR();
                    }
                }
                board.field[m][k].isEmpty = true;
                board.field[m][k].stepNumber = 0;
                step--;
                board.unmarkSpots(m, k);
                board.markSpotsTR(iPrev, jPrev);
            }
        }
    }
    return false;
}

int v6::solve(board board) {
    solutions sols;
    int knightCou = 0;
    solveForWhite(board, sols, knightCou);
    return sols.index;
}
bool v6::solveForWhite(board &board, solutions &sols, int knightCou) {
    switch (N) {
        case 1: {
            sols.index++;
            return true;
        }
        case 5: {
            if (knightCou == 1) {
                return true;
            }
            break;
        }
        default: {
            if (knightCou == N_UNITS / 2) {
                return true;
            }
        }
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].color == 'W' and board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('K', m, k);
                //board.show();
                knightCou++;
                if (solveForWhite(board, sols, knightCou)) {
                    solveForBlack(board, sols, knightCou);
                }
                board.removeUnit('K', m, k);
                //board.show();
                knightCou--;
            }
        }
    }
    return false;
}
bool v6::solveForBlack(board &board, solutions &sols, int knightCou) {
    if (sols.index == 1) {
        return false;
    }
    if (knightCou == N_UNITS) {
        return board.fieldIsUnderAttack();
    }
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (board.field[m][k].color == 'B' and board.field[m][k].isEmpty and board.field[m][k].underAttackTimes == 0) {
                board.setUnit('K', m, k);
                //board.show();
                knightCou++;
                if (solveForBlack(board, sols, knightCou) and sols.appendSolution(board)) {
                    if (SHOW6) {
                        cout << sols.index << endl;
                        board.show();
                    }
                    return true;
                }
                board.removeUnit('K', m, k);
                //board.show();
                knightCou--;
            }
        }
    }
    return false;
}
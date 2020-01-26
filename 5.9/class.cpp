#include <iostream>
#include "class.h"

#define track static_cast<char>(126)
#define unit static_cast<char>(253)
#define black static_cast<char>(176)
#define white static_cast<char>(178)

using namespace std;


square::square() {
    isEmpty = true;
    underAttackTimes = 0;
    color = 'W';
}
board::board() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i + j) % 2 != 0) {
                field[i][j].color = 'B';
            }
        }
    }
}
solutions::solutions() {
    index = 0;
    for (int k = 0; k < MAX_SOLUTIONS_STORED; ++k) {
        for (int i = 0; i < N; ++i) {
            solutionsStorage[k][i][0] = 0;
            solutionsStorage[k][i][1] = 0;
        }
    }
}

void board::show(char type) {
    switch (type) {
        case 'C': {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (!field[i][j].isEmpty) {
                        cout << unit << ' ';
                    } else if (field[i][j].color == 'W') {
                        cout << white << ' ';
                    } else if (field[i][j].color == 'B'){
                        cout << black << ' ';
                    } else {
                        cout << 'O' << ' ';
                    }
                }
                cout << endl;
            }
            cout << endl;
            break;
        }
        case 'T': {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (!field[i][j].isEmpty) {
                        cout << unit << ' ';
                    } else if (field[i][j].underAttackTimes > 0) {
                        cout << track << ' ';
                    } else if (field[i][j].color == 'W') {
                        cout << white << ' ';
                    } else if (field[i][j].color == 'B'){
                        cout << black << ' ';
                    } else {
                        cout << 'O' << ' ';
                    }
                }
                cout << endl;
            }
            cout << endl;
            break;
        }
    }
}
void board::setUnit(char type, int i, int j) {
    switch (type) {
        case 'Q': {
            field[i][j].isEmpty = false;
            for (int m = 0; m < N; ++m) {
                if (m != i) {
                    field[m][j].underAttackTimes++;
                }
                if (m != j) {
                    field[i][m].underAttackTimes++;
                }
                for (int k = 0; k < N; ++k) {
                    if (m + k == i + j and m != i and k != j) {
                        field[m][k].underAttackTimes++;
                    }
                    if (m - k == i - j and m != i and k != j) {
                        field[m][k].underAttackTimes++;
                    }
                }
            }
            break;
        }
        case 'R': {
            field[i][j].isEmpty = false;
            for (int m = 0; m < N; ++m) {
                if (m != i) {
                    field[m][j].underAttackTimes++;
                }
                if (m != j) {
                    field[i][m].underAttackTimes++;
                }
            }
            break;
        }
        case 'B': {
            field[i][j].isEmpty = false;
            for (int m = 0; m < N; ++m) {
                for (int k = 0; k < N; ++k) {
                    if (m + k == i + j and m != i and k != j) {
                        field[m][k].underAttackTimes++;
                    }
                    if (m - k == i - j and m != i and k != j) {
                        field[m][k].underAttackTimes++;
                    }
                }
            }
        }
        break;
    }
}
void board::removeUnit(char type, int i, int j) {
    switch (type) {
        case 'Q': {
            field[i][j].isEmpty = true;
            for (int m = 0; m < N; ++m) {
                if (m != i) {
                    field[m][j].underAttackTimes--;
                }
                if (m != j) {
                    field[i][m].underAttackTimes--;
                }
                for (int k = 0; k < N; ++k) {
                    if (m + k == i + j and m != i and k != j) {
                        field[m][k].underAttackTimes--;
                    }
                    if (m - k == i - j and m != i and k != j) {
                        field[m][k].underAttackTimes--;
                    }
                }
            }
            break;
        }
        case 'R': {
            field[i][j].isEmpty = true;
            for (int m = 0; m < N; ++m) {
                if (m != i) {
                    field[m][j].underAttackTimes--;
                }
                if (m != j) {
                    field[i][m].underAttackTimes--;
                }
            }
            break;
        }
        case 'B': {
            field[i][j].isEmpty = true;
            for (int m = 0; m < N; ++m) {
                for (int k = 0; k < N; ++k) {
                    if (m + k == i + j and m != i and k != j) {
                        field[m][k].underAttackTimes--;
                    }
                    if (m - k == i - j and m != i and k != j) {
                        field[m][k].underAttackTimes--;
                    }
                }
            }
            break;
        }
    }
}
bool board::colorIsUnderAttack(char color) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j].color == color and (field[i][j].isEmpty and field[i][j].underAttackTimes == 0)) {
                return false;
            }
        }
    }
    return true;
}
bool board::fieldIsUnderAttack() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j].isEmpty and field[i][j].underAttackTimes == 0) {
                return false;
            }
        }
    }
    return true;
}

bool solutions::appendSolution(board &board) {
    int unitIndex = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!board.field[i][j].isEmpty) {
                solutionsBuffer[unitIndex][0] = i;
                solutionsBuffer[unitIndex][1] = j;
                unitIndex++;
            }
        }
    }
    int similarityIndex = 0;
    for (int k = 0; k < index; ++k) {
        for (int i = 0; i < N; ++i) {
            if (solutionsStorage[k][i][0] == solutionsBuffer[i][0]
                and solutionsStorage[k][i][1] == solutionsBuffer[i][1]) {
                similarityIndex++;
            }
        }
        if (similarityIndex == N) {
            return false;
        }
        similarityIndex = 0;
    }
    for (int i = 0; i < N; ++i) {
        solutionsStorage[index][i][0] = solutionsBuffer[i][0];
        solutionsStorage[index][i][1] = solutionsBuffer[i][1];
    }

    for (int i = 0; i < N; ++i) {
        solutionsBuffer[i][0] = 0;
        solutionsBuffer[i][1] = 0;
    }
    index++;
    return true;


}


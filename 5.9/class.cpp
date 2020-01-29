#include <iostream>
#include <cmath>
#include <iomanip>
#include "class.h"

#define track static_cast<char>(250)
#define unit static_cast<char>(206)
#define black static_cast<char>(176)
#define white static_cast<char>(178)

using namespace std;

square::square() {
    isEmpty = true;
    underAttackTimes = 0;
    color = 'W';
    stepNumber = 0;
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
}

//------
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
        default: {
            cout << "DEFAULT" << endl;
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
            break;
        }
        case 'K': {
            field[i][j].isEmpty = false;
            for (int m = 0; m < N; ++m) {
                for (int k = 0; k < N; ++k) {
                    if (abs(sqrt((m-i)*(m-i)+(k-j)*(k-j)) - 2.236) < 1E-3) {
                        field[m][k].underAttackTimes++;
                    }
                }
            }
            break;
        }
        default: {
            cout << "DEFAULT" << endl;
        }
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
        case 'K': {
            field[i][j].isEmpty = true;
            for (int m = 0; m < N; ++m) {
                for (int k = 0; k < N; ++k) {
                    if (abs(sqrt((m-i)*(m-i)+(k-j)*(k-j)) - 2.236) < 1E-3) {
                        field[m][k].underAttackTimes--;
                    }
                }
            }
            break;
        }
        default: {
            cout << "DEFAULT" << endl;
        }
    }
}
bool board::colorIsUnderAttack(char color) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j].color == color and field[i][j].isEmpty and field[i][j].underAttackTimes == 0) {
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

void board::showTR() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j].stepNumber != 0) {
                cout << setw(3) << field[i][j].stepNumber;
            } else if (field[i][j].underAttackTimes > 0) {
                cout << setw(3) << track;
            } else if (field[i][j].color == 'W') {
                cout << setw(3) << white;
            } else if (field[i][j].color == 'B') {
                cout << setw(3) << black;
            }
        }
        cout << endl;
    }
    cout << endl;
}
void board::markSpotsTR(int i, int j) {
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (abs(sqrt((m-i)*(m-i)+(k-j)*(k-j)) - 2.236) < 1E-3) {
                field[m][k].underAttackTimes = 1;
            }
        }
    }
}
void board::unmarkSpots(int i, int j) {

    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (abs(sqrt((m-i)*(m-i)+(k-j)*(k-j)) - 2.236) < 1E-3) {
                field[m][k].underAttackTimes = 0;
            }
        }
    }
}
bool board::finishedTR() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j].stepNumber == 0) {
                return false;
            }
        }
    }
    return true;
}
bool board::movesExistTR(int i, int j) {
    for (int m = 0; m < N; ++m) {
        for (int k = 0; k < N; ++k) {
            if (field[m][k].stepNumber == 0 and abs(sqrt((m-i)*(m-i)+(k-j)*(k-j)) - 2.236) < 1E-3) {
                return true;
            }
        }
    }
    return false;
}

void board::clear(){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            field[i][j].underAttackTimes = 0;
            field[i][j].stepNumber = 0;
            field[i][j].isEmpty = true;
        }
    }
}
//-----

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


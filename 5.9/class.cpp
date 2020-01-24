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
board::board() : square() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 != 0) {
                field[i][j].color = 'B';
            }
        }
    }
}

void board::show(char type) {
    switch (type) {
        case 'C': {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
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
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
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
            for (int m = 0; m < 8; ++m) {
                if (m != i) {
                    field[m][j].underAttackTimes++;
                }
                if (m != j) {
                    field[i][m].underAttackTimes++;
                }
                for (int k = 0; k < 8; ++k) {
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
    }
}
void board::removeUnit(char type, int i, int j) {
    switch (type) {
        case 'Q': {
            field[i][j].isEmpty = true;
            for (int m = 0; m < 8; ++m) {
                if (m != i) {
                    field[m][j].underAttackTimes--;
                }
                if (m != j) {
                    field[i][m].underAttackTimes--;
                }
                for (int k = 0; k < 8; ++k) {
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


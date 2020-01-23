#include <iostream>
#include "5.9.h"

#define track static_cast<char>(126)
#define unit static_cast<char>(253)
#define black static_cast<char>(176)
#define white static_cast<char>(178)

using namespace std;


square::square() {
    this->isEmpty = true;
    this->underAttackTimes = 0;
    this->color = 'W';
}
board::board() : square() {
    colorize();
}

void board::colorize() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 != 0) {
                this->field[i][j].color = 'B';
            }
        }
    }
}
void board::show(char type) {
    switch (type) {
        case 'C': {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (!this->field[i][j].isEmpty) {
                        cout << unit << ' ';
                    } else if (this->field[i][j].color == 'W') {
                        cout << white << ' ';
                    } else {
                        cout << black << ' ';
                    }
                }
                cout << endl;
            }
            break;
        }
        case 'T': {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (!this->field[i][j].isEmpty) {
                        cout << unit << ' ';
                    } else if (this->field[i][j].underAttackTimes > 0) {
                        cout << track << ' ';
                    } else if (this->field[i][j].color == 'W') {
                        cout << white << ' ';
                    } else {
                        cout << black << ' ';
                    }
                }
                cout << endl;
            }
            break;
        }
    }
}


#pragma once
#define N 8
#define SHOW false

class square {
public:
    bool isEmpty;
    int underAttackTimes;
    char color;

    square();
};

class board : square {
public:
    square field[N][N];

    board();

    void show(char type = 'T');
    void setUnit(char type, int i, int j);
    void removeUnit(char type, int i, int j);
    bool colorIsUnderAttack(char color);
    void clear();
};
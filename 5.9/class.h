#pragma once

class square {
public:
    bool isEmpty;
    int underAttackTimes;
    char color;

    square();
};

class board : square {
public:
    square field[8][8];

    board();

    void show(char type);
    void setUnit(char type, int i, int j);
    void removeUnit(char type, int i, int j);
};
#pragma once
#define N 6
#define MAX_SOLUTIONS_STORED 70000
#define SHOW1 false
#define SHOW2 false
#define SHOW3 false
#define SHOW4 false

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
    bool fieldIsUnderAttack();
};

class solutions : board {
public:
    board arrangements[MAX_SOLUTIONS_STORED];
    int index;

    solutions();

    bool appendSolution(board board);
};

class solution {
public:
    int solutions[MAX_SOLUTIONS_STORED][N][2];
};
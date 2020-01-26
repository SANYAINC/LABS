#pragma once
#define N 6
#define MAX_SOLUTIONS_STORED 100000
#define SHOW_TYPE 'C'
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

class board {
public:
    square field[N][N];

    board();

    void show(char type = SHOW_TYPE);
    void setUnit(char type, int i, int j);
    void removeUnit(char type, int i, int j);
    bool colorIsUnderAttack(char color);
    bool fieldIsUnderAttack();
};


class solutions {
public:
    int solutionsStorage[MAX_SOLUTIONS_STORED][N][2];
    int solutionsBuffer[N][2];
    int index;

    solutions();

    bool appendSolution(board &board);
};
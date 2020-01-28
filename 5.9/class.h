#pragma once
#define N 8
#define Q_NUMBER4 5
#define MAX_SOLUTIONS_STORED 1000000
#define SHOW_TYPE 'T'
#define SHOW1 false
#define SHOW2 true
#define SHOW3 false
#define SHOW4 true
#define SHOW5 true

class square {
public:
    bool isEmpty;
    int underAttackTimes;
    char color;
    int stepNumber;

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

    void showTR();
    void markSpotsTR(int i, int j);
    void unmarkSpots(int i, int j);
    bool finishedTR();
    bool movesExistTR(int i, int j);

    void clear();
};

class solutions {
public:
    int solutionsStorage[MAX_SOLUTIONS_STORED][N][2] = {0};
    int solutionsBuffer[N][2] = {0};
    int index;

    solutions();

    bool appendSolution(board &board);
};
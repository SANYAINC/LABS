#pragma once
#define MAX_SOLUTIONS_STORED 100000
#define SHOW_TYPE 'T'
#define N 6 //6x6 время 10 секунд //8х8 время 5 минут кроме 6го варианта
#define N_UNITS 10
#define SHOW1 false
#define SHOW2 true
#define SHOW3 false
#define Q_NUMBER4 5
#define SHOW4 true
#define SHOW5 true
#define SHOW6 true

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
    int solutionsStorage[MAX_SOLUTIONS_STORED][N_UNITS][2] = {0};
    int solutionsBuffer[N_UNITS][2] = {0};
    int index;

    solutions();

    bool appendSolution(board &board);
};
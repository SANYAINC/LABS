#pragma once
#define MAX_SOLUTIONS_STORED 100000
#define SHOW_TYPE 'T' //T - следы, C - цвет
#define N 8 // 331 сек

#define N_UNITS 12 //8x8 - 12, 6x6 - 8
#define Q_NUMBER4 5 //8x8 - 5, 6x6 - 4

#define SHOW1 false
#define SHOW2 true
#define SHOW3 true
#define SHOW4 true
#define SHOW5 true
#define SHOW6 true

class square {
public:
    bool isEmpty;           //Пуста ли клетка
    int underAttackTimes;   //Сколько фигур атакуют эту клетку
    char color;             //Цвет клетки
    int stepNumber;         //Номер шага хода коня

    square();
};

class board {
public:
    square field[N][N];     //Доска

    board();

    void show(char type = SHOW_TYPE);           //Показать доску
    void setUnit(char type, int i, int j);      //Поставить фигуру
    void removeUnit(char type, int i, int j);   //Убрать фигуру
    bool colorIsUnderAttack(char color);        //Все ли клетки цвета под ударом
    bool fieldIsUnderAttack();                  //Все ли поле под ударом

    bool checkWhitePos();                       //Проверить расстановку коней

    void showTR();                      //Показать доску с номерами шагов
    void markSpotsTR(int i, int j);     //Пометить возможные точки хода коня
    void hideSpotsTR(int i, int j);     //Убрать возможные точки хода коня
    bool finishedTR();                  //Закончен ли обход конем
    bool movesExistTR(int i, int j);    //Существуют ли ходы коня

    void clear();
};

class solutions {
public:
    int solutionsStorage[MAX_SOLUTIONS_STORED][N_UNITS][2] = {0}; //Хранилище уникальных расстановок фигур в координатах
    int solutionsBuffer[N_UNITS][2] = {0};  //Буфер для перевода типа board в координаты
    int index;  //Количество расстановок

    solutions();

    bool appendSolution(board &board); //Попытаться добавить расстановку в хранилище
};
#pragma once
#include "class.h"

namespace v1 {
    //Решено
    // < 1 сек.
    int solve(board board);
    bool findSolution(board board, int &arrangementsCou, int level = 0);
}

namespace v2 {
    //Решено
    //Оптимизировано с ~55 минут до 7.2 минут (8х8) с условиет что они не бьют друг друга
    //Если нет условия они могу бить дргу дргуа, то для доски 8х8 время > 120 мин
    //Для доски 6х6 320 сек
    int solve(board &board, bool areNotUnderAttack);
    bool solveForWhite(board &board, solutions &sols, int &bishopCou);
    bool solveForBlack(board &board, solutions &sols, int &bishopCou);
    bool solveExpanded(board &board, solutions &sols, int &bishopCou);
}

namespace v3 {
    //Решено
    // < 1 сек.
    int solve(board &board, int n = 92);
    bool findSolution(board &board, int arrangementsNumber, int &arrangementsCou, int level = 0);
}

namespace v4 {
    //Не решено
    int solve(board board);
    bool findSolution(board board, int &arrangementsNumber, int &queensCou);
}

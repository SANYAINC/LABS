#pragma once
#include "class.h"

namespace v1 {
    //Решено
    int solve(board board);
    bool findSolution(board board, int &arrangementsCou, int level = 0);
}

namespace v2 {
    //Решено
    int solve(board &board);
    bool solveForWhite(board &board, solutions &sols, int &bishopCou);
    bool solveForBlack(board &board, solutions &sols, int &bishopCou);
}

namespace v3 {
    //Решено
    int solve(board &board, int n = 92);
    bool findSolution(board &board, int arrangementsNumber, int &arrangementsCou, int level = 0);
}

namespace v4 {
    //Решено
    int solve(board &board);
    bool findSolution(board &board, solutions &sols, int &queensCou);
}

namespace v5 {
    //Решено
    int solve(board board);
    bool findSolution(board &board, int &arrangementsNumber, int &step, int i0 = 0, int j0 =0, int iPrev = 0, int jPrev = 0);
}

namespace v6 {
    //Решено
    int solve(board board);
    bool solveForWhite(board &board, solutions &sols, int &knightCou);
    bool solveForBlack(board &board, solutions &sols, int &knightCou);
}
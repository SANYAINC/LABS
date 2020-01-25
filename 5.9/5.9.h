#pragma once
#include "class.h"

namespace v1 {
    int solve(board board);
    bool findSolution(board board, int &arrangementsCou, int level = 0);
}

namespace v2 {
    //Неоптимизирован, возможно не точное кол-во решений.
    //Решение ~70 сек
    int solve(board board);
    bool findSolution(board board, int &arrangementsNumber, int &bishopsCou, char color = 'W');
}

namespace v3 {
    int solve(board board, int n = 92);
    bool findSolution(board board, int arrangementsNumber, int &arrangementsCou, int level = 0);
}

namespace v4 {
    //Не решено
    int solve(board board);
    bool findSolution(board board, int &arrangementsNumber, int &queensCou);
}

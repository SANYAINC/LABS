#pragma once
#include "class.h"

namespace v1 {
    int solve(board board);
    bool findSolution(board board, int &arrangementsCou, int level = 0);
}

namespace v3 {
    int solve(board board, int n = 92);
    bool findSolution(board board, int arrangementsNumber, int &arrangementsCou, int level = 0);
}

namespace v2 {
    int solve(board board);
    bool findSolution(board board, int &arrangementsNumber, int &bishopsCou, char color = 'W');
}

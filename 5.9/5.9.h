#pragma once
#include "class.h"

namespace v1 {
    bool solve(board board, int &arrangementsCou, int level = 0);
}

namespace v3 {
    void transformNumber(int &n);
    bool solve(board board, int arrangementsNumber, int &arrangementsCou, int level = 0);
}


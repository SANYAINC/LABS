#pragma once
#include "class.h"

namespace v1 {
    int solve(board board);
    bool findSolution(board board, int &arrangementsCou, int level = 0);
}

namespace v2 {
    int solve(board board);
    bool findSolution(board board, int &arrangementsNumber, int &bishopsCou, char color = 'W');
}

namespace v3 {
    /*TODO убрать условие чтобы все цвета были заполнены, тк в задче подразумевается
     * что свободные поля могут быть не под ударом. Главное чтобы ладей было 8 и они друг друга не били
     */
    int solve(board board, int n = 92);
    bool findSolution(board board, int arrangementsNumber, int &arrangementsCou, int level = 0);
}

namespace v4 {
    /*TODO
     * Аналог 3 варианта, но теперь ферзей будет 5, и каждое свободное поле должно быть под ударом
     */
}

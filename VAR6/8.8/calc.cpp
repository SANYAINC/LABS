#include "calc.h"

using namespace std;

matrix matrixCreate() {
    int row, col;
    cout << "Please, specify height of your matrix: ";
    input(row, "Please, enter correct height: ", 0, MAX_SIZE);
    cout << "Please, specify width of your matrix: ";
    input(col, "Please, enter correct width: ", 0, MAX_SIZE);
    matrix newMatrix(row, col);

    cout << "Please, specify filling type of your matrix (0 - random, 1 - via keyboard, 2 - identity matrix): ";
    int fillingType;
    input(fillingType, "Please, enter correct filling type (0-2): ", 0, 2);
    cout << endl;
    switch (fillingType) {
        case 0: {
            newMatrix.fillRandom();
            break;
        }
        case 1: {
            newMatrix.fillKeyboard();
            break;
        }
        case 2: {
            newMatrix.fillIdentity();
            break;
        }
        default:{}
    }
    system("cls");
    return newMatrix;
}
int getOption() {
    int buf;
    cout << "Option #";
    input(buf, "Please, choose correct option (0-11): ", 0, 11);
    cout << endl;
    return buf;
}
void save(matrix& result, matrix& main) {
    int saveToMainMatrix;
    cout << "Would you save result to main matrix? (0/1): ";
    input(saveToMainMatrix, "Please, choose correct option (0-1): ", 0, 1);
    if (saveToMainMatrix) {
        main = result;
    }
    cout << endl << endl;
}
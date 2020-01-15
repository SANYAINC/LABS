#include <iostream>
#include "5.5.h"
#include "../common/common.h"
using namespace std;

int main() {
    //Указатели на функции
    double (*f1)(char, double) = &function;
    double (*f2)(char, double, double) = &function;

    //Тест с первой функцией
    cout << "----------------------------------------------------------------------\n";

    printTableHeader(0);

    cout << "Newton\n";
    solveNewton(f1);
    cout << "Half Division\n";
    solveHalfDivision(f1);
    cout << "Chords\n";
    solveChords(f1);

    //Тест со второй функцией
    cout << "\n----------------------------------------------------------------------\n";

    printTableHeader(1);

    cout << "Newton\n";
    solveNewton(f2);
    cout << "\nHalf division\n";
    solveHalfDivision(f2);
    cout << "\nChords\n";
    solveChords(f2);

    cout << "\n----------------------------------------------------------------------\n";
    return 0;

}

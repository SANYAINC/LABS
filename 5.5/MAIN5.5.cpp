#include <iostream>
#include "5.5.h"
#include "../common/common.h"
using namespace std;

int main() {
    //Указатели на функции
    double (*f1)(char, double) = &function;
    double (*f2)(char, double, double) = &function;

    cout << "----------------------------------------------------------------------\n";

    printTableHeader(0);

    cout << "Newton\n";
    solveNewton(f1);
    cout << "Half Division\n";
    solveHalfDivision(f1);
    cout << "Chords\n";
    solveChords(f1);

    cout << "\n----------------------------------------------------------------------\n";

    printTableHeader(1);

    cout << "Newton\n";
    solveNewton(f2);
    cout << "\n";
    cout << "Half division\n";
    solveHalfDivision(f2);
    cout << "\n";
    cout << "Chords\n";
    solveChords(f2);

    cout << "\n----------------------------------------------------------------------\n";
    return 0;

}

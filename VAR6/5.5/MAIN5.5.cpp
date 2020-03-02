#include <iostream>
#include "5.5.h"
using namespace std;

//Сдано
int main() {
    //Указатели на функции
    double (*f1)(char, double) = &function;
    double (*f2)(char, double, double) = &function;

    //Тест с первой функцией
    cout << "----------------------------------------------------------------------\n";

    printTableHeader(0); //Шапка без параметра
    solveNewton(f1);

    //Тест со второй функцией
    cout << "\n----------------------------------------------------------------------\n";

    printTableHeader(1); //Шапка с параметром
    solveNewton(f2);

    cout << "\n----------------------------------------------------------------------\n";
    return 0;

}

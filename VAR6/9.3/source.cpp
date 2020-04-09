#include <iostream>
#include "expression.h"

#define MAX_CHAR 100

using namespace std;

int main() {
    char exprInit[] = " 6 +(5.45-2.45) *2- 3/(7.3 + 4.7) ";
    char exprKbrd[MAX_CHAR];
    cout << "Init expression: " << exprInit << endl;
    cout << "Please, enter your expression: ";
    cin.getline(exprKbrd, MAX_CHAR);


    expression expr(exprInit);

    cout << "Init expression" << endl;
    expr.show();
    cout << endl;
    expr.convertToRPN();

    cout << expr.calculate() << endl << endl;

    expression expr2(exprKbrd);
    cout << "Your expression" << endl;
    expr2.show();
    cout << endl;
    expr2.convertToRPN();
    cout << expr2.calculate() << endl;


    system("pause");
    return 0;
}
#include <iostream>
#include "expression.h"


using namespace std;

int main() {
    char exprInit[] = " 6 +(5.45*3-2.45) *2- 3/(7.3 + 4.7-2)";

    expression expr(exprInit);

    cout << "Init expression" << endl;
    expr.show();
    cout << endl;
    expr.convertToRPN();

    cout << expr.calculate() << endl << endl;


    system("pause");
    return 0;
}
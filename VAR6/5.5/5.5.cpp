#include <cmath>
#include <iomanip>
#include <iostream>
#include "5.5.h"

using namespace std;

void printSolution(double (*funcPtr)(char, double), double xi, int iterations) {
    cout << setw(10) << xi << setw(20) << (*funcPtr)('F', xi) << setw(20) << iterations << endl;
}
void printSolution(double (*funcPtr)(char, double, double), double xi, double param, int iterations) {
    cout << setw(10) << param << setw(20) << xi << setw(20) << (*funcPtr)('F', xi, param) << setw(20) << iterations << endl;
}
void printTableHeader(int type) {
    if (type == 0) {
        cout << setw(10) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    }
    if (type == 1) {
        cout << setw(10) << "S" << setw(20) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    }
}

bool argsCorrect(double &leftBorder, double &rightBorder, double &x0) {
    return leftBorder <= rightBorder and leftBorder <= x0 and rightBorder >= x0;
}

double function(char type, double x) {
    switch (type) {
        case 'F': {
            return (x - 1) * (x - 1) * (x - 1) - 8;
        }
        case '1': {
            return 3 * x * x - 6 * x + 3;
        }
        default: {
            return 0;
        }
    }
}
double function(char type, double x, double param) {
    switch (type) {
        case 'F': {
            return param * cos(M_PI * x) * cos(M_PI * x) - sqrt(x);
        }
        case '1': {
            return -M_PI * param * sin(2 * M_PI * x) - 1 / (2 * sqrt(x));
        }
        default: {
            return 0;
        }
    }
}

void solveNewton(double (*funcPtr)(char, double), double leftBorder, double rightBorder, double x0, double epsilon) {
    if (!argsCorrect(leftBorder, rightBorder, x0)) {
        cout << "INCORRECT ARGUMENTS\n";
        return;
    }
    if ((*funcPtr)('1', x0) < epsilon) {
        cout << "INCORRECT X0\n";
        return;
    }
    double xi = x0;
    int iterations = 0;
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        xi = xi - (*funcPtr)('F', xi) / (*funcPtr)('1', xi);
        iterations++;
    }
    if (xi < leftBorder or xi > rightBorder) {
        cout << "NO ROOTS DETECTED IN THIS RANGE\n";
        return;
    }
    printSolution(funcPtr, xi, iterations);
}
void solveNewton(double (*funcPtr)(char, double, double), double leftBorder, double rightBorder, double x0, double epsilon, double paramMin, double paramMax, double deltaParam) {
    if (!argsCorrect(leftBorder, rightBorder, x0)) {
        cout << "INCORRECT ARGUMENTS\n";
        return;
    }
    int n = ceil((paramMax - paramMin) / deltaParam);
    double xi = x0;
    int iterations = 0;
    for (int i = 0; i <= n; ++i) {
        double param = paramMin + deltaParam * i;
        while (abs((*funcPtr)('F', xi, param)) > epsilon) {
            xi = xi - (*funcPtr)('F', xi, param) / (*funcPtr)('1', xi, param);
            iterations++;
        }
        if (xi < leftBorder or xi > rightBorder) {
            cout << "NO ROOTS DETECTED IN THIS RANGE\n";
            continue;
        }
        printSolution(funcPtr, xi, param, iterations);
        xi = x0;
    }
}
void solveHalfDivision(double (*funcPtr)(char, double), double leftBorder, double rightBorder, double epsilon) {
    if ((*funcPtr)('F', leftBorder) * (*funcPtr)('F', rightBorder) > 0) {
        cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
        return;
    }
    int iterations = 0;
    double xi = (leftBorder + rightBorder) / 2;
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        if ((*funcPtr)('F', leftBorder) * (*funcPtr)('F', xi) < 0) {
            xi = (leftBorder + xi) / 2;
        } else {
            xi = (rightBorder + xi) / 2;
        }
        iterations++;
    }
    printSolution(funcPtr, xi, iterations);
}
void solveHalfDivision(double (*funcPtr)(char, double, double), double leftBorder, double rightBorder, double epsilon, double paramMin, double paramMax, double deltaParam) {
    double sLB = leftBorder;
    double sRB = rightBorder;
    int iterations = 0;
    double xi = (leftBorder + rightBorder) / 2;
    int n = ceil((paramMax - paramMin) / deltaParam);
    for (int i = 0; i <= n; ++i) {
        double param = paramMin + deltaParam * i;
        if ((*funcPtr)('F', leftBorder, param) * (*funcPtr)('F', rightBorder, param) > 0) {
            cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
            break;
        }
        while ((abs((*funcPtr)('F', xi, param))) > epsilon) {
            if ((*funcPtr)('F', leftBorder, param) * (*funcPtr)('F', xi, param) > 0) {
                leftBorder = xi;
            } else {
                rightBorder = xi;
            }
            xi = (leftBorder + rightBorder) / 2;
            iterations++;
        }
        printSolution(funcPtr, xi, param, iterations);
        leftBorder = sLB;
        rightBorder = sRB;
        xi = (leftBorder + rightBorder) / 2;
        iterations = 0;
    }
}
void solveChords(double (*funcPtr)(char, double), double leftBorder, double rightBorder, double epsilon) {
    if ((*funcPtr)('F', leftBorder) * (*funcPtr)('F', rightBorder) > 0) {
        cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
        return;
    }
    int iterations = 0;
    double xi = leftBorder - ((*funcPtr)('F', leftBorder) * (leftBorder - rightBorder)) /
                             ((*funcPtr)('F', leftBorder) - (*funcPtr)('F', rightBorder));
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        if ((*funcPtr)('F', leftBorder) * (*funcPtr)('F', xi) < 0) {
            xi = leftBorder - ((*funcPtr)('F', leftBorder) * (leftBorder - xi)) /
                              ((*funcPtr)('F', leftBorder) - (*funcPtr)('F', xi));
        } else {
            xi = xi - ((*funcPtr)('F', xi) * (xi - rightBorder)) /
                      ((*funcPtr)('F', xi) - (*funcPtr)('F', rightBorder));
        }
        iterations++;
    }
    printSolution(funcPtr, xi, iterations);
}
void solveChords(double (*funcPtr)(char, double, double), double leftBorder, double rightBorder, double epsilon, double paramMin, double paramMax, double deltaParam) {
    int iterations = 0;
    double xi;
    int n = ceil((paramMax - paramMin) / deltaParam);
    for (int i = 0; i <= n; ++i) {
        double param = paramMin + deltaParam * i;
        if ((*funcPtr)('F', leftBorder, param) * (*funcPtr)('F', rightBorder, param) > 0) {
            cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
            return;
        }
        xi = leftBorder - ((*funcPtr)('F', leftBorder, param) * (leftBorder - rightBorder)) /
                          ((*funcPtr)('F', leftBorder, param) - (*funcPtr)('F', rightBorder, param));
        while (abs((*funcPtr)('F', xi, param)) > epsilon) {
            if ((*funcPtr)('F', leftBorder, param) * (*funcPtr)('F', xi, param) < 0) {
                xi = leftBorder - ((*funcPtr)('F', leftBorder, param) * (leftBorder - xi)) /
                                  ((*funcPtr)('F', leftBorder, param) - (*funcPtr)('F', xi, param));
            } else {
                xi = xi - ((*funcPtr)('F', xi, param) * (xi - rightBorder)) /
                          ((*funcPtr)('F', xi, param) - (*funcPtr)('F', rightBorder, param));
            }
            iterations++;
        }
        printSolution(funcPtr, xi, param, iterations);
        iterations = 0;
    }
}





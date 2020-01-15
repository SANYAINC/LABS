#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

void printSolution(double (*funcPtr)(char, double), double xi, int iterations) {
    cout << setw(10) << xi << setw(20) << (*funcPtr)('F', xi) << setw(20) << iterations;
    cout << "\n";
}

void printSolution(double (*funcPtr)(char, double, double), double xi, double param, int iterations) {
    cout << setw(10) << param << setw(20) << xi << setw(20) << (*funcPtr)('F', xi, param) << setw(20) << iterations
         << endl;
}

void printTableHeader(int type) {
    if (type == 0) {
        cout << setw(10) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    }
    if (type == 1) {
        cout << setw(10) << "S" << setw(20) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    }
}

bool argsCorrect(double &inf, double &sup, double &x0) {
    return inf <= sup and inf <= x0 and sup >= x0;
}

double function(char type, double x) {
    switch (type) {
        case 'F': {
            return (x - 1) * (x - 1) * (x - 1) - 8;
        }
        case '1': {
            return 3 * x * x - 6 * x + 3;
        }
        case '2': {
            return 6 * x - 6;
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
        case '2': {
            return -2 * M_PI * M_PI * param * cos(2 * M_PI * x) + 1 / (4 * x * sqrt(x));
        }
        default: {
            return 0;
        }
    }
}

void solveNewton(double (*funcPtr)(char, double), double inf, double sup, double x0, double epsilon) {
    if (!argsCorrect(inf, sup, x0)) {
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
    if (xi < inf or xi > sup) {
        cout << "NO ROOTS DETECTED\n";
        return;
    }
    printSolution(funcPtr, xi, iterations);
}

void solveNewton(double (*funcPtr)(char, double, double), double inf, double sup, double x0,
                 double epsilon, double paramInf, double paramSup, double deltaParam) {
    if (!argsCorrect(inf, sup, x0)) {
        cout << "INCORRECT ARGUMENTS\n";
        return;
    }
    int n = ceil((paramSup - paramInf) / deltaParam);
    double xi = x0;
    int iterations = 0;
    for (int i = 0; i <= n; ++i) {
        double param = paramInf + deltaParam * i;
        while (abs((*funcPtr)('F', xi, param)) > epsilon) {
            xi = xi - (*funcPtr)('F', xi, param) / (*funcPtr)('1', xi, param);
            iterations++;
        }
        if (xi < inf or xi > sup) {
            cout << "NO ROOTS DETECTED IN THIS RANGE\n";
            break;
        }
        printSolution(funcPtr, xi, param, iterations);
        xi = x0;
    }
}

void solveHalfDivision(double (*funcPtr)(char, double), double inf, double sup, double epsilon) {
    if ((*funcPtr)('F', inf) * (*funcPtr)('F', sup) > 0) {
        cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
        return;
    }
    int iterations = 0;
    double xi = (inf + sup) / 2;
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        if ((*funcPtr)('F', inf) * (*funcPtr)('F', xi) < 0) {
            xi = (inf + xi) / 2;
        } else {
            xi = (sup + xi) / 2;
        }
        iterations++;
    }
    printSolution(funcPtr, xi, iterations);
}

void solveHalfDivision(double (*funcPtr)(char, double, double), double inf, double sup, double epsilon,
                       double paramInf, double paramSup, double deltaParam) {
    double sInf = inf;
    double sSup = sup;
    int iterations = 0;
    double newPoint = (inf + sup) / 2;
    int n = ceil((paramSup - paramInf) / deltaParam);
    for (int i = 0; i <= n; ++i) {
        double param = paramInf + deltaParam * i;
        if ((*funcPtr)('F', inf, param) * (*funcPtr)('F', sup, param) > 0) {
            cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
            break;
        }
        while ((abs((*funcPtr)('F', newPoint, param))) > epsilon) {
            if ((*funcPtr)('F', inf, param) * (*funcPtr)('F', newPoint, param) > 0) {
                inf = newPoint;
            } else {
                sup = newPoint;
            }
            newPoint = (inf + sup) / 2;
            iterations++;
        }
        printSolution(funcPtr, newPoint, param, iterations);
        inf = sInf;
        sup = sSup;
        newPoint = (inf + sup) / 2;
        iterations = 0;
    }
}

void solveChords(double (*funcPtr)(char, double), double inf, double sup, double epsilon) {
    if ((*funcPtr)('F', inf) * (*funcPtr)('F', sup) > 0) {
        cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
        return;
    }
    int iterations = 0;
    double xi = inf - ((*funcPtr)('F', inf) * (inf - sup)) / ((*funcPtr)('F', inf) - (*funcPtr)('F', sup));
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        if ((*funcPtr)('F', inf) * (*funcPtr)('F', xi) < 0) {
            xi = inf - ((*funcPtr)('F', inf) * (inf - xi)) / ((*funcPtr)('F', inf) - (*funcPtr)('F', xi));
        } else {
            xi = xi - ((*funcPtr)('F', xi) * (xi - sup)) / ((*funcPtr)('F', xi) - (*funcPtr)('F', sup));
        }
        iterations++;
    }
    printSolution(funcPtr, xi, iterations);
}

void solveChords(double (*funcPtr)(char, double, double), double inf, double sup, double epsilon,
                 double paramInf, double paramSup, double deltaParam) {
    int iterations = 0;
    double xi;
    int n = ceil((paramSup - paramInf) / deltaParam);
    for (int i = 0; i <= n; ++i) {
        double param = paramInf + deltaParam * i;
        if ((*funcPtr)('F', inf, param) * (*funcPtr)('F', sup, param) > 0) {
            cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
            return;
        }
        xi = inf -
             ((*funcPtr)('F', inf, param) * (inf - sup)) / ((*funcPtr)('F', inf, param) - (*funcPtr)('F', sup, param));
        while (abs((*funcPtr)('F', xi, param)) > epsilon) {
            if ((*funcPtr)('F', inf, param) * (*funcPtr)('F', xi, param) < 0) {
                xi = inf - ((*funcPtr)('F', inf, param) * (inf - xi)) /
                           ((*funcPtr)('F', inf, param) - (*funcPtr)('F', xi, param));
            } else {
                xi = xi - ((*funcPtr)('F', xi, param) * (xi - sup)) /
                          ((*funcPtr)('F', xi, param) - (*funcPtr)('F', sup, param));
            }
            iterations++;
        }
        printSolution(funcPtr, xi, param, iterations);
        iterations = 0;
    }
}





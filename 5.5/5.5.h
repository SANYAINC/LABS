#include <cmath>
#include <iomanip>
using namespace std;

double function(char type, double x);
double function(char type, double x, double param);
void solveNewton(double (*funcPtr)(char, double), double epsilon = 1E-6, double inf = 1, double sup = 4);
void solveNewton(double (*funcPtr)(char, double, double), double epsilon = 1E-6, double inf = 0, double sup = 1.5, double paramInf = 0.95, double paramSup = 1.2, double deltaParam = 0.05);
void printSolution(double (*funcPtr)(char, double), double xi, int iterations);
void printSolution(double (*funcPtr)(char, double, double), double xi, double paramInf, double deltaParam, int i, int iterations);
void printTableHeader();






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
            return  -2 * M_PI * M_PI * param * cos(2 * M_PI * x) + 1 / (4 * x * sqrt(x));
        }
        default: {
            return 0;
        }
    }
}

void solveNewton(double (*funcPtr)(char, double), double epsilon, double inf, double sup) {
    double xi = (inf + sup)/2;
    int iterations = 0;
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        xi = xi - (*funcPtr)('F', xi)/(*funcPtr)('1', xi);
        iterations++;
        if (xi < inf or xi > sup) {
            cout << "NO ROOTS DETECTED";
            return;
        }
    }
    printSolution(funcPtr, xi, iterations);
}

void solveNewton(double (*funcPtr)(char, double, double), double epsilon, double inf, double sup, double paramInf, double paramSup, double deltaParam) {
    //TODO ВЫделить память для параметра, поменять место epsilon
    printTableHeader();
    int n = ceil((paramSup - paramInf) / deltaParam);
    double xi = 0.1;
    double xPrev;
    double xCur;
    bool isTrapped = false;
    bool outOfRange = false;
    int iterations = 0;
    for (int i = 0; i <= n; ++i) {
        while (abs((*funcPtr)('F', xi, paramInf + deltaParam * i)) > epsilon) {
            xPrev = xi;
            xi = xi - (*funcPtr)('F', xi, paramInf + deltaParam * i) / (*funcPtr)('1', xi, paramInf + deltaParam * i);
            iterations++;
            xCur = xi;
            if (xi < inf or xi > sup) {
                cout << "NO ROOTS DETECTED IN THIS RANGE\n";
                outOfRange = true;
                break;
            }
            if (abs((*funcPtr)('F', xCur, paramInf + deltaParam * i)) > abs((*funcPtr)('F', xPrev, paramInf + deltaParam * i))) {
                cout << "EXTREMUM TRAP\n";
                isTrapped = true;
                break;
            }
        }
        if (!isTrapped and !outOfRange) {
            printSolution(funcPtr, xi, paramInf, deltaParam, i, iterations);
        }
        xi = 0.1;
        isTrapped = false;
        outOfRange = false;
    }
}


void printSolution(double (*funcPtr)(char, double), double xi, int iterations) {
    cout << "\n";
    cout << setw(10) << "X" << setw(20) <<       "F(x)"          << setw(20) << "Iterations\n\n";
    cout << setw(10) <<  xi << setw(20) << (*funcPtr)('F', xi)   << setw(20) <<    iterations;
    cout << "\n";
}
void printSolution(double (*funcPtr)(char, double, double), double xi, double paramInf, double deltaParam, int i, int iterations) {
    cout << setw(10) << paramInf + deltaParam * i << setw(20) << xi << setw(20) << (*funcPtr)('F', xi, paramInf + deltaParam * i) << setw(20) << iterations << endl;
}
void printTableHeader() {
    cout << '\n';
    cout << setw(10) << "S" << setw(20) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    cout << '\n';
}


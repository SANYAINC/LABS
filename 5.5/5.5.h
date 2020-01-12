#include <cmath>
#include <iomanip>
using namespace std;

double function1(char type, double x);
void solveNewton(double (*funcPtr)(char, double), double epsilon = 1E-6, double inf = 1, double sup = 4);
void printSolution(double (*funcPtr)(char, double), double xi, int iterations);






double function1(char type, double x) {
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

void solveNewton(double (*funcPtr)(char, double), double epsilon, double inf, double sup) {
    double xi;
    if ((*funcPtr)('F', inf) * (*funcPtr)('2', inf) > 0) {
        xi = inf;
    } else {
        xi = sup;
    }
    int iterations = 0;
    while (abs((*funcPtr)('F', xi)) > epsilon) {
        xi = xi - (*funcPtr)('F', xi)/(*funcPtr)('1', xi);
        iterations++;
    }
    printSolution(funcPtr, xi, iterations);
}

void printSolution(double (*funcPtr)(char, double), double xi, int iterations) {
    cout << "\n";
    cout << setw(10) << "X" << setw(20) <<       "F(x)"          << setw(20) << "Iterations\n\n";
    cout << setw(10) <<  xi << setw(20) << (*funcPtr)('F', xi)   << setw(20) <<    iterations;
    cout << "\n";
}


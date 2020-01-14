#include <cmath>
#include <iomanip>
using namespace std;


//Вывод найденных решений
void printSolution(double (*funcPtr)(char, double), double xi, int iterations) {
    cout << "\n";
    cout << setw(10) << "X" << setw(20) <<       "F(x)"          << setw(20) << "Iterations\n\n";
    cout << setw(10) <<  xi << setw(20) << (*funcPtr)('F', xi)   << setw(20) <<    iterations;
    cout << "\n";
}
void printSolution(double (*funcPtr)(char, double, double), double xi, double param, int iterations) {
    cout << setw(10) << param << setw(20) << xi << setw(20) << (*funcPtr)('F', xi, param) << setw(20) << iterations << endl;
}
void printTableHeader() {
    cout << '\n';
    cout << setw(10) << "S" << setw(20) << "X" << setw(20) << "F(x)" << setw(20) << "Iterations\n\n";
    cout << '\n';
}

//Проверка правильности позиции аргументов
bool argsCorrect(double &inf, double &sup, double &x0) {
    return inf <= sup and inf <= x0 and sup >= x0;
}
//Функции
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

//Решение методом Ньютона
//Можно использовать вдали от критических точек
void solveNewton(double (*funcPtr)(char, double), double inf = 1, double sup = 4, double x0 = 2, double epsilon = 1E-6) {
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
        xi = xi - (*funcPtr)('F', xi)/(*funcPtr)('1', xi);
        iterations++;
    }
    if (xi < inf or xi > sup) {
        cout << "NO ROOTS DETECTED\n";
        return;
    }
    printSolution(funcPtr, xi, iterations);
}
void solveNewton(double (*funcPtr)(char, double, double), double inf = 0, double sup = 1.5, double x0 = 0.2, double epsilon = 1E-6, double paramInf = 0.95, double paramSup = 1.2, double deltaParam = 0.05) {
    if (!argsCorrect(inf, sup, x0)) {
        cout << "INCORRECT ARGUMENTS\n";
        return;
    }
    printTableHeader();
    int n = ceil((paramSup - paramInf) / deltaParam);
    double xi = x0;
    bool outOfRange = false;
    int iterations = 0;
    for (int i = 0; i <= n; ++i) {
        double param = paramInf + deltaParam * i;
        while (abs((*funcPtr)('F', xi, param)) > epsilon) {
            xi = xi - (*funcPtr)('F', xi, param) / (*funcPtr)('1', xi, param);
            iterations++;
        }
        if (xi < inf or xi > sup) {
            cout << "NO ROOTS DETECTED IN THIS RANGE\n";
            outOfRange = true;
            break;
        }
        if (!outOfRange) {
            printSolution(funcPtr, xi, param, iterations);
        }
        xi = x0;
        outOfRange = false;
    }
}
//Решение методом половинного деления
//Можно использовать когда точно известно что на промежутке есть единственный корень
void solveHalfDividing(double (*funcPtr)(char, double), double inf = 1, double sup = 4, double epsilon = 1E-6) {
    if ((*funcPtr)('F', inf) * (*funcPtr)('F', sup) > 0) {
        cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
        return;
    }
    int iterations = 0;
    double newPoint = (inf + sup)/2;
    while (abs((*funcPtr)('F', newPoint)) > epsilon) {
        if ((*funcPtr)('F', inf) * (*funcPtr)('F', newPoint) < 0){
            newPoint = (inf + newPoint)/2;
        } else {
            newPoint = (sup + newPoint)/2;
        }
        iterations++;
    }
    printSolution(funcPtr, newPoint, iterations);
}
void solveHalfDividing(double (*funcPtr)(char, double, double), double inf = 0, double sup = 1.5 ,double epsilon = 1E-6, double paramInf = 0.95, double paramSup = 1.2, double deltaParam = 0.05) {
    printTableHeader();
    double sInf = inf;
    double sSup = sup;
    int iterations = 0;
    double newPoint = (inf + sup)/2;
    int n = ceil((paramSup - paramInf) / deltaParam);
    for (int i = 0; i <= n; ++i) {
        double param = paramInf + deltaParam * i;
        if ((*funcPtr)('F', inf, param) * (*funcPtr)('F', sup, param) > 0) {
            cout << "PARAMS DO NOT MATCH REQUIREMENTS ( F(a)*F(b)>0 )";
            break;
        }
        while ((abs((*funcPtr)('F', newPoint, param))) > epsilon) {
            if ((*funcPtr)('F', inf, param) * (*funcPtr)('F', newPoint, param) > 0){
                inf = newPoint;
            } else {
                sup = newPoint;
            }
            newPoint = (inf+sup)/2;
            iterations++;
        }
        printSolution(funcPtr, newPoint, param, iterations);
        inf = sInf;
        sup = sSup;
        newPoint = (inf + sup)/2;
    }
}



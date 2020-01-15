#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double function(double x, double paramS, double paramT) {
    return ((1 + pow(x, paramT) + x * x) / (sqrt(x * x * x + 1))) * (1 - sin(paramS * x));
}

double calcIntegral(double (*func)(double, double, double), double inf, double sup, double s, double t, int N) {
    double xi = inf;
    double dx = (sup - inf) / N;
    double integral = 0;
    for (int k = 0; k < N; k++) {
        integral += (*func)(xi + dx / 2, s, t);
        xi += dx;
    }
    return integral * dx;
}

void solveIntegral(double (*function)(double, double, double), double inf, double sup, double epsilon,
                   double parSInf, double parSSup, double parSDelta,
                   double parTInf, double patTSup, double parTDelta, int N0) {
    int parSIter = ceil((parSSup - parSInf) / parSDelta);
    int parTIter = ceil((patTSup - parTInf) / parTDelta);

    double curParS;
    double curParT;

    double integralN = 0;
    double integral2N = 0;

    int N = N0;
    double dx;
    double xi;
    int iterations = 0;

    cout << "\n\n";
    cout << setw(15) << "S PARAM" << setw(15) << "T PARAM" << setw(15) << "INTEGRAL" << setw(15) << "ITERATIONS"
         << "\n\n";

    for (int i = 0; i <= parSIter; ++i) {
        curParS = parSInf + parSDelta * i;
        for (int j = 0; j <= parTIter; ++j) {
            curParT = parTInf + parTDelta * j;
            do {
                if (integral2N != 0) {
                    integralN = integral2N;
                    integral2N = calcIntegral(function, inf, sup, curParS, curParT, 2 * N);
                    iterations++;
                } else {
                    integralN = calcIntegral(function, inf, sup, curParS, curParT, N);
                    iterations++;

                    integral2N = calcIntegral(function, inf, sup, curParS, curParT, 2 * N);
                    iterations++;
                }

                N *= 2;

            } while (abs(integralN - integral2N) > epsilon);

            cout << setw(15) << curParS << setw(15) << curParT << setw(15) << integralN << setw(15) << iterations << "\n";
            N = N0;
            iterations = 0;
        }
    }
}
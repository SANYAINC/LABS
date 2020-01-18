#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double function(double x, double paramS, double paramT) {
    return ((1 + pow(x, paramT) + x * x) / (sqrt(x * x * x + 1))) * (1 - sin(paramS * x));
}

double calcIntegral(double (*func)(double, double, double), double leftBorder, double rightBorder, double paramS, double paramT, int N) {
    double xi = leftBorder;
    double dx = (rightBorder - leftBorder) / N;
    double integral = 0;
    for (int k = 0; k < N; k++) {
        integral += (*func)(xi + dx / 2, paramS, paramT);
        xi += dx;
    }
    return integral * dx;
}

void solveIntegralMidRectangles(double (*func)(double, double, double), double leftBorder, double rightBorder, double epsilon,
                                double parSMin, double parSMax, double parSDelta,
                                double parTMin, double patTSup, double parTDelta) {

    int parSIter = ceil((parSMax - parSMin) / parSDelta);
    int parTIter = ceil((patTSup - parTMin) / parTDelta);

    double curParS;
    double curParT;

    double integralN = 0;
    double integral2N = 0;

    int N = 1;
    int iterations = 0;

    cout << "\n\n";
    cout << setw(15) << "S PARAM" << setw(15) << "T PARAM" << setw(15) << "INTEGRAL" << setw(15) << "ITERATIONS";
    cout << "\n\n";

    for (int i = 0; i <= parSIter; ++i) {
        curParS = parSMin + parSDelta * i;
        for (int j = 0; j <= parTIter; ++j) {
            curParT = parTMin + parTDelta * j;
            do {
                //Если интеграл считается не в первый раз, ложим в N предыдущее значение из 2N, а новое 2N пересчитываем с новым параметром
                if (integral2N != 0) {
                    integralN = integral2N;
                    integral2N = calcIntegral(func, leftBorder, rightBorder, curParS, curParT, 2 * N);
                    iterations++;
                //Если интеграл считается в первый раз, считаем для N и для 2N
                } else {
                    integralN = calcIntegral(func, leftBorder, rightBorder, curParS, curParT, N);
                    integral2N = calcIntegral(func, leftBorder, rightBorder, curParS, curParT, 2 * N);
                    iterations+=2;
                }

                N *= 2;

            } while (abs(integralN - integral2N) > epsilon);

            cout << setw(15) << curParS << setw(15) << curParT << setw(15) << integralN << setw(15) << iterations << "\n";
            N = 1;
            iterations = 0;
        }
    }
}
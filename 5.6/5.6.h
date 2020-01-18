#pragma once

//Функция
double function(double x, double paramS, double paramT);

//Решить интеграл методом средних прямоугольников
void solveIntegralMR(double (*func)(double, double, double), double min = 1, double max = 2,
                     double epsilon = 1E-6,
                     double parSMin = 0, double parSMax = 0.5, double parSDelta = 0.1,
                     double parTMin = 0.5, double patTMax = 2.5, double parTDelta = 0.5);
//Решить интеграл методом трапеций
void solveIntegralT(double (*func)(double, double, double), double min = 1, double max = 2, double epsilon = 1E-6,
                    double parSMin = 0, double parSMax = 0.5, double parSDelta = 0.1,
                    double parTMin = 0.5, double patTMax = 2.5, double parTDelta = 0.5);
//Решить интеграл методом Симпсона
void solveIntegralS(double (*func)(double, double, double), double leftBorder = 1, double rightBorder = 2, double epsilon = 1E-6,
                    double parSMin = 0, double parSMax = 0.5, double parSDelta = 0.1,
                    double parTMin = 0.5, double patTMax = 2.5, double parTDelta = 0.5);



//Посчитать интеграл с текущим количествои разбиений соответствующим методом
double calcIntegralMR(double (*func)(double, double, double), double leftBorder, double rightBorder, double paramS,
                      double paramT, int N);
double calcIntegralT(double (*func)(double, double, double), double leftBorder, double rightBorder, double paramS,
                     double paramT, int N);
double calcIntegralS(double (*func)(double, double, double), double leftBorder, double rightBorder, double paramS,
                    double paramT, int N);

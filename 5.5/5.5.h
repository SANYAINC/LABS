#include <cmath>
#include <iomanip>
using namespace std;


//Вывод найденных решений
void printSolution(double (*funcPtr)(char, double), double xi, int iterations);
void printSolution(double (*funcPtr)(char, double, double), double xi, double param, int iterations);
void printTableHeader();

//Проверка правильности позиции аргументов
bool argsCorrect(double &inf, double &sup, double &x0);
//Функции
double function(char type, double x);
double function(char type, double x, double param);

//Решение методом Ньютона
//Можно использовать вдали от критических точек
void solveNewton(double (*funcPtr)(char, double), double inf = 1, double sup = 4, double x0 = 2, double epsilon = 1E-6);
void solveNewton(double (*funcPtr)(char, double, double), double inf = 0, double sup = 1.5, double x0 = 0.2, double epsilon = 1E-6, double paramInf = 0.95, double paramSup = 1.2, double deltaParam = 0.05);
//Решение методом половинного деления
//Можно использовать когда точно известно что на промежутке есть единственный корень
void solveHalfDividing(double (*funcPtr)(char, double), double inf = 1, double sup = 4, double epsilon = 1E-6);
void solveHalfDividing(double (*funcPtr)(char, double, double), double inf = 0, double sup = 1.5 ,double epsilon = 1E-6, double paramInf = 0.95, double paramSup = 1.2, double deltaParam = 0.05);



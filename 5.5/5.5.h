
//Вывод найденных решений
void printSolution(double (*funcPtr)(char, double), double xi, int iterations);
void printSolution(double (*funcPtr)(char, double, double), double xi, double param, int iterations);

//Вывод шапки таблицы.
// 0 - без параметра; 1 - с параметром
void printTableHeader(int type);

//Проверка правильности позиции аргументов
bool argsCorrect(double &leftBorder, double &rightBorder, double &x0);
//Функции
double function(char type, double x);
double function(char type, double x, double param);

//Решение методом Ньютона
//Можно использовать вдали от критических точек
void solveNewton(double (*funcPtr)(char, double), double leftBorder = 1, double rightBorder = 4, double x0 = 2, double epsilon = 1E-6);
void solveNewton(double (*funcPtr)(char, double, double), double leftBorder = 0, double rightBorder = 1.5, double x0 = 0.01, double epsilon = 1E-6, double paramMin = 0.95, double paramMax = 1.2, double deltaParam = 0.05);
//Решение методом половинного деления
//Можно использовать когда точно известно что на промежутке есть единственный корень
void solveHalfDivision(double (*funcPtr)(char, double), double leftBorder = 1, double rightBorder = 4, double epsilon = 1E-6);
void solveHalfDivision(double (*funcPtr)(char, double, double), double leftBorder = 0, double rightBorder = 1.5 , double epsilon = 1E-6, double paramMin = 0.95, double paramMax = 1.2, double deltaParam = 0.05);
//Решение методом хорд
//Можно использовать когда точно известно что на промежутке есть единственный корень
void solveChords(double (*funcPtr)(char, double), double leftBorder = 1, double rightBorder = 4, double epsilon = 1E-6);
void solveChords(double (*funcPtr)(char, double, double), double leftBorder = 0, double rightBorder = 1.5, double epsilon = 1E-6, double paramMin = 0.95, double paramMax = 1.2, double deltaParam = 0.05);



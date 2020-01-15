double function(double x, double paramS, double paramT);

void solveIntegral(double (*func)(double, double, double), double inf = 1, double sup = 2, double epsilon = 1E-6,
                   double parSInf = 0, double parSSup = 0.5, double parSDelta = 0.1,
                   double parTInf = 0.5, double patTSup = 2.5, double parTDelta = 0.5, int N0 = 1);

double calcIntegral(double (*func)(double, double, double), double inf, double sup, double s, double t, int N);
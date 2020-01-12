double function1(char type, double x) {
    switch (type) {
        case 'F': {
            return (x - 1)*(x-1)*(x-1)-8;
        }
        case 'D': {
            return 3*x*x-6*x+3;
        }
        default: {
            return 0;
        }
    }
}
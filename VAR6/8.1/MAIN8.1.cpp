#include <iostream>
#include "class.h"
#include "8.1.h"

using namespace std;

int main() {
    char fileName[] = "../VAR6/8.1/f.txt";

    vector result = getRepeats(fileName);

    cout << result;
    return 0;
}
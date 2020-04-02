#include <iostream>
#include "9.1.h"

using namespace std;

int main() {

    char fileName[] = "f.txt";

    fileInit(fileName);

    vector<int> result = getRepeats(fileName);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }


    return 0;
}

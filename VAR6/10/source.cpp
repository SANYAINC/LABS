#include <iostream>
#include <ctime>
#include "sEye_Entity/Entities.h"
#include "sEye_Entity/Containers.h"
#include "sEye_Entity/ContainersFactory.h"
#include "sEye_Scanner/Scanner.h"

using namespace std;


int main() {
    srand(time(nullptr));

    vectorFactory factoryV;
    listFactory factoryL;

    vector& vector1 = factoryV.create();
    list& list1 = factoryL.create();

    cout << "TESTING NON-EMPTY VECTOR " << endl;

    scanFrame(vector1);
    testContainer(vector1);

    cout << "====================================================" << endl;
    cout << "TESTING NON-EMPTY LIST " << endl;

    scanFrame(list1);
    testContainer(list1);

    cout << "====================================================" << endl;
    cout << "====================================================" << endl;

    for (int i = 0; i < vector1.getSize(); ++i) {
        vector1[i]->print();
    }

    cout << "====================================================";
    cout << "====================================================";

    for (int j = 0; j < list1.getSize(); ++j) {
        list1[j]->print();
    }

    factoryV.destroy(vector1);
    factoryL.destroy(list1);

    return 0;
}
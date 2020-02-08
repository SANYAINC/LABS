#include <iostream>
#include "6.2.h"

using namespace std;

int main() {
    string fileName1 = "f.txt"; //Имя с целыми числами
    string fileName2 = "g.txt"; //Имя файла с отсортированными 2 по 2
    createFileWithIntegers(fileName1, 100000); //Сгенерировать файл с целыми числами
    rewriteTwoByTwo(fileName1, fileName2); //Получить отсортированный файл


    return 0;
}
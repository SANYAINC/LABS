#include <iostream>
#include "6.2.h"

using namespace std;

//Сдано
int main() {
    string fileName1 = "f.txt"; //Имя с целыми числами
    string fileName2 = "g.txt"; //Имя файла с отсортированными 2 по 2
    string fileNameBin1 = "binaryF.bin"; //Имя двоичного файла с числами
    string fileNameBin2 = "binaryG.bin"; //Имя двоичного файла с отсортированными 2 по 2

    //createFileWithIntegers(fileName1, 100000); //Сгенерировать файл с целыми числами
    rewriteTwoByTwo(fileName1, fileName2); //Получить отсортированный файл
    createBinFileWithIntegers(fileNameBin1, 100000); //Сгенерировать двоичный файл с целыми числами
    rewriteTwoByTwoBin(fileNameBin1, fileNameBin2); //Получить отсортированный двоичных файл

    return 0;
}
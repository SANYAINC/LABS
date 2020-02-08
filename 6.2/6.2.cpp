#include "6.2.h"

bool createFileWithIntegers(string &name, int amount) {
    ofstream f;
    srand(time(nullptr));
    f.open("../6.2/" + name);
    if (!f.is_open()) {
        return false;
    }
    for (int i = 1; i <= amount; ++i) {
        f << (i%2 == 0 ? rand()%100 : rand()%100 - 100) << endl;
    }
    f.close();
    return true;
}
void rewriteTwoByTwo(string &rd, string &wt) {
    ifstream fPst("../6.2/" + rd); //Чтение положительных чисел
    ifstream fNgt("../6.2/" + rd); //Чтение отрицательных чисел
    ofstream g("../6.2/" + wt); //Запись в новый файл
    if (!fPst.is_open() or !g.is_open()) {
        return;
    }
    string bufPst;  //Буфер для Положительных чисел
    string bufNgt;  //Буфер для отрицательных чисел
    int pstCou = 0; //счетчик положительных
    int ngtCou = 0; //счетчик отрицательных
    //Пока не дошли до конца обоих файлов
    while (!(fPst.eof() and fNgt.eof())) {
        //Потск положительных чисел
        while (getline(fPst, bufPst)) {
            if (bufPst[0] == '-') {
                continue;
            } else {
                if (pstCou < 2) {
                    g << bufPst << endl;
                    pstCou++;
                }
                if (pstCou == 2) {
                    pstCou = 0;
                    break;
                }
            }
        }
        //Поиск отрицательных чисел
        while (getline(fNgt, bufNgt)) {
            if (bufNgt[0] != '-') {
                continue;
            } else {
                if (ngtCou < 2) {
                    g << bufNgt << endl;
                    ngtCou++;
                }
                if (ngtCou == 2) {
                    ngtCou = 0;
                    break;
                }
            }
        }
    }
}

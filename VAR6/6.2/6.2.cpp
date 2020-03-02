#include "6.2.h"

bool createFileWithIntegers(string &name, int amount) {
    if (amount%4 != 0) {
        return false;
    }
    ofstream f;
    srand(time(nullptr));
    f.open("../VAR6/6.2/" + name);
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
    ifstream fPst("../VAR6/6.2/" + rd); //Чтение положительных чисел
    ifstream fNgt("../VAR6/6.2/" + rd); //Чтение отрицательных чисел
    ofstream g("../VAR6/6.2/" + wt); //Запись в новый файл
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

bool createBinFileWithIntegers(string &name, int amount) {
    if (amount%4 != 0) {
        return false;
    }
    ofstream f;
    srand(time(nullptr));
    f.open("../VAR6/6.2/" + name, ios::binary);
    int a;
    for (int i = 0; i < amount; ++i) {
        a = (i%2 == 0 ? rand()%100 : rand()%100 - 100);
        f.write(reinterpret_cast<char*>(&a), sizeof(int));
    }
    f.close();
    return true;
}
void rewriteTwoByTwoBin(string &rd, string &wt) {
    ifstream fPos("../VAR6/6.2/" + rd, ios::binary);
    ifstream fNgt("../VAR6/6.2/" + rd, ios::binary);
    ofstream g("../VAR6/6.2/" + wt, ios::binary);
    int buffer;
    int pstCou = 0;
    int ngtCou = 0;
    while (!(fPos.eof() and fNgt.eof())) {
        //Потск положительных чисел
        while (fPos.read(reinterpret_cast<char*>(&buffer), sizeof(int))) {
            if (buffer < 0) {
                continue;
            } else {
                if (pstCou < 2) {
                    g.write(reinterpret_cast<char*>(&buffer), sizeof(int));
                    pstCou++;
                }
                if (pstCou == 2) {
                    pstCou = 0;
                    break;
                }
            }
        }
        //Поиск отрицательных чисел
        while (fNgt.read(reinterpret_cast<char*>(&buffer), sizeof(int))) {
            if (buffer >= 0) {
                continue;
            } else {
                if (ngtCou < 2) {
                    g.write(reinterpret_cast<char*>(&buffer), sizeof(int));
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
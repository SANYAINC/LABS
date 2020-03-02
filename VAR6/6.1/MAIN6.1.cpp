#include "6.1.h"

int main() {
    cout << endl << endl;

    //Удаление символов, встречающихся более 2х раз
    string str1 = "l,lblvccffbfjjjjcfdfddfdgfgtttttt3ervfdg55";
    cout << str1 << "\tTO\t";
    deleteRepeats(str1);
    cout << str1 << endl;

    //Перевод строки из десятичной в шестнадцатиричную систему
    string str2 = "134523534.234234";
    cout << str2 << "\tTO\t";
    decToHex(str2);
    cout << str2 << endl;

    //Выделение слов с максимальным количеством согласных
    string str3 = "... We continue expanding our operations, increasing our team size, and improving JetBrains facilities. bbbbbbb .";
    cout << maxConsonantsWord(str3) << endl << str3;

    return 0;
}

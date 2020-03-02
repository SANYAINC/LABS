#include <iostream>
#include "7.3.h"

using namespace std;

int main() {

    //Инциализация данных
    date b1(14, 9, 2001);
    date b2(13, 11, 2001);
    date b3(19, 5, 2002);

    student sanya("Alexander", "BBBBBBBBBBBBBB", "Vyacheslavovich", b1, 1, 10);
    student vanya("Ivan", "CCCCCCCCCCCCCCC", "Vladimirovich", b2, 1, 8.2);
    student denis("Denis", "AAAAAAAAAAAAAAAAAA", "Alexandrovich", b3, 1, 9);
    student u;
    student u1("U", "Z", "U", b1, 1, 0);

    list students;
    students.pushAlphabetically(u);
    students.pushAlphabetically(u);
    students.pushAlphabetically(u1);        //Добавление элементов в список
    students.pushAlphabetically(sanya);
    students.pushAlphabetically(vanya);
    students.pushAlphabetically(denis);

    for (int i = 0; i < students.getSize(); ++i) {
        students[i].print();
    }

    cout << "------------------------------------\n";

    list goodStudents;
    students.selectGoodFromAll(goodStudents);

    for (int i = 0; i < goodStudents.getSize(); ++i) {
        goodStudents[i].print();
    }
    cout << "------------------------------------\n";

    for (int i = 0; i < students.getSize(); ++i) {
        students[i].print();
    }


    return 0;
}


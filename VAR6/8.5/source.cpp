#include <iostream>
#include <ctime>
#include "class.h"

using namespace std;


int main() {
    srand(time(nullptr));

    int n;
    cout << "Please, enter number of elements: ";
    cin >> n;

    //Создание первого списка
    cout << "Please, enter " << n << " numbers: ";
    list <int> list1(n);
    for (int i = 0; i < n; ++i) {
        cin >> list1[i];
    }
    cout << endl;
    cout << "List1 (init): ";
    list1.print();
    cout << endl;

    //Создание второго списка
    list <int> list2;
    cout << "List2 (empty): ";
    list2.print();
    cout << endl;

    //СОздание третьего списка
    list <int> list3(list1);
    cout << "List3 (copy of List1): ";
    list3.print();
    cout << endl << endl;

    //Добавление случайных чисел в конец каждого списка
    cout << "Pushing random number to List1, List2, List3:" << endl;
    list1.pushBack(rand()%100+1000);
    list2.pushBack(rand()%100+1000);
    list3.pushBack(rand()%100+1000);
    cout << endl;

    cout << "List1 (init): ";
    list1.print();
    cout << endl;
    cout << "List2 (empty): ";
    list2.print();
    cout << endl;
    cout << "List3 (copy of List1): ";
    list3.print();
    cout << endl << endl;

    //Добавление случайных чисел в произвольную позицию
    int ins1, ins2, ins3;
    cout << "Please, enter insert position (0 - " << list1.getSize() <<"): ";
    cin >> ins1;
    cout << "Please, enter insert position (0 - " << list2.getSize() <<"): ";
    cin >> ins2;
    cout << "Please, enter insert position (0 - " << list3.getSize() <<"): ";
    cin >> ins3;
    cout << endl;

    cout << "Pushing random numbers to List1, List2, List3 at " << ins1 << ", " << ins2 << ", " << ins3 << ":"<< endl;
    cout << endl;
    list1.pushAt(ins1, rand()%100+1000);
    list2.pushAt(ins2, rand()%100+1000);
    list3.pushAt(ins3, rand()%100+1000);
    cout << "List1 (init): ";
    list1.print();
    cout << endl;
    cout << "List2 (empty): ";
    list2.print();
    cout << endl;
    cout << "List3 (copy of List1): ";
    list3.print();
    cout << endl << endl;

    //Удаление элементов с заданных позиций
    int del1, del2, del3;
    cout << "Please, enter delete position (0 - " << list1.getSize()-1 <<"): ";
    cin >> del1;
    cout << "Please, enter delete position (0 - " << list2.getSize()-1 <<"): ";
    cin >> del2;
    cout << "Please, enter delete position (0 - " << list3.getSize()-1 <<"): ";
    cin >> del3;
    cout << endl;
    list1.deleteAt(del1);
    list2.deleteAt(del2);
    list3.deleteAt(del3);
    cout << "List1 (init): ";
    list1.print();
    cout << endl;
    cout << "List2 (empty): ";
    list2.print();
    cout << endl;
    cout << "List3 (copy of List1): ";
    list3.print();
    cout << endl << endl;

    //Поиск элемента в списке List1 (Возвращает его индекс или -1)
    int srch;
    cout << "Please, enter a number to find in List1: ";
    cin >> srch;
    cout << list1.find(srch) << endl << endl;

    //Чистка списков
    cout << "Wiping lists:" << endl;
    list1.clear();
    list2.clear();
    list3.clear();

    cout << "List1 (init): ";
    list1.print();
    cout << endl;
    cout << "List2 (empty): ";
    list2.print();
    cout << endl;
    cout << "List3 (copy of List1): ";
    list3.print();
    cout << endl << endl;

    cout << "Please, enter number of elements: ";
    cin >> n;
    cout << "Please, enter " << n << " numbers: ";
    list <int> listTask(n);
    for (int i = 0; i < n; ++i) {
        cin >> listTask[i];
    }
    cout << endl;
    cout << "List: ";
    listTask.print();
    cout << endl << "Product is " << listTask.getProd() << endl << endl;

    system("pause");
    return 0;
}
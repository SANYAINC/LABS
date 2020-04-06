#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <list>
using namespace std;

#define AMOUNT 8


//Сложно сказать какой контейнер лучше.
//Вставка данных не требуется, а двусвязный список list позволяет обходить контейнер в нужных направлениях, так что доступ за O(1) не дает преимуществ

//Считаю оба контейнера эквивалентны


int getProd(list<int>& numbers);
int getProd(vector<int>& numbers);

int main() {
    srand(time(nullptr));

    list<int> numbersL;
    for (int i = 0; i < AMOUNT; ++i) {
        numbersL.push_back(i + 1);
    }

    for (list<int>::iterator i = numbersL.begin(); i != numbersL.end() ; ++i) {
        cout << *i << ' ';
    }
    cout << endl << getProd(numbersL);
    
    
    cout << endl << endl;
    
    
    vector<int> numbersV;
    for (int i = 0; i < AMOUNT; ++i) {
        numbersV.push_back(i + 1);
    }

    for (vector<int>::iterator i = numbersV.begin(); i != numbersV.end() ; ++i) {
        cout << *i << ' ';
    }
    cout << endl << getProd(numbersV);

    return 0;
}

int getProd(list<int>& numbers) {
    if (numbers.size()%2 != 0) {
        exit(1);
    }

    list<int>::iterator iter1 = numbers.begin();
    list<int>::iterator iter2 = numbers.end();
    --iter2;

    unsigned int n = numbers.size()/2;
    int result = 1;

    for (int i = 0; i < n; ++i) {
        result *= *iter1++ - *iter2--;
    }

    return result;
}
int getProd(vector<int>& numbers) {
    if (numbers.size()%2 != 0) {
        exit(1);
    }

    unsigned int n = numbers.size()/2;
    int result = 1;

    unsigned int ptr1 = 0;
    unsigned int ptr2 = numbers.size()-1;

    for (int i = 0; i < n; ++i) {
        result *= numbers[ptr1++] - numbers[ptr2--];
    }

    return result;
}
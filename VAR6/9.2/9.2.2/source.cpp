#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <list>

#define AMOUNT1 30
#define AMOUNT2 35

using namespace std;

void fill(vector<char>& container, int amount);
void fill(list<char>& container, int amount);

vector<char> getRepeatsFrom(vector<char>& L1, vector<char>& L2);
list<char> getRepeatsFrom(list<char>& L1, list<char>& L2);

//L1, L2, L проходятся последовательно, т.е произвольный доступ не дает выйгрыша.
//Если учитытывать перевыделение памяти при добавлении элементов в результирующий вектор, то тут list даст преимущество за счет константой сложности добавления.

int main() {
    srand(time(nullptr));

    vector<char> L1V;
    vector<char> L2V;
    fill(L1V, AMOUNT1);
    fill(L2V, AMOUNT2);

    cout << "Vector" << endl;
    for (int i = 0; i < AMOUNT1; ++i) {
        cout << L1V[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < AMOUNT2; ++i) {
        cout << L2V[i] << ' ';
    }
    cout << endl << endl;

    vector<char> resultV = getRepeatsFrom(L1V, L2V);

    for (int i = 0; i < resultV.size(); ++i) {
        cout << resultV[i] << ' ';
    }



    cout << endl << endl;



    list<char> L1L;
    list<char> L2L;
    fill(L1L, AMOUNT1);
    fill(L2L, AMOUNT2);

    cout << "List" << endl;
    for (list<char>::iterator elem = L1L.begin(); elem != L1L.end() ; ++elem) {
        cout << *elem << ' ';
    }
    cout << endl;
    for (list<char>::iterator elem = L2L.begin(); elem != L2L.end() ; ++elem) {
        cout << *elem << ' ';
    }
    cout << endl << endl;

    list<char> resultL = getRepeatsFrom(L1L, L2L);

    for (list<char>::iterator elem = resultL.begin(); elem != resultL.end() ; ++elem) {
        cout << *elem << ' ';
    }
    return 0;
}

void fill(vector<char>& container, int amount) {
    container.resize(amount);
    for (int i = 0; i < amount; ++i) {
        container[i] = rand() % 26 + 65;
    }
}
void fill(list<char>& container, int amount) {
    for (int i = 0; i < amount; ++i) {
        container.push_back(rand()%26 + 65);
    }
}
vector<char> getRepeatsFrom(vector<char>& L1, vector<char>& L2) {
    vector<char> result;
    //Дублирование кода позволяет избежать копирования вектора, что выигрывает 2 * |L1.size() - L2.size()| обращений
    if (L1.size() < L2.size()) {
        for (int i = 0; i < L1.size(); ++i) {
            for (int j = 0; j < L2.size(); ++j) {
                if (L1[i] == L2[j] and find(result.begin(), result.end(), L1[i]) == result.end()) {
                    result.push_back(L1[i]);
                }
            }
        }
    } else {
        for (int i = 0; i < L2.size(); ++i) {
            for (int j = 0; j < L1.size(); ++j) {
                if (L1[i] == L2[j] and find(result.begin(), result.end(), L2[i]) == result.end()) {
                    result.push_back(L2[i]);
                }
            }
        }
    }
    return result;
}
list<char> getRepeatsFrom(list<char>& L1, list<char>& L2) {
    list<char> result;
    //Дублирование кода позволяет избежать копирования списка, что выигрывает 2 * |L1.size() - L2.size()| обращений
    if (L1.size() < L2.size()) {
        for (list<char>::iterator elem1 = L1.begin(); elem1 != L1.end() ; ++elem1) {
            for (list<char>::iterator elem2 = L2.begin(); elem2 != L2.end() ; ++elem2) {
                if (*elem1 == *elem2 and find(result.begin(), result.end(), *elem1) == result.end()) {
                    result.push_back(*elem1);
                }
            }
        }
    } else {
        for (list<char>::iterator elem2 = L2.begin(); elem2 != L2.end() ; ++elem2) {
            for (list<char>::iterator elem1 = L1.begin(); elem1 != L1.end() ; ++elem1) {
                if (*elem1 == *elem2 and find(result.begin(), result.end(), *elem2) == result.end()) {
                    result.push_back(*elem2);
                }
            }
        }
    }
    return result;
}
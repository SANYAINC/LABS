#include <iostream>
#include "class.h"

using namespace std;

//В class.h подключен заголовок из лабы 8.4 (список) для построения списка смежности

int main() {

    graph <float> g1;

    int n;
    cout << "Please, enter number of vertices for Graph2: ";
    cin >> n;
    graph <char> g2(n);

    cout << "Graph1 (empty): ";
    g1.show();
    cout << "Graph2 (with n vertices): ";
    g2.show();

    int m;
    cout << endl << "Please, enter number of vertices to add to Graph1: ";
    cin >> m;
    for (int i = 0; i < m; ++i) {
        //Последовательно добавляются вершины в graph1.
        // Для каждой указывается на сколько вершин она указывает(если указывает, то на какие) и сколько вершин будут указывать на новую (если указывают, то какие)
        g1.pushVertex();
    }

    //Соединение вершин графа Graph2
    int connections, vertex1, vertex2;
    cout << endl << "Please, enter number of connection in Graph2 (0 - " << n*n-n <<"): ";
    cin >> connections;
    cout << "E.g 1 2 means lead the way from 1st to 2nd" << endl;
    if (connections < 0 or connections >= n * n - n) {
        exit(404);
    }
    for (int i = 0; i < connections; ++i) {
        cout << "Please, enter ID of vertices: ";
        cin >> vertex1;
        cin >> vertex2;
        if (vertex1 < 0 or vertex2 < 0 or vertex1 >= g2.getSize() or vertex2 >= g2.getSize()) {
            exit(404);
        }
        g2.connect(vertex1, vertex2);
    }

    cout << "Graph1 (with pushed vertices): ";
    g1.show();

    cout << "Graph2 (with added connections): ";
    g2.show();

    graph <char> g3(g2);
    cout << "Graph3 (copy of Graph2): ";
    g3.show();
    cout << endl;

    //Удаление вершин из графов Graph1 и Graph2
    int del1, del2;
    cout << "Please, select vertex to delete in Graph1 (0 - " << g1.getSize() - 1 << "): ";
    cin >> del1;
    g1.removeVertex(del1);
    cout << "Please, select vertex to delete in Graph2 (0 - " << g2.getSize() - 1 << "): ";
    cin >> del2;
    g2.removeVertex(del2);

    cout << endl << endl << "Graph1: ";
    g1.show();
    cout << endl;
    g1.showLongestPath();
    cout << endl;

    cout << endl << "Graph2: ";
    g2.show();
    cout << endl;
    g2.showLongestPath();
    cout << endl;

    cout << endl << "Graph3: ";
    g3.show();
    cout << endl;
    g3.showLongestPath();
    cout << endl;



    system("pause");
    return 0;
}


#include "7.8.h"

graphAdjMx::graphAdjMx(const int n) {
    if (n < 1) {
        exit(700);
    }
    mSize = n;

    //Динамическое выделение памяти для матрицы смежности
    int **adjacencyMatrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        adjacencyMatrix[i] = new int[n];
    }
    mAdjacencyMatrix = adjacencyMatrix;

    //Заполнение матрциы смежности
    bool buffer;
    for (int i = 0; i < n; ++i) {
        cout << "Please enter " << i << " adjacency string:\n";
        for (int j = 0; j < n; ++j) {
            cin >> buffer;
            mAdjacencyMatrix[i][j] = buffer;
        }
        cout << endl;
    }
}

void graphAdjMx::show() {
    cout << "    ";
    for (int i = 0; i < mSize; ++i) {
        cout << setw(4) << i;
    }
    cout << endl << "    ";
    for (int i = 0; i < mSize; ++i) {
        cout << "____";
    }
    cout << endl;
    for (int i = 0; i < mSize; ++i) {
        cout  << setw(2) << i << setw(2) << "|";
        for (int j = 0; j < mSize; ++j) {
            cout << setw(4) << mAdjacencyMatrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void graphAdjMx::showLongestPath() {
    int currentSolution[mSize + 1]; //Массив для хранения текущего пути
    int finalSolution[mSize + 1];   //Массив для хранения самого длинного пути
    for (int i = 0; i < mSize + 1; ++i) {
        currentSolution[i] = -1;
        finalSolution[i] = -1;
    }
    containers::listSingleDir<int>visitedVertex; //Список для хранения посещенных вершин
    int maxVisitedEdges = 0;    //Максимальное кол-во пройденных ребер

    //Перевод вершин чтобы начать путь
    for (int i = 0; i < mSize; ++i) {

        dfs(currentSolution, visitedVertex, maxVisitedEdges, i);
        //Если текущий путь длиннее максимального, записать его в максимальный
        if (currentSolution[0] > finalSolution[0]) {
            for (int j = 0; j < mSize + 1; ++j) {
                finalSolution[j] = currentSolution[j];
            }
        }
        //Обнуляем максимальное кол-во посещенных вершин
        maxVisitedEdges = 0;
    }
    cout << "The longest path is: ";
    for (int l = 0; l < finalSolution[0]; ++l) {
        cout << finalSolution[l+1] << " -> ";
    }
    cout << "\b\b\b\b     \n";
}

void graphAdjMx::dfs(int *solution, containers::listSingleDir<int> &visitedVertex, int &maxEdges,  int currentVertex) {
    static int visitedEdges = 0;    //Переменная для хранения кол-ва пройденных ребер

    //Если эта вершина посещена, возвращаемся назад
    if (visitedVertex.find(currentVertex)) {
        visitedEdges--;
        return;
    }
    //Перебор возможных связей у вершины
    for (int j = 0; j < mSize; ++j) {
        //Если есть связь
        if (mAdjacencyMatrix[currentVertex][j] == 1) {
            //Если вершна не добавлена, добавляем
            if (!visitedVertex.find(currentVertex)) {
                visitedVertex.pushBack(currentVertex);
            }
            visitedEdges++;
            dfs(solution, visitedVertex, maxEdges, j);
        }
    }
    if (!visitedVertex.find(currentVertex)) {
        visitedVertex.pushBack(currentVertex);
    }
    //Если текущий путь больше макимального
    if (visitedEdges > maxEdges) {
        maxEdges = visitedEdges;
        solution[0] = visitedVertex.getSize();  //На первое место в массиве решений кладем кол-во посещенных вершин
        //Копирование
        for (int i = 0; i < visitedVertex.getSize(); ++i) {
            solution[i + 1] = visitedVertex[i];
        }
    }
    //Возвращение назад
    visitedVertex.removeLast();
    if (visitedEdges > 0) {
        visitedEdges--;
    }
}

void graphAdjMx::pushVertex(int pointsToC, int pointedByC, const int *pointsToV, const int *pointedByV) {
    //Создание новой матрицы
    mSize++;
    int **newMatrix = new int*[mSize];
    for (int i = 0; i < mSize; ++i) {
        newMatrix[i] = new int[mSize];
    }
    //Копирование матрицы
    for (int i = 0; i < mSize - 1; ++i) {
        for (int j = 0; j < mSize - 1; ++j) {
            newMatrix[i][j] = mAdjacencyMatrix[i][j];
        }
    }
    //Заполнение строки и столбца вершины нулями
    for (int k = 0; k < mSize; ++k) {
        newMatrix[k][mSize - 1] = 0;
        newMatrix[mSize - 1][k] = 0;
    }

    for (int i = 0; i < mSize; ++i) {
        //Проводим связи к новой вершине
        for (int vI = 0; vI < pointedByC; ++vI) {
            if (i == pointedByV[vI]) {
                newMatrix[i][mSize - 1] = 1;
            }
        }
        //Проводим связи от новой вершины
        for (int vI = 0; vI < pointsToC; ++vI) {
            if (i == pointsToV[vI]) {
                newMatrix[mSize - 1][i] = 1;
            }
        }
    }
    //Очищение памяти
    for (int i = 0; i < mSize - 1; ++i) {
        delete [] mAdjacencyMatrix[i];
    }
    delete [] mAdjacencyMatrix;
    mAdjacencyMatrix = newMatrix;


}

void graphAdjMx::pushVertex() {
    int pointsToC;
    int pointedByC;

    cout << "New vertex will point to ___ vertexes: ";
    cin >> pointsToC;
    int *pointsToV = pointsToC > 0 ? new int[pointsToC] : nullptr;
    for (int i = 0; i < pointsToC; ++i) {
        cout << "\t" <<i+1 <<". New vertex will point to: ";
        cin >> pointsToV[i];
    }

    cout << "New vertex will be pointed by ___ vertexes: ";
    cin >> pointedByC;
    int *pointedByV = pointedByC > 0 ? new int[pointedByC] : nullptr;
    for (int i = 0; i < pointedByC; ++i) {
        cout << "\t" << i+1 << ". New vertex will be pointed by: ";
        cin >> pointedByV[i];
    }

    pushVertex(pointsToC, pointedByC, pointsToV, pointedByV);
    cout << "PUSHED\n\n";
}








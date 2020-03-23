#pragma once
#include "../8.4/class.h"

template <class T>
class graph {
    class vertex {
    public:

        int mID;
        T mData;
        list <int> mPointTo;

        vertex(int ID = 0, T data = 0);
        void setID(int ID);
    };

    list <vertex> mAdjacencyList;
    int mVertices;
    int mEdges;

    void DFS(list <int>& solution, int currentVertex);
    int getIndexByID(int ID);
public:
    graph();
    graph(int vertices);
    graph(const graph& anotherGraph);
    ~graph();

    T& operator[](int index);

    void connect(int ID1, int ID2);
    void pushVertex(T data, int pointToAmount, int* pointToVector, int pointedByAmount, int* pointedByVector); //На какие вершины будет указывать новая/какие вершины будут указывать на новую
    void pushVertex(T data = 0);
    void removeVertex(int index);
    void show();
    int getSize();
    void showLongestPath();
    
    void clear();
};

template <class T>
graph <T>::vertex::vertex(int ID, T data) {
    mID = ID;
    mData = data;
}

template <class T>
void graph <T>::vertex::setID(int ID) {
    mID = ID;
}

template <class T>
graph <T>::graph() {
    mVertices = 0;
    mEdges = 0;
}

template <class T>
graph <T>::graph(int vertices) {
    mVertices = vertices;
    mEdges = 0;
    vertex temp(0);
    for (int i = 0; i < vertices; ++i) {
        temp.setID(i);
        mAdjacencyList.pushBack(temp);
    }
}

template <class T>
graph <T>::graph(const graph& anotherGraph) {
    mVertices = anotherGraph.mVertices;
    mEdges = anotherGraph.mEdges;
    mAdjacencyList = anotherGraph.mAdjacencyList;
}

template <class T>
void graph <T>::connect(int ID1, int ID2) {
    mAdjacencyList[ID1].mPointTo.pushBack(ID2);
    mEdges++;
}

template <class T>
void graph <T>::pushVertex(T data, int pointToAmount, int* pointToVector, int pointedByAmount, int* pointedByVector) {
    int maxID = -1;
    for (int k = 0; k < mAdjacencyList.getSize(); ++k) {
        if (mAdjacencyList[k].mID > maxID) {
            maxID = mAdjacencyList[k].mID;
        }
    }
    vertex newVertex(maxID+1, data);
    for (int i = 0; i < pointToAmount; ++i) {
        newVertex.mPointTo.pushBack(pointToVector[i]);
        mEdges++;
    }
    mAdjacencyList.pushBack(newVertex);
    for (int j = 0; j < pointedByAmount; ++j) {
        mAdjacencyList[pointedByVector[j]].mPointTo.pushBack(mVertices);
        mEdges++;
    }
    mVertices++;
}

template <class T>
void graph <T>::pushVertex(T data) {
    int pointToA;
    int pointedByA;
    std::cout << "-----PUSHING SEQUENCE STARTED-----" << std::endl;
    std::cout << "New vertex #" << mVertices << " will point to _ vertices: ";
    std::cin >> pointToA;
    int* pointToV = new int[pointToA];
    for (int i = 0; i < pointToA; ++i) {
        std::cout << "\t" << i + 1 << ") Vertex #" << mVertices << " will point to: ";
        std::cin >> pointToV[i];
    }
    std::cout << "New vertex #" << mVertices << " will be pointed by _ vertices: ";
    std::cin >> pointedByA;
    int* pointedByV = new int[pointedByA];
    for (int i = 0; i < pointedByA; ++i) {
        std::cout << "\t" << i + 1 << ") Vertex #" << mVertices << " will be pointed by: ";
        std::cin >> pointedByV[i];
    }
    pushVertex(data, pointToA, pointToV, pointedByA, pointedByV);
    std::cout << "---------PUSHING COMPLETE---------" << std::endl;
}

template <class T>
void graph <T>::removeVertex(int index) {
    for (int i = 0; i < mVertices; ++i) {
        if (i != index) {
            for (int j = 0; j < mAdjacencyList[i].mPointTo.getSize(); ++j) {
                if (mAdjacencyList[i].mPointTo[j] == index) {
                    mAdjacencyList[i].mPointTo.deleteAt(j);
                    mEdges--;
                }
            }
        }
    }
    mAdjacencyList.deleteAt(index);
    mVertices--;
}

template <class T>
void graph <T>::show() {
    std::cout << "Graph's adjacency list:" << std::endl;
    if (mVertices == 0) {
        std::cout << "\t//EMPTY//" << std::endl;
        return;
    }
    int edgesWithCurVertex;
    int curID;
    for (int i = 0; i < mVertices; ++i) {
        curID = mAdjacencyList[i].mID;
        std::cout << "\t" << curID << " -> ";
        edgesWithCurVertex = mAdjacencyList[i].mPointTo.getSize();
        for (int j = 0; j < edgesWithCurVertex; ++j) {
            std::cout << mAdjacencyList[i].mPointTo[j];
            if (j != edgesWithCurVertex - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

template <class T>
void graph <T>::clear() {
    for (int i = 0; i < mVertices; ++i) {
        mAdjacencyList[i].mPointTo.clear();
    }
    mAdjacencyList.clear();
    mVertices = 0;
    mEdges = 0;
}

template <class T>
graph <T>::~graph() {
    clear();
}

template <class T>
T& graph <T>::operator[](int index) {
    if (index < 0 or index >= mVertices) {
        std::cerr << "INDEX OUT OF RANGE";
    } else {
        return mAdjacencyList[index].mData;
    }
}

template <class T>
void graph <T>::DFS(list <int>& solution, int currentVertex) {
    static list <int> visitedVertex;

    if (visitedVertex.find(mAdjacencyList[currentVertex].mID) != -1) {
        return;
    }

    for (int i = 0; i < mAdjacencyList[currentVertex].mPointTo.getSize(); ++i) {
        if (visitedVertex.find(mAdjacencyList[currentVertex].mID) == -1) {
            visitedVertex.pushBack(mAdjacencyList[currentVertex].mID);
        }
        DFS(solution, getIndexByID(mAdjacencyList[currentVertex].mPointTo[i]));
    }
    if (visitedVertex.find(mAdjacencyList[currentVertex].mID) == -1) {
        visitedVertex.pushBack(mAdjacencyList[currentVertex].mID);
    }
    if (visitedVertex.getSize() > solution.getSize()) {
        solution = visitedVertex;
    }
    visitedVertex.deleteAt(visitedVertex.getSize()-1);
}

template <class T>
void graph <T>::showLongestPath() {
    list <int> curSolution;
    list <int> finSolution;
    for (int i = 0; i < mVertices; ++i) {
        DFS(curSolution, i);
        if (curSolution.getSize() > finSolution.getSize()) {
            finSolution = curSolution;
        }
        curSolution.clear();
    }
    std::cout << "The longest path is: ";
    int solSize = finSolution.getSize();
    for (int j = 0; j < solSize; ++j) {
        std::cout << finSolution[j];
        if (j != solSize - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

template <class T>
int graph <T>::getSize() {
    return mVertices;
}

template <class T>
int graph<T>::getIndexByID(int ID) {
    for (int i = 0; i < mVertices; ++i) {
        if ((*this).mAdjacencyList[i].mID == ID) {
            return i;
        }
    }
    return -1;
}


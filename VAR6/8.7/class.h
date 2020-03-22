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
    void showData();

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
    vertex newVertex(mVertices, data);
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
    std::cout << "-----PUSHING COMPLETE-----" << std::endl;
}

template <class T>
void graph <T>::removeVertex(int index) {
    int edgesCurVertex;
    for (int i = 0; i < mVertices; ++i) {
        if (i != index) {
            edgesCurVertex = mAdjacencyList[i].mPointTo.getSize();
            for (int j = 0; j < edgesCurVertex; ++j) {
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
    int edgesWithCurVertex;

    std::cout << "Graph's adjacency list:" << std::endl;
    for (int i = 0; i < mVertices; ++i) {
        std::cout << "\t" << i << " -> ";
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
void graph <T>::showData() {
    int edgesWithCurVertex;

    std::cout << "Graph's adjacency list (with data):" << std::endl;
    for (int i = 0; i < mVertices; ++i) {
        std::cout << "\t" << i << "(" << mAdjacencyList[i].mData << ")"<< " -> ";
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
void graph <T>::DFS(list <int>& solution, int currentVertex) {
    static list <int> visitedVertex;

    if (visitedVertex.find(currentVertex) != -1) {
        return;
    }

    for (int i = 0; i < mAdjacencyList[currentVertex].mPointTo.getSize(); ++i) {
        if (visitedVertex.find(currentVertex) == -1) {
            visitedVertex.pushBack(currentVertex);
        }
        DFS(solution, mAdjacencyList[currentVertex].mPointTo[i]);
    }
    if (visitedVertex.find(currentVertex) == -1) {
        visitedVertex.pushBack(currentVertex);
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


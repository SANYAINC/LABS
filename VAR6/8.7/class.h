#pragma once
#include "../8.4/class.h"


class graph {
    list <list <int>> mAdjacencyList;
    int mVertices;
    int mEdges;
public:
    graph();
    graph(int vertices);
    graph(const graph& anotherGraph);
    ~graph();
    void connect(int vertex1, int vertex2);
    void pushVertex(int pointToAmount, int* pointToVector, int pointedByAmount, int* pointedByVector);
    void pushVertex();
    void removeVertex(int index);
    void show();
    void clear();
};
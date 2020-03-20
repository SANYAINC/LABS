#pragma once
#include "../8.4/class.h"


class graph {
    list <list <int>> adjacencyList;
    int mSize;

public:
    graph();
    graph(int vertices);
    graph(const graph& anotherGraph);
    ~graph();

    void pushVertex();
    void pushVertex(int pointToAmount, int* pointToVector, int pointedByAmount, int* pointedByVector);
    void removeVertex(int index);
    void show();
    void clear();
};
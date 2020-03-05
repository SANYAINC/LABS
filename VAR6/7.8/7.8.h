#pragma once

#include <iostream>
#include <iomanip>
#include "../../common/common.h"

using namespace containers;

class graphAdjMx {
    int **mAdjacencyMatrix;
    int mSize;

    void dfs(int *solution, containers::listSingleDir <int> &visitedVertex, int &maxEdges, int currentVertex = 0);

public:
    graphAdjMx(int n);

    void show();

    void showLongestPath();

    void pushVertex(int pointsToC, int pointedByC, const int *pointsToV, const int *pointedByV);

    void pushVertex();
};

class graphAdjList {
    listSingleDir < listSingleDir<int> > mAdjacencyList;
    int mVertexAmount;

    void dfs(int *solution, containers::listSingleDir <int> &visitedVertex, int &maxEdges, int currentVertex = 0);

public:

    graphAdjList();

    graphAdjList(int n);

    void show();

    void showLongestPath();

    void pushVertex();
};

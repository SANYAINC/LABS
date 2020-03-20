#include "class.h"

graph::graph() {
    mVertices = 0;
    mEdges = 0;
}

graph::graph(const int vertices) {
    mVertices = vertices;
    mEdges = 0;
    list <int> temp;
    for (int i = 0; i < vertices; ++i) {
        mAdjacencyList.pushBack(temp);
    }
}

graph::graph(const graph& anotherGraph) {
    mVertices = anotherGraph.mVertices;
    mEdges = anotherGraph.mEdges;
    mAdjacencyList = anotherGraph.mAdjacencyList;
}

void graph::connect(int vertex1, int vertex2) {
    mAdjacencyList[vertex1].pushBack(vertex2);
    mEdges++;
}

void graph::pushVertex(int pointToAmount, int* pointToVector, int pointedByAmount, int* pointedByVector) {
    list <int> newVertex;
    for (int i = 0; i < pointToAmount; ++i) {
        newVertex.pushBack(pointToVector[i]);
        mEdges++;
    }
    mAdjacencyList.pushBack(newVertex);
    for (int j = 0; j < pointedByAmount; ++j) {
        mAdjacencyList[pointedByVector[j]].pushBack(mVertices);
        mEdges++;
    }
    mVertices++;
}

void graph::pushVertex() {
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
    pushVertex(pointToA, pointToV, pointedByA, pointedByV);
    std::cout << "-----PUSHING COMPLETE-----" << std::endl;

}

void graph::show() {
    int edgesWithCurVertex;

    std::cout << "Graph's adjacency list:" << std::endl;
    for (int i = 0; i < mVertices; ++i) {
        std::cout << "\t" << i << " -> ";
        edgesWithCurVertex = mAdjacencyList[i].getSize();
        for (int j = 0; j < edgesWithCurVertex; ++j) {
            std::cout << mAdjacencyList[i][j];
            if (j != edgesWithCurVertex - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

void graph::removeVertex(const int index) {
    int edgesWithCurVertex;
    for (int i = 0; i < mVertices; ++i) {
        if (i != index) {
            edgesWithCurVertex = mAdjacencyList[i].getSize();
            for (int j = 0; j < edgesWithCurVertex; ++j) {
                if (mAdjacencyList[i][j] == index) {
                    mAdjacencyList[i].deleteAt(j);
                    mEdges--;
                }
            }
        }
    }
    mAdjacencyList.deleteAt(index);
    mVertices--;
}

void graph::clear() {
    for (int i = 0; i < mVertices; ++i) {
        mAdjacencyList[i].clear();
    }
    mAdjacencyList.clear();
    mVertices = 0;
    mEdges = 0;
}

graph::~graph() {
    clear();
}

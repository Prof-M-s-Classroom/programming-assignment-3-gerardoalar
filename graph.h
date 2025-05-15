#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
        }
        for (int i = 0; i < numVertices; i++) {
            for (int j =0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        std::cout<<"Destroying graph"<<std::endl;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        MinHeap minHeap = MinHeap(numVertices);
        int i;
        int total = 0;
        int j;
        while (!minHeap.isEmpty()) {
            for (i = 0; i < numVertices; i++) {
                for (j = 0; j < numVertices; j++) {
                    if (adjMatrix[i][j] != 0 && minHeap.isInMinHeap(i)) {
                        minHeap.decreaseKey(j,adjMatrix[i][j]);
                    }
                }
                int minkey = minHeap.extractMin();
                total += minkey;
                if (minkey > 0) {
                    for (j = 0; j < numVertices; j++) {
                        if (adjMatrix[i][j] == minkey) {
                            std::cout<<j<<" -- "<<i<<" ("<<minkey<<")"<<std::endl;
                        }
                    }
                }
            }
            std::cout<<"Total weight: "<<total<<std::endl;
        }
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif
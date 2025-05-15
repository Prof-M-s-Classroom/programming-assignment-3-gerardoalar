[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Gerardo Alarcon

## Description
This project impliments prims algorithm for
constructing minimum spanning trees from
a given set of vertices, edges, and weights

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity   |
|----------------------|-------------------|
| Insert in MinHeap    |      O(1)         |
| Extract Min          |      O(n)         |
| Decrease Key         |      O(1)         |
| Prim’s MST Overall   |      O(n^2)       |

_Explain why your MST implementation has the above runtime._
Insert - The method that inserts into the MinHeap
inserts the lowest edge weight directly into the
KeyArray if it is lower than an existing path 
directly through array index insertion.


Extract Min - The extract method returns the 
lowest weight and then updates the MinHeap
by calling the minHeapify method which
removes the lowest index and resizes the array
by running through n-1 elements each time.

Decrease Key - Decrease key method uses
array indexes to directly update weights
and calls the insert function to update
the KeyArray, both using constant time
operations.

Prim's MST Overall - The Prim's method
uses 2 nested for loops in order to 
iterate through the graph, execute
functions, and display results
as they are computed.

## Test Case Description

Input:  
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);
g.primMST();

Output:
0 -- 1 (2)
1 -- 2 (3)
0 -- 3 (6)
1 -- 4 (5)
Total weight: 16
Destroying heap
Destroying graph

#pragma once

// Заголовковий файл для оголошення класу графа
class Graph {
private:
    int** adjMatrix;
    bool* visited;
    int* dfsNumber, * bfsNumber;
    int vertices;
    int dfsCount, bfsCount;

    void dfsRecursiveUtil(int v);

public:
    Graph();
    ~Graph();
    void init(int n);
    void inputMatrix();
    void resetVisited();
    void dfsNonRecursive(int start);
    void dfsRecursive(int start);
    void bfs(int start);
};
#include <iostream>
#include <stack>
#include <queue>
#include "Graph.h"

using namespace std;

// Конструктор
Graph::Graph() : adjMatrix(nullptr), visited(nullptr), dfsNumber(nullptr), bfsNumber(nullptr), vertices(0), dfsCount(0), bfsCount(0) {}

// Деструктор
Graph::~Graph() {
    if (adjMatrix) {
        for (int i = 0; i < vertices; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
            delete[] visited;
            delete[] dfsNumber;
            delete[] bfsNumber;
        
    
}

// Ініціалізація графа
void Graph::init(int n) {
    vertices = n;
    adjMatrix = new int* [vertices];
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = new int[vertices];
    }

    visited = new bool[vertices];
    dfsNumber = new int[vertices];
    bfsNumber = new int[vertices];
    resetVisited();
}

// Ввід матриці суміжності
void Graph::inputMatrix() {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cin >> adjMatrix[i][j];
        }
    }
}

// Скидання міток відвіданих вершин
void Graph::resetVisited() {
    for (int i = 0; i < vertices; ++i) {
        visited[i] = false;
        dfsNumber[i] = 0;
        bfsNumber[i] = 0;
    }
    dfsCount = 0;
    bfsCount = 0;
}

// Нерекурсивний DFS
void Graph::dfsNonRecursive(int start) {
    resetVisited();
    stack<int> s;
    s.push(start);
    visited[start] = true;
    dfsNumber[start] = ++dfsCount;

 
    
    
    while (!s.empty()) {
        int v = s.top();
        bool found = false;

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[v][i] && !visited[i]) {
                visited[i] = true;
                dfsNumber[i] = ++dfsCount;
                cout << "v" << v + 1 << " -> v" << i + 1 << "\n";
                s.push(i);
                found = true;
                break;
            }
        }

        if (!found) s.pop();
    }

    cout << "\nDFS numbers:\n";
    for (int i = 0; i < vertices; ++i)
        cout << "v[" << i + 1 << "] = " << dfsNumber[i] << "\n";
}

// Рекурсивний DFS
void Graph::dfsRecursiveUtil(int v) {
    visited[v] = true;
    dfsNumber[v] = ++dfsCount;

    for (int i = 0; i < vertices; ++i) {
        if (adjMatrix[v][i] && !visited[i]) {
            cout << "v" << v + 1 << " -> v" << i + 1 << "\n";
            dfsRecursiveUtil(i);
        }
    }
}

void Graph::dfsRecursive(int start) {
    resetVisited();
    cout << "DFS Traversal (recursive):\n";
    dfsRecursiveUtil(start);
    cout << "\nDFS numbers:\n";
    for (int i = 0; i < vertices; ++i)
        cout << "v" << i + 1 << ": " << dfsNumber[i] << "\n";
}

// Пошук у ширину
void Graph::bfs(int start) {
    resetVisited();
    queue<int> q;
    visited[start] = true;
    bfsNumber[start] = ++bfsCount;
    q.push(start);

    cout << "BFS traversal:\n";

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[v][i] && !visited[i]) {
                visited[i] = true;
                bfsNumber[i] = ++bfsCount;
                cout << "v" << v + 1 << " -> v" << i + 1 << "\n";
                q.push(i);
            }
        }
    }

    cout << "\nBFS numbers:\n";
    for (int i = 0; i < vertices; ++i)
        cout << "v" << i + 1 << ": " << bfsNumber[i] << "\n";
}

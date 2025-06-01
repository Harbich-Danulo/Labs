#include <iostream>
#include <limits>
#include <stack>
#include "dijkstra.h"

using namespace std;

// Example graph; update this for your variant
int Adj[N][N] = {
     { 0, 1, 5, INF, INF, INF, INF },
    { INF, 0, 3, INF, 2, 8, 20 },
    { INF, INF, 0, INF, INF, 4, INF },
    { INF, INF, 9, 0, INF, INF, INF },
    { INF, INF, INF, INF, INF, INF, INF },
    { INF, INF, INF, INF, INF, 0, 7 },
    { INF, INF, INF, INF, INF, INF, 0 }
};

void dijkstra(int start, int end) {
    int Length[N];
    bool Label[N];
    int Vertex[N];

    // Step 1: Initialization
    for (int i = 0; i < N; ++i) {
        Length[i] = INF;
        Label[i] = false;
        Vertex[i] = -1;
    }
    Length[start] = 0;

    for (int count = 0; count < N; ++count) {
        // Step 3: Find vertex with minimal temporary label
        int u = -1;
        for (int i = 0; i < N; ++i)
            if (!Label[i] && (u == -1 || Length[i] < Length[u]))
                u = i;

        if (Length[u] == INF)
            break;

        Label[u] = true;

        // Step 2: Update neighbors
        for (int v = 0; v < N; ++v) {
            if (!Label[v] && Adj[u][v] > 0) {
                if (Length[u] + Adj[u][v] < Length[v]) {
                    Length[v] = Length[u] + Adj[u][v];
                    Vertex[v] = u;
                }
            }
        }
    }

    // Output results
    if (end != -1) {
        if (Length[end] == INF) {
            cout << "No path from vertex " << start << " to vertex " << end << ".\n";
        }
        else {
            cout << "Shortest path from vertex " << start << " to vertex " << end << " is " << Length[end] << ".\n";
            stack<int> path;
            for (int v = end; v != -1; v = Vertex[v])
                path.push(v);

            cout << "Path: ";
            while (!path.empty()) {
                cout << path.top();
                path.pop();
                if (!path.empty()) cout << " -> ";
            }
            cout << "\n";
        }
    }
    else {
        cout << "Shortest paths from vertex " << start << ":\n";
        for (int i = 0; i < N; ++i) {
            cout << "To vertex " << i << ": ";
            if (Length[i] == INF) {
                cout << "No path.\n";
            }
            else {
                cout << Length[i] << " | Path: ";
                stack<int> path;
                for (int v = i; v != -1; v = Vertex[v])
                    path.push(v);
                while (!path.empty()) {
                    cout << path.top();
                    path.pop();
                    if (!path.empty()) cout << " -> ";
                }
                cout << "\n";
            }
        }
    }
}

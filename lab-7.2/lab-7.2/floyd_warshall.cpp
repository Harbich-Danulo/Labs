#include "floyd_warshall.h"
#include <iostream>
#include <algorithm>

using namespace std;

void printMatrix(const vector<vector<int>>& m, const string& symbol, int k) {
    cout << symbol << "(" << k << ")\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] >= INF) {
                cout << " INF";
            }
            else {
                cout << m[i][j];
            }
            if (j + 1 < n) cout << " ";
        }
        cout << (i + 1 < n ? "," : "") << "\n\n";
    }
}

void floyd(vector<vector<int>>& d, vector<vector<int>>& p) {
    printMatrix(d, "d", 0);
    printMatrix(p, "p", 0);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }

        printMatrix(d, "d", k + 1);
        printMatrix(p, "p", k + 1);
    }

    for (int i = 0; i < n; ++i)
        if (d[i][i] < 0) {
            cout << "Graph contains a negative cycle!\n";
            return;
        }
}

void Path(int u, int v, const vector<vector<int>>& p) {
    if (p[u][v] == 0) {
        cout << "No path exists.\n";
        return;
    }

    vector<int> path;
    while (v != u) {
        path.push_back(v);
        v = p[u][v] - 1;
    }
    path.push_back(u);
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] + 1;
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << "\n";
}
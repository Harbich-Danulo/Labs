#include "graph_utils.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> readWeightMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the weight matrix (use -1 for INF):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            if (val == -1) matrix[i][j] = INF;
            else matrix[i][j] = val;
        }
    }
    return matrix;
}

void initializePathMatrix(vector<vector<int>>& path, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            path[i][j] = (i != j) ? i : -1;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == INF)
                cout << "INF ";
            else
                cout << setw(4) << val << " ";
        }
        cout << endl;
    }
}

void printPath(const vector<int>& path) {
    if (path.empty()) {
        cout << "No path exists.\n";
        return;
    }
    cout << "Shortest path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << "v" << path[i] + 1;
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

#include <iostream>
#include <vector>
#include "floyd_warshall.h"

using namespace std;

int main() {
    vector<vector<int>> d = {
        {   0,   1,   6, INF, INF, INF },
        { INF,   0,   4, INF,  -2, INF },
        { INF, INF,   0, INF,   5,   3 },
        {   2, INF, INF,   0,  -5, INF },
        { INF, INF, INF,   8,   0,   4 },
        { INF, INF, INF, INF, INF,   0 }
    };

    vector<vector<int>> p(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            p[i][j] = (i == j ? 0 : i + 1);

    floyd(d, p);

    int u, v;
    cout << "Enter two vertex numbers (1-6): ";
    cin >> u >> v;
    --u; --v;

    if (d[u][v] >= INF) {
        cout << "No path from " << u + 1 << " to " << v + 1 << ".\n";
    }
    else {
        cout << "Shortest path from " << u + 1 << " to " << v + 1 << ": ";
        Path(u, v, p);
        cout << "Length: " << d[u][v] << "\n";
    }

    return 0;
}
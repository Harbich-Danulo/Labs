#include <iostream>
#include "dijkstra.h"

using namespace std;

int main() {
    int mode, start, end;

    cout << "Choose mode:\n";
    cout << "1 - Shortest path between two vertices\n";
    cout << "2 - Shortest paths from a given vertex to all others\n";
    cout << "Enter mode (1 or 2): ";
    cin >> mode;

    cout << "Enter start vertex (0 to " << N - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= N) {
        cout << "Invalid start vertex.\n";
        return 1;
    }

    if (mode == 1) {
        cout << "Enter end vertex (0 to " << N - 1 << "): ";
        cin >> end;

        if (end < 0 || end >= N) {
            cout << "Invalid end vertex.\n";
            return 1;
        }

        dijkstra(start, end);
    }
    else if (mode == 2) {
        dijkstra(start);
    }
    else {
        cout << "Invalid mode.\n";
        return 1;
    }

    return 0;
}

#include <iostream>
#include <windows.h>
#include "Graph.h"

using namespace std;

int main() {
    int startVertex;
    Graph g;

    cout << "Enter number of vertices: ";
    int n;
    cin >> n;

    g.init(n);
    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    g.inputMatrix();

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. DFS (Non-Recursive)\n";
        cout << "2. DFS (Recursive)\n";
        cout << "3. BFS\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 4) break;

        cout << "Enter start vertex (1.." << n << "): ";
        cin >> startVertex;
        startVertex--; 

        switch (choice) {
        case 1:
            g.dfsNonRecursive(startVertex);
            break;
        case 2:
            g.resetVisited();
            g.dfsRecursive(startVertex);
            break;
        case 3:
            g.bfs(startVertex);
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (true);

}
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

const int INF = 1000000000;  
const int N = 7; 

extern int Adj[N][N];

void dijkstra(int start, int end = -1);

#endif  

#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define n 6
#define INF 99999

void printMatrix(const vector<vector<int>>& m, const std::string& symbol, int k);
void floyd(vector<vector<int>>& d, vector<vector<int>>& p);
void Path(int u, int v, const vector<vector<int>>& p);

#endif
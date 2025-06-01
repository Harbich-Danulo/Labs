#pragma once
#include <vector>

using namespace std;

vector<vector<int>> readWeightMatrix(int n);
void initializePathMatrix(vector<vector<int>>& path, int n);
void printMatrix(const vector<vector<int>>& matrix);
void printPath(const vector<int>& path);

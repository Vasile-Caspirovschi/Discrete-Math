#ifndef CONVERT_FROM_GRAPH_HPP
#define CONVERT_FROM_GRAPH_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> FromIncMatrixToAdjMatrix(vector<vector<int>> incMatrix);
vector<vector<int>> FromIncMatrixToAdjList(vector<vector<int>> incMatrix);

vector<vector<int>> FromAdjMatrixToIncMatrix(vector<vector<int>> adjMatrix);
vector<vector<int>> FromAdjMatrixToAdjList(vector<vector<int>> adjMatrix);

vector<vector<int>> FromAdjListToIncMatrix(vector<vector<int>> adjList, vector<int> vertices);
vector<vector<int>> FromAdjListToAdjMatrix(vector<vector<int>> adjList, vector<int> vertices);
#endif
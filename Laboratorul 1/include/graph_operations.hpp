#ifndef PRINT_GRAPH_HPP
#define PRINT_GRAPH_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ReadGraphIncMatrix();
vector<vector<int>> ReadGraphAdjMatrix();
vector<vector<int>> ReadGraphAdjList();
pair<int, int> ReadEdge(int n, vector<int> vertices);
int ReadNumbersOfVertices();
int ReadNumbersOfEdges(int n);
vector<int> ReadVerteces(vector<int>);
vector<vector<int>> AddVertex(vector<vector<int>> graph, vector<int> &vertices, int graphForm);
vector<vector<int>> DeleteVertex(vector<vector<int>> graph, vector<int> &vertices, int graphForm);
vector<vector<int>> AddEdges(vector<vector<int>> graph, int graphForm, vector<int> vertices);
vector<vector<int>> DeleteEdges(vector<vector<int>> graph, int graphForm, vector<int> vertices);
void PrintGraphIncMatrix(vector<vector<int>> incMatrix, vector<int> vertexes);
void PrintGraphAdjMatrix(vector<vector<int>> adjMatrix, vector<int> vertexes);
void PrintGraphAdjList(vector<vector<int>> adjList, vector<int> vertices);

#endif
// #include "Headers/convert_form_graph.hpp"
#include "convert_form_graph.hpp"

vector<vector<int>> FromIncMatrixToAdjMatrix(vector<vector<int>> incMatrix)
{
    int vertices = incMatrix[0].size();
    int edges = incMatrix.size();
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices));

    for (int edge = 0; edge < edges; edge++)
    {
        int u = -1, v = -1, vertex = 0;
        for (; vertex < vertices && u == -1; vertex++)
            if (incMatrix[edge][vertex])
                u = vertex;
        for (; vertex < vertices && v == -1; vertex++)
            if (incMatrix[edge][vertex])
                v = vertex;
        if (v == -1)
            v == u;
        adjMatrix[u][v] = 1;
    }
    return adjMatrix;
}

vector<vector<int>> FromIncMatrixToAdjList(vector<vector<int>> incMatrix)
{
    int vertices = incMatrix[0].size();
    int edges = incMatrix.size();
    vector<vector<int>> adjList(vertices);

    for (int edge = 0; edge < edges; edge++)
    {
        int u = -1, v = -1, vertex = 0;
        for (; vertex < vertices && u == -1; vertex++)
            if (incMatrix[edge][vertex])
                u = vertex;
        for (; vertex < vertices && v == -1; vertex++)
            if (incMatrix[edge][vertex])
                v = vertex;
        if (v == -1)
            v == u;
        adjList[u].push_back(v + 1);
    }
    return adjList;
}

vector<vector<int>> FromAdjMatrixToIncMatrix(vector<vector<int>> adjMatrix)
{
    int edges = 0;
    int vertices = adjMatrix.size();
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (adjMatrix[i][j])
                edges++;

    vector<vector<int>> incMatrix(edges, vector<int>(vertices));

    int edge = 0;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adjMatrix[i][j])
            {
                if (i == j)
                {

                    incMatrix[edge][i] = 2;
                    edge++;
                }
                else
                {

                    incMatrix[edge][i] = -1;
                    incMatrix[edge][j] = 1;
                    edge++;
                }
            }
        }
    }
    return incMatrix;
}

vector<vector<int>> FromAdjMatrixToAdjList(vector<vector<int>> adjMatrix)
{
    int vertices = adjMatrix.size();

    vector<vector<int>> adjList(vertices);

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (adjMatrix[i][j])
                adjList[i].push_back(j + 1);
    return adjList;
}

vector<vector<int>> FromAdjListToIncMatrix(vector<vector<int>> adjList, vector<int> vertexes)
{
    int vertices = adjList.size();
    int edges = 0, adjVertices;

    for (int i = 0; i < vertices; i++)
        edges += adjList[i].size();

    vector<vector<int>> incMatrix;

    for (int i = 0; i < vertices; i++)
    {
        int adjVertices = adjList[i].size();

        for (int j = 0; j < adjVertices; j++)
        {
            int index = find(vertexes.begin(), vertexes.end(), adjList[i][j]) - vertexes.begin();
            vector<int> temp(vertices);
            temp[i] = -1;
            temp[index] = 1;
            incMatrix.push_back(temp);
        }
    }
    return incMatrix;
}

vector<vector<int>> FromAdjListToAdjMatrix(vector<vector<int>> adjList, vector<int> vertexes)
{
    int vertices = adjList.size();

    vector<vector<int>> adjMatrix;

    for (int i = 0; i < vertices; i++)
    {
        int adjVertices = adjList[i].size();
        vector<int> temp(vertices);
        for (int j = 0; j < adjVertices; j++)
        {
            int index = find(vertexes.begin(), vertexes.end(), adjList[i][j]) - vertexes.begin();
            temp[index] = 1;
        }
        adjMatrix.push_back(temp);
    }
    return adjMatrix;
}

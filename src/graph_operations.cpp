// #include "Headers/read_print_graph.hpp"
#include "graph_operations.hpp"

vector<vector<int>> AddEdges(vector<vector<int>> graph, int graphForm, vector<int> vertices)
{
    cout << "Cite arcuri doriti sa adaugati? m: ";
    int n, m;
    if (graphForm == 1)
        n = graph[0].size();
    else
        n = graph.size();
    m = ReadNumbersOfEdges(n);
    cout << "Itroduceti arcurile:\n";

    for (int i = 0; i < m; i++)
    {
        pair<int, int> edge = ReadEdge(graph.size(), vertices);
        int indexX = find(vertices.begin(), vertices.end(), edge.first) - vertices.begin();
        int indexY = find(vertices.begin(), vertices.end(), edge.second) - vertices.begin();
        if (graphForm == 1)
        {
            vector<int> temp(n);
            temp[indexX] = -1;
            temp[indexY] = 1;
            graph.push_back(temp);
        }
        if (graphForm == 2)
            graph[indexX][indexY] = 1;
        if (graphForm == 3)
            graph[indexX].push_back(edge.second);
    }
    return graph;
}

vector<vector<int>> DeleteEdges(vector<vector<int>> graph, int graphForm, vector<int> vertices)
{
    if (graphForm == 1)
        PrintGraphIncMatrix(graph, vertices);
    if (graphForm == 2)
        PrintGraphAdjMatrix(graph, vertices);
    if (graphForm == 3)
        PrintGraphAdjList(graph, vertices);

    cout << "\nCite arcuri doriti sa stergeti? m: ";
    int n, m;
    bool foundEdge = false;
    if (graphForm == 1)
        n = graph[0].size();
    else
        n = graph.size();
    m = ReadNumbersOfEdges(n);
    cout << "Itroduceti arcurile:\n";

    for (int i = 0; i < m; i++)
    {
        pair<int, int> edge = ReadEdge(graph.size(), vertices);
        int indexX = find(vertices.begin(), vertices.end(), edge.first) - vertices.begin();
        int indexY = find(vertices.begin(), vertices.end(), edge.second) - vertices.begin();

        if (graphForm == 1)
        {
            for (int i = 0; i < graph.size(); i++)
            {
                if (graph[i][indexX] == -1 || graph[i][indexY] == 1)
                {
                    foundEdge = true;
                    break;
                }
            }
        }
        if (graphForm == 2)
            if (graph[indexX][indexY] == 1)
                foundEdge = true;

        if (graphForm == 3)
            if (count(graph[indexX].begin(), graph[indexX].end(), edge.second))
                foundEdge = true;

        if (!foundEdge)
        {
            cout << "Muchia introdusa nu exista in graf!\n";
            i--;
            continue;
        }

        if (graphForm == 1)
        {
            vector<int> temp(n);
            temp[indexX] = 0;
            temp[indexY] = 0;
            graph.push_back(temp);
        }
        if (graphForm == 2)
            graph[indexX][indexY] = 0;
        if (graphForm == 3)
            graph[indexX].erase(graph[indexX].begin() + indexY);
    }
    return graph;
}

int ReadVertex(vector<int> vertices, bool flag)
{
    int vertex;

    bool found = false;
    do
    {
        cin >> vertex;
        found = count(vertices.begin(), vertices.end(), vertex);
        if (found && flag)
            cout << "Varf invalid, varful deja exista\n";
        if (!found && !flag)
        {
            cout << "Varf invalid, varful nu exista\n";
            found = true;
        }
        if (found && !flag)
            found = false;

        if (vertex <= 0)
            cout << "Varf invalid, varful nu trebuie sa fie 0\n";
    } while (vertex <= 0 || found);
    return vertex;
}

vector<vector<int>> AddVertex(vector<vector<int>> graph, vector<int> &vertices, int graphForm)
{
    cout << "Introduceti varful care doriti sa-l adaugati:";
    int vertex = ReadVertex(vertices, true);
    // int lastVertex = vertices[vertices.size() - 1];
    vertices.push_back(vertex);
    sort(vertices.begin(), vertices.end());
    int vertexIndex = find(vertices.begin(), vertices.end(), vertex) - vertices.begin();

    if (graphForm == 1)
    {
        int size = graph.size();
        for (int i = 0; i < size; i++)
            // if (vertex <= lastVertex)
            graph[i].insert(graph[i].begin() + vertexIndex, 0);
        // else
        // graph[i].push_back(0);
    }

    if (graphForm == 2)
    {
        int size = graph.size();
        for (int i = 0; i < size; i++)
            // if (vertex <= lastVertex)
            graph[i].insert(graph[i].begin() + vertexIndex, 0);
        // else
        // graph[i].push_back(0);
        vector<int> temp(vertices.size());
        graph.push_back(temp);
    }

    if (graphForm == 3)
    {
        vector<int> temp;
        if (vertex <= graph.size())
        {
            int i;
            for (i = graph.size(); i > vertexIndex; i--)
                graph[i] == graph[i - 1];
            graph[i] == temp;
        }
        else
            graph.push_back(temp);
    }
    return graph;
}

vector<vector<int>> DeleteVertex(vector<vector<int>> graph, vector<int> &vertices, int graphForm)
{
    cout << "Introduceti varful care doriti sa-l stergeti:";
    int vertex = ReadVertex(vertices, false);

    int vertexIndex = find(vertices.begin(), vertices.end(), vertex) - vertices.begin();
    vertices.erase(vertices.begin() + vertexIndex);

    // delete vertex from incident matrix
    if (graphForm == 1)
    {
        // delete adjacencie edges to vertex, //shift rows to up
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i][vertexIndex] == 1)
            {
                // for (int j = i; j < graph.size() - 1; j++)
                //     graph[j] = graph[j + 1];
                // i--;
                graph.erase(graph.begin() + i);
                i--;
            }
        }
        // delete column vertex, //shift columns to left
        // if (vertexIndex == graph[0].size() - 1)
        //     for (int i = 0; i < graph.size(); i++)
        //         graph[i].pop_back();
        // else
        //     for (int i = 0; i < graph.size(); i++)
        //         for (int j = vertexIndex; j < graph[0].size() - 1; j++)
        //             graph[i][j] = graph[i][j + 1];
        for (int i = 0; i < graph.size(); i++)
            graph[i].erase(graph[i].begin() + vertexIndex);
    }

    // delete vertex from adjancency matrix
    if (graphForm == 2)
    {
        // if (vertexIndex == graph.size() - 1)
        // {
        //     for (int i = 0; i < graph.size(); i++)
        //         graph[i].pop_back();
        //     graph.pop_back();
        // }
        // else
        // {
        //     // shift rows to up
        //     for (int i = vertexIndex; i < graph.size() - 1; i++)
        //         graph[i] = graph[i + 1];
        //     // delete column vertex, //shift columns to left
        //     for (int i = 0; i < graph.size(); i++)
        //         for (int j = vertexIndex; j < graph[0].size() - 1; j++)
        //             graph[i][j] = graph[i][j + 1];
        // }
        graph.erase(graph.begin() + vertexIndex);
        for (int i = 0; i < graph.size(); i++)
            graph[i].erase(graph[i].begin() + vertexIndex);
    }

    // delete vertex from adjacency list
    if (graphForm == 3)
    {
        // if (vertexIndex == graph.size() - 1)
        //     graph.pop_back();
        // else
        //     // shift rows to up
        //     for (int i = vertexIndex; i < graph.size() - 1; i++)
        //         graph[i] = graph[i + 1];
        graph.erase(graph.begin() + vertexIndex);
        // delete the vertex from the vertices's adjacency list
        for (int i = 0; i < graph.size(); i++)
        {
            auto iter = find(graph[i].begin(), graph[i].end(), vertex);
            if (iter != graph[i].end())
                graph[i].erase(iter);
        }
    }
    return graph;
}

vector<int> ReadVerteces(vector<int> vertices)
{
    for (int i = 0; i < vertices.size(); i++)
        vertices[i] = i + 1;
    return vertices;
}

pair<int, int> ReadEdge(int n, vector<int> vertices)
{
    int x, y;
    bool foundX;
    bool foundY;
    if (vertices.empty())
    {
        do
        {
            cin >> x >> y;
            if (x <= 0 || y <= 0 || x > n || y > n)
                cout << "Arcul introdus nu este valid!\n";
        } while (x <= 0 || y <= 0 || x > n || y > n);
        return make_pair(x, y);
    }

    do
    {
        cin >> x >> y;
        foundX = count(vertices.begin(), vertices.end(), x);
        foundY = count(vertices.begin(), vertices.end(), y);
        if (!foundX || !foundY)
            cout << "Arcul introduss nu este valid!\n";
    } while (!foundX || !foundY);

    return make_pair(x, y);
}

int ReadNumbersOfEdges(int n)
{
    int m;
    do
    {
        cin >> m;
        if (n <= 0)
            cout << "Numarul de muchii introdus nu este valida!\n";
    } while (m <= 0 );
    return m;
}

int ReadNumbersOfVertices()
{
    int n;
    do
    {
        cout << "Introduceti numarul de varfuri: ";
        cin >> n;
        if (n <= 0)
            cout << "Numarul de varfuri introdus nu este valida!";
    } while (n <= 0);
    return n;
}

vector<vector<int>> ReadGraphIncMatrix(vector<int> vertices)
{
    int n = ReadNumbersOfVertices();
    cout << "Introduceti numarul de arcuri: ";
    int m = ReadNumbersOfEdges(n);
    vector<vector<int>>
        incMat(m, vector<int>(n));

    cout << "Introduceti arcurile:\n";
    for (int i = 0; i < m; i++)
    {
        pair<int, int> edge = ReadEdge(n, vertices);
        incMat[i][edge.first - 1] = -1;
        incMat[i][edge.second - 1] = 1;
        // adjMat[v - 1][u - 1] = 1;
    }
    cout << "Graful a fost citit cu succes!\n";
    return incMat;
}

vector<vector<int>> ReadGraphAdjMatrix(vector<int> vertices)
{
    int n = ReadNumbersOfVertices();
    cout << "Introduceti numarul de arcuri: ";
    int m = ReadNumbersOfEdges(n);

    vector<vector<int>> adjMat(n, vector<int>(n));

    cout << "Introduceti arcurile:\n";
    for (int i = 0; i < m; i++)
    {
        pair<int, int> edge = ReadEdge(n, vertices);
        adjMat[edge.first - 1][edge.second - 1] = 1;
        // adjMat[v - 1][u - 1] = 1;
    }
    cout << "Graful a fost citit cu succes!\n";
    return adjMat;
}

vector<vector<int>> ReadGraphAdjList(vector<int> vertices)
{
    int n = ReadNumbersOfVertices();
    cout << "Introduceti numarul de arcuri: ";
    int m = ReadNumbersOfEdges(n);

    vector<vector<int>> adjList(n);

    cout << "Introduceti arcurile:\n";
    for (int i = 0; i < m; i++)
    {
        pair<int, int> edge = ReadEdge(n, vertices);
        adjList[edge.first - 1].push_back(edge.second);
    }
    cout << "Graful a fost citit cu succes!\n";
    return adjList;
}

void PrintGraphIncMatrix(vector<vector<int>> incMatrix, vector<int> vertexes)
{
    cout << "Matricea de incidenta a grafului:\n";
    int edges = incMatrix.size();
    int vertices = vertexes.size();

    cout << "    ";
    for (int i = 0; i < vertices; i++)
        printf("%3d ", vertexes[i]);
    cout << "\n";
    for (int i = 0; i < edges; i++)
    {
        printf("%3d ", i + 1);
        for (int j = 0; j < vertices; j++)
            printf("%3d ", incMatrix[i][j]);
        cout << "\n";
    }
}

void PrintGraphAdjMatrix(vector<vector<int>> adjMatrix, vector<int> vertexes)
{
    cout << "Matricea de adiacenta a grafului:\n";

    int vertices = vertexes.size();
    cout << "    ";
    for (int i = 0; i < vertices; i++)
        printf("%3d ", vertexes[i]);
    cout << "\n";
    for (int i = 0; i < vertices; i++)
    {
        printf("%3d ", vertexes[i]);
        for (int j = 0; j < vertices; j++)
            printf("%3d ", adjMatrix[i][j]);
        cout << "\n";
    }
}

void PrintGraphAdjList(vector<vector<int>> adjList, vector<int> vertices)
{
    cout << "Matricea de adiacenta a grafului:\n";

    int degree = vertices.size();

    for (int i = 0; i < degree; i++)
    {
        printf("%3d | ", vertices[i]);
        int verticeDegree = adjList[i].size();
        for (int j = 0; j < verticeDegree; j++)
            cout << adjList[i][j] << " ";
        cout << "0\n";
    }
}

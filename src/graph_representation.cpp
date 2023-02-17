#include "graph_operations.hpp"
#include "convert_form_graph.hpp"

void PrintMainMenu();
void PrintProcessingMenu(int);

int main()
{
    PrintMainMenu();
    vector<vector<int>> graph;
    vector<int> vertices;
    int option, graphForm = 0;
    do
    {
        cin >> option;
        switch (option)
        {
        case 1:
            system("clear");
            graph = ReadGraphIncMatrix();
            graphForm = 1;
            vertices = vector<int>(graph[0].size());
            vertices = ReadVerteces(vertices);
            PrintProcessingMenu(graphForm);
            system("clear");
            break;
        case 2:
            system("clear");
            graph = ReadGraphAdjMatrix();
            graphForm = 2;
            vertices = vector<int>(graph.size());
            vertices = ReadVerteces(vertices);
            system("clear");
            PrintProcessingMenu(graphForm);
            break;
        case 3:
            system("clear");
            graph = ReadGraphAdjList();
            graphForm = 3;
            vertices = vector<int>(graph.size());
            vertices = ReadVerteces(vertices);
            system("clear");
            PrintProcessingMenu(graphForm);
            break;
        case 4:
            system("clear");
            switch (graphForm)
            {
            case 1:
                PrintGraphIncMatrix(graph, vertices);
                break;
            case 2:
                PrintGraphAdjMatrix(graph, vertices);
                break;
            case 3:
                PrintGraphAdjList(graph, vertices);
                break;
            }
            PrintProcessingMenu(graphForm);
            break;
        case 5:
            if (graphForm == 1)
            {
                graph = FromIncMatrixToAdjMatrix(graph);
                graphForm = 2;
                system("clear");
                PrintProcessingMenu(graphForm);
                cout << "Reprezentarea grafului a fost convertita cu succes!\n";
            }
            else if (graphForm == 2)
            {
                graph = FromAdjMatrixToIncMatrix(graph);
                graphForm = 1;
                system("clear");
                PrintProcessingMenu(graphForm);
                cout << "Reprezentarea grafului a fost convertita cu succes!\n";
            }
            else if (graphForm == 3)
            {
                graph = FromAdjListToIncMatrix(graph, vertices);
                graphForm = 1;
                system("clear");
                PrintProcessingMenu(graphForm);
                cout << "Reprezentarea grafului a fost convertita cu succes!\n";
            }
            break;
        case 6:
            if (graphForm == 1)
            {
                graph = FromIncMatrixToAdjList(graph);
                graphForm = 3;
                system("clear");
                PrintProcessingMenu(graphForm);
                cout << "Reprezentarea grafului a fost convertita cu succes!\n";
            }
            else if (graphForm == 2)
            {
                graph = FromAdjMatrixToAdjList(graph);
                graphForm = 3;
                system("clear");
                PrintProcessingMenu(graphForm);
                cout << "Reprezentarea grafului a fost convertita cu succes!\n";
            }
            else if (graphForm == 3)
            {
                graph = FromAdjListToAdjMatrix(graph, vertices);
                graphForm = 2;
                system("clear");
                PrintProcessingMenu(graphForm);
                cout << "Reprezentarea grafului a fost convertita cu succes!\n";
            }
            break;
        case 7:
            system("clear");
            graph = AddVertex(graph, vertices, graphForm);
            PrintProcessingMenu(graphForm);
            cout << "Varful a fost adaugat cu succes!\n";
            break;
        case 8:
            system("clear");
            graph = AddEdges(graph, graphForm, vertices);
            PrintProcessingMenu(graphForm);
            cout << "Arcurile au fost adaugate cu succes!\n";
            break;
        case 9:
            system("clear");
            graph = DeleteVertex(graph, vertices, graphForm);
            PrintProcessingMenu(graphForm);
            cout << "Varful a fost sters cu succes!\n";
            break;
        case 10:
            system("clear");
            graph = DeleteEdges(graph, graphForm, vertices);
            PrintProcessingMenu(graphForm);
            cout << "Arcurile au fost sterse cu succes!\n";
            break;
        case 11:
            system("clear");
            PrintMainMenu();
            break;
        default:
            break;
        }
    } while (option != 0);
    return 0;
}

void PrintMainMenu()
{
    cout << "Alegeti metoda de introducere a grafului:"
         << "\n";
    cout << "1. Matricea de incidenta"
         << "\n";
    cout << "2. Matricea de adiacenta"
         << "\n";
    cout << "3. Lista de adicenta"
         << "\n";
    cout << "0. Inchideti programul"
         << "\n";
}

void PrintProcessingMenu(int graphForm)
{
    cout << "Gestionarea grafului:"
         << "\n";
    cout << "4. Afisati graful"
         << "\n";
    if (graphForm == 1)
    {
        cout << "5. Convertiti in matricea de adiacenta"
             << "\n";
        cout << "6. Convertiti in lista de adiacenta"
             << "\n";
    }
    if (graphForm == 2)
    {
        cout << "5. Convertiti in matricea de incidenta"
             << "\n";
        cout << "6. Convertiti in lista de adiacenta"
             << "\n";
    }
    if (graphForm == 3)
    {
        cout << "5. Convertiti in matricea de incidenta"
             << "\n";
        cout << "6. Convertiti in matricea de adiacenta"
             << "\n";
    }
    cout << "7. Adaugati un varf"
         << "\n";
    cout << "8. Adaugati arcuri"
         << "\n";
    cout << "9. Stergeti un varf"
         << "\n";
    cout << "10. Stergeti arcuri"
         << "\n";
    cout << "11. Inapoi la meniul principal"
         << "\n";
}

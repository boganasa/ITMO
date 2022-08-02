#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

struct Graph
{
    int number;
    list<int>* graph;
};


int Visiting(Graph g, int v, int visited[], int color[], int prev)
{
    int key = 0;

    visited[v] = 1;
    color[v] = prev;
    

    list<int>::iterator i;
    for (i = g.graph[v].begin(); i != g.graph[v].end(); i++)
    {
        if (visited[*i] == 0)
        {
            visited[v] = 1;

            key = Visiting(g, *i, visited, color, (prev + 1) % 2);
            if (key == -1)
            {
                return -1;
            }
        }
        else if ((visited[*i] == 1) && (color[*i] == color[v]))
        {
            return -1;
        }
    }

    visited[v] = -1;
    return 1;
}

int TopologicalSort(Graph g, int number)
{
    int key;
    int* visited = new int[number];
    int* color = new int[number];

    for (int i = 0; i < number; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < number; i++)
    {
        if (visited[i] == 0)
        {
            key = Visiting(g, i, visited, color, 0);
        }
        if (key == -1)
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    ifstream fcin("bipartite.in");
    ofstream fout("bipartite.out");

    int m, n, x, y, answer = 0;
    fcin >> n >> m;

    Graph g;
    g.graph = new list<int>[n];

    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        g.graph[x - 1].push_back(y - 1);
        g.graph[y - 1].push_back(x - 1);
    }

    answer = TopologicalSort(g, n);

    if (answer == -1)
    {
        fout << "NO";
    }

    else
    {
        fout << "YES";
    }


    fcin.close();
    fout.close();
    return 0;
}
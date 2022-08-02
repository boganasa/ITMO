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


int Visiting(Graph g, int v, int visited[], stack<int>& Stack)
{
    int key = 0;

    visited[v] = 1;

    list<int>::iterator i;
    for (i = g.graph[v].begin(); i != g.graph[v].end(); i++)
    {
        if (visited[*i] == 0)
        {
            visited[v] = 1;
            key = Visiting(g, *i, visited, Stack);
        }
    }

    visited[v] = -1;
    Stack.push(v);
    return 1;
}


void DFS(Graph gInvert, int number, stack<int>& Stack)
{
    int key;
    int* visited = new int[number];
    for (int i = 0; i < number; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < number; i++)
    {
        if (visited[i] == 0)
        {
            key = Visiting(gInvert, i, visited, Stack);
        }
    }
    return;
}


int VisitingComponenta(Graph gInvert, int v, int visited[], int order, int componenta[])
{
    int key = 0;

    visited[v] = 1;
    componenta[v] = order;

    list<int>::iterator i;
    for (i = gInvert.graph[v].begin(); i != gInvert.graph[v].end(); i++)
    {
        if (visited[*i] == 0)
        {
            visited[v] = 1;
            key = VisitingComponenta(gInvert, *i, visited, order, componenta);
        }
    }

    visited[v] = -1;
    return 1;
}
int DFS_componenta(Graph g, int number, stack<int>& Stack, int componenta[])
{
    int key;
    int* visited = new int[number];
    for (int i = 0; i < number; i++)
    {
        visited[i] = 0;
    }

    int order = 1;

    while (Stack.empty() == false)
    {
        if (visited[Stack.top()] == 0)
        {
            key = VisitingComponenta(g, Stack.top(), visited, order, componenta);
            order++;
        }
        Stack.pop();
    }
    return order;
}

int main()
{
    ifstream fcin("cond.in");
    ofstream fout("cond.out");

    int m, n, x, y, answer = 0;
    fcin >> n >> m;

    Graph g;
    g.graph = new list<int>[n];
    Graph gInvert;
    gInvert.graph = new list<int>[n];

    stack<int> Stack;
    int* componenta = new int[n];

    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        g.graph[x - 1].push_back(y - 1);
        gInvert.graph[y - 1].push_back(x - 1);
    }

    DFS(g, n, Stack);
    int order = DFS_componenta(gInvert, n, Stack, componenta);

    fout << order - 1 << endl;
    for (int i = 0; i < n; i++)
    {
        fout << componenta[i] << " ";
    }
  

    fcin.close();
    fout.close();
    return 0;
}
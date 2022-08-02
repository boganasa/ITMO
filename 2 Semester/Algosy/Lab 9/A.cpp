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
            if (key == -1)
            {
                return -1;
            }
        }
        else if (visited[*i] == 1)
        {
            return -1;
        }
    }
        
    visited[v] = -1;
    Stack.push(v);
    return 1;
}

int TopologicalSort(Graph g, int number, stack<int>& Stack)
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
            key = Visiting(g, i, visited, Stack);
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
    ifstream fcin("topsort.in");
    ofstream fout("topsort.out");

    int m, n, x, y, answer = 0;
    fcin >> n >> m;

    Graph g;
    g.graph = new list<int>[n];

    stack<int> Stack;

    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        g.graph[x - 1].push_back(y - 1);
    }

    answer = TopologicalSort(g, n, Stack);
    if (answer == -1)
    {
        fout << -1;
    }

    else
    {
        while (Stack.empty() == false)
        {
            fout << Stack.top() + 1 << " ";
            Stack.pop();
        }
    }
    

    fcin.close();
    fout.close();
    return 0;
}
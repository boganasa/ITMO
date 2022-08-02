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


int Visiting(Graph g, int v, int visited[], stack<int>& Stack, list<int>& path)
{
    int key = 0;

    visited[v] = 1;
    path.push_front(v);

    list<int>::iterator i;
    for (i = g.graph[v].begin(); i != g.graph[v].end(); i++)
    {
        if (visited[*i] == 0)
        {
            visited[*i] = 1;
            //path.push_front(*i);
            key = Visiting(g, *i, visited, Stack, path);
            if (key == -1)
            {
                return -1;
            }
            //path.pop_back();
        }
        else if (visited[*i] == 1)
        {
            path.push_front(*i);
            return -1;
        }
    }

    visited[v] = -1;
    Stack.push(v);
    path.pop_front();
    return 1;
}

int TopologicalSort(Graph g, int number, stack<int>& Stack, list<int>& path)
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
            key = Visiting(g, i, visited, Stack, path);
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
    ifstream fcin("cycle.in");
    ofstream fout("cycle.out");

    int m, n, x, y, answer = 0;
    fcin >> n >> m;

    Graph g;
    g.graph = new list<int>[n];

    stack<int> Stack;
    list<int> path;


    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        g.graph[x - 1].push_back(y - 1);
    }

    answer = TopologicalSort(g, n, Stack, path);
    if (answer == -1)
    {
        fout << "YES" << endl;

        while (path.back() != path.front())
        {
            path.pop_back();
        }
        path.pop_back();

        while ((path.empty() == false))
        {
                fout << path.back() + 1 << " ";
                path.pop_back();  
        }
    }

    else
    {
        fout << "NO";
    }


    fcin.close();
    fout.close();
    return 0;
}
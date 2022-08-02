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


void Visiting(Graph g, int v, int visited[], stack<int>& Stack)
{
    int key = 0;

    visited[v] = 1;

    list<int>::iterator i;
    for (i = g.graph[v].begin(); i != g.graph[v].end(); i++)
    {
        if (visited[*i] == 0)
        {
            visited[v] = 1;
            Visiting(g, *i, visited, Stack);
        }
    }
    visited[v] = -1;
    Stack.push(v);
    return;
}

void DFS(Graph g, int number, stack<int>& Stack)
{
    int* visited = new int[number];
    for (int i = 0; i < number; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < number; i++)
    {
        if (visited[i] == 0)
        {
            Visiting(g, i, visited, Stack);
        }
    }
    return;
}

int main()
{
    ifstream fcin("hamiltonian.in");
    ofstream fout("hamiltonian.out");

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

    DFS(g, n, Stack);
   
    int top, prev_top, key = 0;
    list<int>::iterator i;
    top = Stack.top();
    Stack.pop();

    while (Stack.empty() == false)
    {
        key = 0;
        prev_top = Stack.top();
        while (g.graph[top].empty() == false)
        {
            if (g.graph[top].front() == prev_top)
            {
                key = 1;
                break;
            }
            g.graph[top].pop_front();
        }
        if (key == 0)
        {
            fout << "NO";
            fcin.close();
            fout.close();
            return 0;
        }
            
        Stack.pop();
        top = prev_top;
    }
    
    fout << "YES";
    fcin.close();
    fout.close();
    return 0;
}
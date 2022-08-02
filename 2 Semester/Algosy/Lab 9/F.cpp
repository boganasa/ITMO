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


int Visiting(Graph g, int v, int visited[], int path[], int win[], int len, int s)
{
    int key = 0;
    visited[v] = 1;

    path[v] = len;
    if (g.graph[v].empty() == true)
    {
        if (path[v] % 2 == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }

    list<int>::iterator i;
    for (i = g.graph[v].begin(); i != g.graph[v].end(); i++)
    {
        if (visited[*i] == 0)
        {
            visited[v] = 1;
            key = Visiting(g, *i, visited, path, win, len + 1, s);
            if (win[*i] == 0)
            {
                win[*i] = key;
            }
            else if (win[*i] != key)
            {
                if (path[*i] % 2 == 0)
                {
                    win[*i] = 2;
                    key = 2;
                }
                else
                {
                    win[*i] = 1;
                    key = 1;
                }
            }
        }
        else
        {
            if ((path[v] - path[*i]) % 2 == 1)
            {
                key = win[*i];
            }
            else
            {
                if (path[*i] % 2 == 1)
                {
                    win[*i] = 2;
                    key = 2;
                }
                else
                {
                    win[*i] = 1;
                    key = 1;
                }
            }
        }
        if (path[v] == 0)
        {
            if (key == 1)
            {
                return 1;
            }
        }
    }
    visited[v] = -1;
   
    return key;
}

int DFS(Graph g, int number, int s, int path[], int win[])
{
    int key;
    int* visited = new int[number];
    for (int i = 0; i < number; i++)
    {
        visited[i] = 0;
    }

    key = Visiting(g, s, visited, path, win, 0, s);
   
    return key;
}

int main()
{
    ifstream fcin("game.in");
    ofstream fout("game.out");

    int m, n, s, x, y, answer = 0;
    fcin >> n >> m >> s;

    Graph g;
    g.graph = new list<int>[n];

    int* path = new int[n];
    int* win = new int[n];

    for (int i = 0; i < n; i++)
    {
        path[i] = 0;
        win[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        g.graph[x - 1].push_back(y - 1);
    }

    answer = DFS(g, n, s - 1, path, win);
   

    if (answer == 1)
    {
        fout << "First player wins";
    }
    else
    {
        fout << "Second player wins";
    }

    fcin.close();
    fout.close();
    return 0;
}

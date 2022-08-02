#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void dfs(vector <vector <int> >& graph, int v, int** d)
{
    d[v][0] = 0;
    d[v][1] = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        dfs(graph, graph[v][i], d);
    }
    for (int i = 0; i < graph[v].size(); i++)
    {
        d[v][1] += d[graph[v][i]][0];
        d[v][0] += max(d[graph[v][i]][0], d[graph[v][i]][1]);
    }
}

int main()
{
    int n;
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[2];
        a[i][0] = i;
        cin >> a[i][1];
        a[i][1]--;
    }

    vector <vector <int> > graph(n);
    int root;

    for (int i = 0; i < n; i++)
    {
        if (a[i][1] == -1)
        {
           root = a[i][0];
        }
        else
        {
            graph[a[i][1]].push_back(a[i][0]);
        }
    }
  
    int** d = new int* [n];
    for (int i = 0; i < n; i++)
    {
        d[i] = new int[2];
    }

    dfs(graph, root, d);
    cout << max(d[root][0], d[root][1]);

    return 0;
}
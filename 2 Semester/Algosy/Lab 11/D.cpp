#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

struct edge {
    int a;
    int b;
    long long cost;
};

int n, m;
long long s;
vector<edge> e;
long long INF = 9*1e18;

void dfs(int v, int* visited, vector<long long>& d, vector <vector<int> >& g) {
    visited[v] = true;
    for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++)
    {
        if (!visited[*i])
        {
            dfs(*i, visited, d, g);
        }
    }
}

int main()
{
    ifstream fcin("path.in");
    ofstream fout("path.out");

    fcin >> n >> m >> s;
    s--;
    int x, y;
    long long w;;
    vector <vector<int> > g(n);

    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y >> w;
        edge ee;
        ee.a = x - 1;
        ee.b = y - 1;
        ee.cost = w;
        e.push_back(ee);
        g[x - 1].push_back(y - 1);
    }
    int* visited = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<long long> d(n, INF);
    d[s] = 0;
    vector<long long> p(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                }
    }

    for (int j = 0; j < m; ++j)
        if (d[e[j].a] < INF)
            if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                dfs(e[j].b, visited, d, g);
            }


    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            fout << "-" << endl;
        }
        else if (d[i] == INF)
        {
            fout << "*" << endl;
        }
        else
        {
            fout << d[i] << endl;
        }
    }

    fcin.close();
    fout.close();
    return 0;
}
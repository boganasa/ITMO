#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct edge
{
    int begin;
    int end;
    int weight;
    edge(int beg, int end, int wei) : begin(beg), end(end), weight(wei) {}
};


int main()
{
    ifstream fcin("negcycle.in");
    ofstream fout("negcycle.out");
    
    int n;
    vector<edge> g;

    fcin >> n;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int x;
            fcin >> x;
            if (x != 1000000000) 
            {
                g.emplace_back(edge(i, j, x));
            }
        }
    }
    vector<int> d(n);
    vector<int> p(n, -1);
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int j = 0; j < (int)g.size(); j++)
        {
            if (d[g[j].end] > d[g[j].begin] + g[j].weight)
            {
                d[g[j].end] = max(-1000000000, d[g[j].begin] + g[j].weight);
                p[g[j].end] = g[j].begin;
                x = g[j].end;
            }
        }
    }

    if (x == -1)
    {
        fout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            x = p[x];
        }

        vector<int> path;
        int y = x;
        while (true) 
        {
            path.push_back(y);
            if ((y == x) && (path.size() > 1))
            {
                break;
            }
            y = p[y];
        }

        reverse(path.begin(), path.end());

        fout << "YES" << endl << path.size() << endl;
        for (int i : path) 
        {
            fout << i + 1 << ' ';
        }
    }

    fcin.close();
    fout.close();
    return 0;
}
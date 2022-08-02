#include <iostream>
#include <cmath>
#include <fstream>
#include <list>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;

const int INF = 100000000;
int root, n, m;
long long res;

struct Edge {
    int begin;
    int end;
    int length;
    Edge(int begin, int end, int length) :
        begin(begin), end(end), length(length) {}
};

struct graphNode {
    int root;
    int number;
    int weight;
    graphNode(int root, int number, int weight) :
        root(root), number(number), weight(weight) {}
};

void DFS(int v, vector<bool>& visited, vector<vector<graphNode>>& graph, bool flag)
{
    if (!visited[v])
    {
        visited[v] = true;
        for (graphNode& node : graph[v])
        {
            if (node.weight == 0 || !flag)
            {
                DFS(node.root, visited, graph, flag);
            }
        }
    }
}

bool Solve(vector<vector<graphNode>>* graph, bool flag)
{
    vector<bool> visited(graph->size(), false);

    DFS(root, visited, *graph, flag);
    for (bool v : visited)
    {
        if (!v)
        {
            return false;
        }
    }
    return true;
}

void DFSout(int v, vector <vector<graphNode>>& graph, vector<bool>& visited, list<int>& out)
{
    if (!visited[v])
    {
        visited[v] = true;
        for (graphNode& node : graph[v])
        {
            if (node.weight == 0)
            {
                DFSout(node.root, graph, visited, out);
            }
        }
        out.push_front(v);
    }
}

vector<vector<graphNode>>* getReverse(vector <vector<graphNode>>& graph)
{

    vector<vector<graphNode>>* res = new vector<vector<graphNode>>(graph.size());

    for (int i = 0; i < graph.size(); i++)

    {
        for (graphNode& node : graph[i])
        {
            (*res)[node.root].push_back(graphNode(i, node.number, node.weight));
        }
    }
    return res;
}

void paint(int v, int color, vector<vector<graphNode>>& graph, vector<int>& colour)
{
    if (!colour[v])
    {
        colour[v] = color;
        for (graphNode& node : graph[v])
        {
            if (node.weight == 0)
            {
                paint(node.root, color, graph, colour);
            }
        }
    }
}

vector<vector<graphNode>>* getReversedCondensation(vector<vector<graphNode>>& graph, vector<Edge>& edges)
{
    vector<bool> marked(graph.size(), false);
    list<int> outTime;


    DFSout(root, graph, marked, outTime);

    for (int i = 0; i < graph.size(); i++)
    {
        DFSout(i, graph, marked, outTime);
    }


    vector<int> colors(graph.size(), 0);
    int color = 1;

    vector<vector<graphNode>>* condensation = getReverse(graph);
    for (int& o : outTime)
    {
        if (!colors[o])
        {
            paint(o, color++, *condensation, colors);
        }
    }
    delete condensation;

    root = colors[root];
    root--;
    color--;


    vector<vector<graphNode>>* newGraph = new vector<vector<graphNode>>(color);

    for (int i = 0; i < graph.size(); i++)
    {
        for (graphNode& node : graph[i])
        {
            if (colors[i] != colors[node.root])
            {
                (*newGraph)[colors[i] - 1].push_back(
                    graphNode(colors[node.root] - 1, node.number, node.weight));
            }
        }
    }
    return newGraph;
}


void findMinWeight(vector<vector<graphNode>>* graph, vector<Edge>& edges)
{

    for (int i = 0; i < graph->size(); ++i)
    {
        int minEdge = INF;

        for (graphNode& node : (*graph)[i])
        {
            minEdge = min(minEdge, node.weight);
        }

        for (graphNode& node : (*graph)[i])
        {
            node.weight -= minEdge;
        }

        if (i != root)
            res += minEdge;
    }


    if (!Solve(getReverse(*graph), true))
    {
        vector <vector<graphNode>>* cond = getReversedCondensation(*graph, edges);
        return findMinWeight(cond, edges);
    }
}

int main()
{
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);

    root = 0;
    res = 0;

    cin >> n >> m;
    vector<vector<graphNode>>* graph = new vector<vector<graphNode>>(n);
    vector<vector<graphNode>>* reverse = new vector<vector<graphNode>>(n);
    vector<Edge> edge;

    for (int i = 0; i < m; ++i) {
        int x, y, w;

        cin >> x >> y >> w;

        edge.push_back(Edge(x - 1, y - 1, w));
        edge[i].length = w;
        (*graph)[x - 1].push_back(graphNode(y - 1, i, w));
        (*reverse)[y - 1].push_back(graphNode(x - 1, i, w));
    }

    if (Solve(graph, false)) {
        cout << "YES" << endl;
        findMinWeight(reverse, edge);
        cout << res;
    }
    else {
        cout << "NO";
    }
    return 0;
}
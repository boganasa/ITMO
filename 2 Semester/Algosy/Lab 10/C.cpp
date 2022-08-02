#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
struct edge_t {
    int begin;
    int end;
    int length;
};

void mergeSort(int l, int r, edge_t* edge)
{
    if (l == r)
    {
        return;
    }
    int middle = (l + r) / 2;
    mergeSort(l, middle, edge);
    mergeSort(middle + 1, r, edge);
    int i = l;
    int j = middle + 1;
    edge_t* c = new edge_t[r - l + 1];
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= middle) && (edge[i].length < edge[j].length)))
        {
            c[step] = edge[i];
            i++;
        }
        else
        {
            c[step] = edge[j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++)
    {
        edge[l + step] = c[step];
    }
}
/*int compare(edge_t* a, edge_t* b) {
    return a->length < b->length;;
}*/

int last_n;

int getColor(int n, int* node) {
    int color;
    if (node[n] < 0)
        return node[last_n = n];
    color = getColor(node[n], node);
    node[n] = last_n;
    return color;
}

int main() 
{
    ifstream fcin("spantree3.in");
    ofstream fout("spantree3.out");
    long long answer = 0;
    int n, m;
    cin >> n >> m;
    last_n = 0;
    int* node = new int[n];

    for (int i = 0; i < n; i++)
    {
        node[i] = -1 - i;
    }

    int x, y, w;

    edge_t* edge = new edge_t[m];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        edge[i].begin = x - 1;
        edge[i].end = y - 1;
        edge[i].length = w;
    }
  
    mergeSort(0, m - 1, edge);
    //sort(edge->begin, edge->end);
    // qsort(edge, m, sizeof(edge_t), compare);

    for (int i = 0; i < m; i++) {
        int c2 = getColor(edge[i].end, node);
        if (getColor(edge[i].begin, node) != c2) {
            node[last_n] = edge[i].end;
            answer += edge[i].length;
        }
    }
    cout << answer;
    fcin.close();
    fout.close();
    return 0;
}
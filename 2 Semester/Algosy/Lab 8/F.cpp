#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct cell
{
    char meanning;
    int length;
    int i;
    int j;
    string path;
};

struct NodeQ
{
    cell meaning;
    NodeQ* prev;
};

void push(NodeQ*& pbeg, NodeQ*& pend, cell value)
{
    NodeQ* ph = new NodeQ;
    ph->meaning = value;
    ph->prev = NULL;
    if (pend)
    {
        pend->prev = ph;
    }
    else
    {
        pbeg = ph;
    }
    pend = ph;
}

cell pop(NodeQ*& pbeg, NodeQ*& pend)
{
    if (!pbeg)
    {
        cell def;
        def.length = -5;
        return def;
    }
    cell value = pbeg->meaning;
    NodeQ* ph = pbeg;
    pbeg = pbeg->prev;
    if (!pbeg)
    {
        pend = NULL;
    }
    delete ph;
    return value;
}

void dfs(cell cage, cell** arr, int n, int m)
{
    NodeQ* pbeg = NULL;
    NodeQ* pend = NULL;

    cell ph;
    push(pbeg, pend, cage);
    ph = pop(pbeg, pend);

    while (ph.length != -5)
    {
        if (((ph.i - 1) >= 0) && (arr[ph.i - 1][ph.j].meanning != '#') && (arr[ph.i - 1][ph.j].length == -1))
        {
            arr[ph.i - 1][ph.j].length = ph.length + 1;
            arr[ph.i - 1][ph.j].path = ph.path + "U";
            push(pbeg, pend, arr[ph.i - 1][ph.j]);
            if (arr[ph.i - 1][ph.j].meanning == 'T')
            {
                return;
            }
        }
        if (((ph.i + 1) < n) && (arr[ph.i + 1][ph.j].meanning != '#') && (arr[ph.i + 1][ph.j].length == -1))
        {
            arr[ph.i + 1][ph.j].length = ph.length + 1;
            arr[ph.i + 1][ph.j].path = ph.path + "D";

            push(pbeg, pend, arr[ph.i + 1][ph.j]);
            if (arr[ph.i + 1][ph.j].meanning == 'T')
            {
                return;
            }
        }
        if (((ph.j - 1) >= 0) && (arr[ph.i][ph.j - 1].meanning != '#') && (arr[ph.i][ph.j - 1].length == -1))
        {
            arr[ph.i][ph.j - 1].length = ph.length + 1;
            arr[ph.i][ph.j - 1].path = ph.path + "L";
            push(pbeg, pend, arr[ph.i][ph.j - 1]);
            if (arr[ph.i][ph.j - 1].meanning == 'T')
            {
                return;
            }
        }
        if (((ph.j + 1) < m) && (arr[ph.i][ph.j + 1].meanning != '#') && (arr[ph.i][ph.j + 1].length == -1))
        {
            arr[ph.i][ph.j + 1].length = ph.length + 1;
            arr[ph.i][ph.j + 1].path = ph.path + "R";

            push(pbeg, pend, arr[ph.i][ph.j + 1]);
            if (arr[ph.i][ph.j + 1].meanning == 'T')
            {
                return;
            }
        }

        ph = pop(pbeg, pend);
    }
}

int main()
{
    ifstream fcin("input.txt");
    ofstream fout("output.txt");

    int n, m, index_i_s = 0, index_j_s = 0, index_i_t = 0, index_j_t = 0;
    fcin >> n >> m;
    cell** arr = new cell* [n];
  
    for (int i = 0; i < n; i++)
    {
        arr[i] = new cell [m];
        for (int j = 0; j < m; j++)
        {
            fcin >> arr[i][j].meanning;
            arr[i][j].length = -1;
            arr[i][j].i = i;
            arr[i][j].j = j;
            arr[i][j].path = "";

            if (arr[i][j].meanning == 'S')
            {
                index_i_s = i;
                index_j_s = j;
            }
            else if (arr[i][j].meanning == 'T')
            {
                index_i_t = i;
                index_j_t = j;
            }
        }
    }

    arr[index_i_s][index_j_s].length = 0;
    dfs(arr[index_i_s][index_j_s], arr, n, m);

    fout << arr[index_i_t][index_j_t].length << endl << arr[index_i_t][index_j_t].path;

    fcin.close();
    fout.close();
    return 0;
}


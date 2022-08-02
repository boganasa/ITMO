#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Node
{
    long long key;
    Node* next;
    Node* prev;
    int ind;
    int weigt;
};

void add(Node*& ptr, int data, int index)
{
    Node* ph = new Node;
    ph->key = data;
    ph->ind = index;
    ph->weigt = -1;
    if (ptr == NULL)
    {
        ph->next = NULL;
        ph->prev = NULL;
        ptr = ph;
    }
    else
    {
        ph->prev = NULL;
        ph->next = ptr;
        ptr->prev = ph;
        ptr = ph;
    }
}

struct NodeQ
{
    Node* meaning;
    NodeQ* prev;
};

void push(NodeQ*& pbeg, NodeQ*& pend, Node*& value)
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

Node* pop(NodeQ*& pbeg, NodeQ*& pend)
{
    if (!pbeg)
    {
        return NULL;
    }
    Node* value = pbeg->meaning;
    NodeQ* ph = pbeg;
    pbeg = pbeg->prev;
    if (!pbeg)
    {
        pend = NULL;
    }
    delete ph;
    return value;
}

void dfs(Node* ptr,  Node* arr[], int w[])
{
    NodeQ* pbeg = NULL;
    NodeQ* pend = NULL;
    
    Node* ph;
    Node* ph_n;
    ph = ptr; // отвечает за очередь
    while (ph != NULL)
    {
        if (w[ph->key - 1] == -1)
        {
            w[ph->key - 1] = ph->weigt + 1;
            arr[ph->key - 1]->weigt = ph->weigt + 1;
            push(pbeg, pend, arr[ph->key - 1]);
        }

        ph_n = ph;
        while (ph_n->next != NULL)
        {
            if (w[ph_n->next->key - 1] == -1)
            {
                w[ph_n->next->key - 1] = ph->weigt + 1;
                arr[ph_n->next->key - 1]->weigt = ph->weigt + 1;
                push(pbeg, pend, arr[ph_n->next->key - 1]);
            }
            ph_n = ph_n->next;
        }

        ph = pop(pbeg, pend);
    }
}


int main()
{
    ifstream fcin("pathbge1.in");
    ofstream fout("pathbge1.out");

    int n, m, x, y, k = 0;

    fcin >> n >> m;
    int* w = new int[n];


    Node* arr[30001];

    for (int i = 0; i < n; i++)
    {
        arr[i] = NULL;
        w[i] = -1;
    }


    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        if (x == y)
        {
            continue;
        }
        add(arr[x - 1], y, x - 1);
        add(arr[y - 1], x, y - 1);
    }

    arr[0]->weigt = 0;
    w[0] = 0;

    dfs(arr[0], arr, w);

    
    for (int i = 0; i < n; i++)
    {
        fout << w[i] << " ";
    }

    fcin.close();
    fout.close();
    return 0;
}
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
};

void add(Node*& ptr, int data, int index)
{
    Node* ph = new Node;
    ph->key = data;
    ph->ind = index;
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

bool exists(Node*& ptr, int data)
{
    Node* cur = ptr;
    while (cur != NULL)
    {
        if (cur->key == data)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}


void dfs(Node* ptr, int componenta[], int k, int index, Node* arr[])
{
    componenta[index] = k;

    if (componenta[ptr->key - 1] == 0)
    {
        dfs(arr[ptr->key - 1], componenta, k, ptr->key - 1, arr);
    }

    while (ptr->next != NULL)
    {
        if (componenta[ptr->next->key - 1] == 0)
        {
            dfs(ptr->next, componenta, k, ptr->next->ind, arr);
        }
        else
        {
            ptr = ptr->next;
        }

    }
}


int main()
{
    ifstream fcin("components.in");
    ofstream fout("components.out");

    int n, m, x, y, k = 0;



    fcin >> n >> m;
    int* componenta = new int[n];

  
    Node* arr[100001];
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = NULL;
        componenta[i] = 0;
    }


    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        if (x == y)
        {
            continue;
        }
        if (!exists(arr[x - 1], y))
        {
            add(arr[x - 1], y, x - 1);
        }
        if (!exists(arr[y - 1], x))
        {
            add(arr[y - 1], x, y - 1);
        }
    }

    k = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == NULL)
        {
            componenta[i] = k;
            k++;
        }
        else if (componenta[i] == 0)
        {
            dfs(arr[i], componenta, k, i, arr);
            k++;
        }

    }
    k--;

    fout << k << endl;
    for (int i = 0; i < n; i++)
    {
        fout << componenta[i] << " ";
    }
    
    fcin.close();
    fout.close();
    return 0;
}
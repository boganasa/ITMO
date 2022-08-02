#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

int binSearchLeft(int *array, int key, int n)
{
    int l = -1;
    int r = n;
    int mid;
    while (l < r - 1)
    {
        mid = (l + r) / 2;
        if (array[mid] < key)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if ((r < n) && (array[r] == key))
    {
        return r;
    }
    else
    {
        return -2;
    }
}

int binSearchRight(int *array, int key, int n)
{
    int l = -1;
    int r = n;
    int mid;
    while (l < r - 1)
    {
        mid = (l + r) / 2;
        if (array[mid] <= key)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if ((l > -1) && (array[l] == key))
    {
        return l;
    }
    else
    {
        return -2;
    }
}

int main()
{
    ifstream fcin("binsearch.in");
    ofstream fout("binsearch.out");
    int n, m;
    fcin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        fcin >> array[i];
    }
    fcin >> m;
    int search, startL = -1, startR;
    for (int i = 0; i < m; i++)
    {
        fcin >> search;
        startL = binSearchLeft(array, search, n) + 1;
        startR = binSearchRight(array, search, n) + 1;
        fout << startL << " " << startR << '\n';
    }

    fcin.close();
    fout.close();
    return 0;
}
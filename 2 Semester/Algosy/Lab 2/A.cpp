#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
void mergeSort(int l, int r, long long* a)
{
    if (l == r)
    {
        return;
    }
    int middle = (l + r) / 2;
    mergeSort(l, middle, a);
    mergeSort(middle + 1, r, a);
    int i = l;
    int j = middle + 1;
    int *c = new int [r - l + 1];
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= middle) && (a[i] < a[j])))
        {
            c[step] = a[i];
            i++;
        }
        else
        {
            c[step] = a[j];
            j++;
        }
      }
    for (int step = 0; step < r - l + 1; step++)
    {
        a[l + step] = c[step];
    }
}
int main()
{
    int n;
    ifstream fcin ("sort.in");
    fcin >> n;
    long long* a = new long long [n];
    for (int i = 0; i < n; i++)
    {
        fcin >> a[i];
    }
    mergeSort(0, n - 1, a);
    ofstream fout ("sort.out");
    for (int i = 0; i < n; i++)
    {
        fout << a[i] << " ";
    }
    fcin.close();
    fout.close();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

long long inversion = 0;

void mergeSort(long long l, long long r, long long *a)
{
    if (l == r)
    {
        return;
    }
    long long middle = (l + r) / 2;

    mergeSort(l, middle, a);
    mergeSort(middle + 1, r, a);

    long long i = l;
    long long j = middle + 1;
    long long *c = new long long [r - l + 1];
    for (long long step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= middle) && (a[i] <= a[j])))
        {
            c[step] = a[i];
            i++;

        }
        else
        {
            c[step] = a[j];
            j++;
            inversion = inversion + (middle - i + 1);
        }
      }
    for (long long step = 0; step < r - l + 1; step++)
    {
        a[l + step] = c[step];
    }
}
int main()
{
    long long n;

    ifstream fcin ("inversions.in");
    fcin >> n;

    long long* a = new long long [n];

    for (int i = 0; i < n; i++)
    {
        fcin >> a[i];
    }

    mergeSort(0, n - 1, a);

    ofstream fout ("inversions.out");
    fout << inversion;

    fcin.close();
    fout.close();
    return 0;
}

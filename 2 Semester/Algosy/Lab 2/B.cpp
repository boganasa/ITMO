#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
void mergeSort(int l, int r, string** a)
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
    string** c = new string* [r - l + 1];
    for (int step = 0; step < r - l + 1; step++)
    {
        c[step] = new string [2];
        if ((j > r) || ((i <= middle) && (a[i][0] <= a[j][0])))
        {
            c[step][0] = a[i][0];
            c[step][1] = a[i][1];
            i++;
        }
        else
        {
            c[step][0] = a[j][0];
            c[step][1] = a[j][1];
            j++;
        }
      }
    for (int step = 0; step < r - l + 1; step++)
    {
        a[l + step][0] = c[step][0];
        a[l + step][1] = c[step][1];
    }
}
int main()
{
    int n;
    ifstream fcin ("race.in");
    fcin >> n;
    string** a = new string* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new string [2];
        fcin >> a[i][0] >> a[i][1];
    }
    mergeSort(0, n - 1, a);
    ofstream fout ("race.out");
    fout << "=== " << a[0][0] << " ===" << endl << a[0][1] << endl;
    for (int i = 1; i < n; i++)
    {
        if (a[i][0] == a[i-1][0])
        {
            fout << a[i][1] << endl;
        }
        else
        {
            fout << "=== " << a[i][0] << " ===" << endl << a[i][1] << endl;
        }
    }
    fcin.close();
    fout.close();
    return 0;
}

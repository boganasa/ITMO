#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <fstream>
#include<string>
using namespace std;
void CountingSort (string *&arr, int n, int step)
{
    string *arrHelp = new string [n];
    int c [26] = {0};
    int index;
    for (int i = 0; i < n; i++)
    {
        index =int(arr[i][step]) - 'a';
        c[index]++;
    }
    for (int i = 1; i < 26; i++)
    {
        c[i]+= c[i-1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        index = int(arr[i][step])- 'a';
        arrHelp[c[index] - 1] = arr[i];
        c[index]--;
    }
    delete arr;
    arr = arrHelp;
}

int main()
{
    ifstream fcin ("radixsort.in");
    int n, m, k, step = 0;
    fcin >> n >> m >> k;
    string *arr = new string [n];
    for (int i = 0; i < n; i++)
    {
        fcin >> arr[i];
    }
    while (step < k)
    {
        CountingSort(arr, n, m - 1 - step);
        step ++;
    }
    ofstream fout ("radixsort.out");
    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << endl;
    }
    fcin.close();
    fout.close();
    return 0;
}

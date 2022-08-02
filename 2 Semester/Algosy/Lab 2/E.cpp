#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int partition(int left, int right, int *a, int k)
{
    int i, j, pivot;
    while (left < right)
    {
        i = left;
        j = right;
        pivot = a[k];
        while (i <= j)
        {
            while (a[i] < pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
            if (i <= j)
            {
                int help_tmp = a[i];
                a[i] = a[j];
                a[j] = help_tmp;
                i++;
                j--;
            }
        }
        if (j < k)
        {
            left = i;
        }
        if (k < i)
        {
            right = j;
        }
    }
    return a[k];
}
int main()
{
    srand(time(NULL));
    int n, A, B, C, k;
    ifstream fcin("kth.in");
    fcin >> n >> k;
    k--;
    int *a = new int[n];
    fcin >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++)
    {
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    }
    int rezult;
    rezult = partition(0, n - 1, a, k);
    ofstream fout("kth.out");
    fout << rezult;
    fcin.close();
    fout.close();
    return 0;
}

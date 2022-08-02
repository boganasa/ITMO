#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    ifstream fcin("isheap.in");
    long long n;
    fcin >> n;
    long long *arr = new long long[n];
    for (int i = 0; i < n; i++)
    {
        fcin >> arr[i];
    }
    int key = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if ((2 * i + 1) < n)
        {
            if (!(arr[i] <= arr[i * 2 + 1]))
            {
                key = 0;
                break;
            }
        }
        if ((2 * i + 2) < n)
        {
            if (!(arr[i] <= arr[2 * i + 2]))
            {
                key = 0;
                break;
            }
        }
        else
        {
            break;
        }
    }
    ofstream fout("isheap.out");
    if (key == 1)
    {
        fout << "YES";
    }
    else
    {
        fout << "NO";
    }
    fcin.close();
    fout.close();
    return 0;
}

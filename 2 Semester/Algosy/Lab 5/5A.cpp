#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream fcin("height.in");
    ofstream fout("height.out");

    int n, heigh = 0;
    long long k;
    fcin >> n;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[4];
        fcin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    if (n > 0)
    {
        arr[0][3] = 1;
        heigh = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] != 0)
        {
            arr[arr[i][1] - 1][3] = arr[i][3] + 1;
            if (arr[i][3] + 1 > heigh)
            {
                heigh = arr[i][3] + 1;
            }
        }
        if (arr[i][2] != 0)
        {
            arr[arr[i][2] - 1][3] = arr[i][3] + 1;
            if (arr[i][3] + 1 > heigh)
            {
                heigh = arr[i][3] + 1;
            }
        }
    }

    fout << heigh;

    fcin.close();
    fout.close();
    return 0;
}
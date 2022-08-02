#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream fcin("balance.in");
    ofstream fout("balance.out");

    int n, heigh = 0;
    long long k;
    fcin >> n;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[5];
        fcin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    if (n > 0)
    {
        arr[0][3] = 1;
        heigh = 1;
    }

    for (int i = 0; i < n; i++) //Ссылки на родителей
    {
        if (arr[i][1] != 0)
        {
            arr[arr[i][1] - 1][3] = i;
        }

        if (arr[i][2] != 0)
        {
            arr[arr[i][2] - 1][3] = i;
        }
        arr[i][4] = 1;
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[arr[i][3]][4] < arr[i][4] + 1)
        {
            arr[arr[i][3]][4] = arr[i][4] + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((arr[i][2] != 0) && (arr[i][1] != 0))
        {
            fout << arr[arr[i][2] - 1][4] - arr[arr[i][1] - 1][4] << endl;
        }
        else if (arr[i][2] != 0)
        {
            fout << arr[arr[i][2] - 1][4] << endl;
        }
        else if (arr[i][1] != 0)
        {
            fout << -arr[arr[i][1] - 1][4] << endl;
        }
        else
        {
            fout << 0 << endl;
        }
    }

    fcin.close();
    fout.close();
    return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream fcin("pathsg.in");
    ofstream fout("pathsg.out");
    long long n, m;
    fcin >> n >> m;

    long long** arr = new long long* [n];
    bool* visited = new bool[n];
    long long* len = new long long[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new long long[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 1000000000000;
            visited[i] = false;
            len[i] = 1000000000000;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, weight;
        fcin >> x >> y >> weight;   
        arr[x - 1][y - 1] = weight;
    }

    long long min = 1000000000000, min_ind = 100000000;

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (arr[i][k] < 1000000000000 && arr[k][j] < 1000000000000)
                {
                    if (arr[i][j] > arr[i][k] + arr[k][j])
                    {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }
    }
        
                    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                fout << 0 << " ";
            }
            else
            {
                fout << arr[i][j] << " ";
            }
        }
        fout << endl;
    }
    fcin.close();
    fout.close();
    return 0;
}

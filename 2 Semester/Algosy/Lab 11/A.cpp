#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream fcin("pathmgep.in");
    ofstream fout("pathmgep.out");
    long long n, s, f;
    fcin >> n >> s >> f;

    long long** arr = new long long* [n];
    bool* visited = new bool[n];
    long long* len = new long long[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new long long[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fcin >> arr[i][j];
        }
        visited[i] = false;
        len[i] = 1000000000000;
    }

    long long min = 1000000000000, min_ind = 100000000;

    len[s - 1] = 0;

    do
    {
        min = 1000000000000;
        min_ind = 100000000;
        for (int i = 0; i < n; i++)
        {
            if ((visited[i] == false) && (len[i] < min))
            {
                min = len[i];
                min_ind = i;
            }
        }

        if (min_ind != 100000000)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[min_ind][i] > 0)
                {
                    long long temp = min + arr[min_ind][i];
                    if (temp < len[i])
                    {
                        len[i] = temp;
                    }
                }
            }
            visited[min_ind] = true;
        }

    } while (min_ind < 100000000);

    if ((visited[f - 1] == false) || (len[f - 1] == 1000000000000))
    {
        fout << -1;
    }
    else
    {
        fout << len[f - 1];
    }

    fcin.close();
    fout.close();
    return 0;
}

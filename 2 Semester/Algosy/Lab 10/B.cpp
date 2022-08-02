#include <iostream>
#include <cmath>
#include <fstream>
#include <list>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    ifstream fcin("spantree.in");
    ofstream fout("spantree.out");

    int n;
    double answer = 0;
    fcin >> n;

    int inf = 1000000000;
    double** weight = new double* [n];
    bool* visited = new bool[n];
    double* minE = new double[n];
    long long** xoy = new long long* [n];
    int* select = new int[n];

    for (int i = 0; i < n; i++)
    {
        weight[i] = new double[n];
        xoy[i] = new long long[2];
        visited[i] = false;
        select[i] = -1;
        minE[i] = inf;
    }

    for (int i = 0; i < n; i++)
    {
        fcin >> xoy[i][0] >> xoy[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            weight[i][j] = sqrt(pow(xoy[i][0] - xoy[j][0], 2) + pow(xoy[i][1] - xoy[j][1], 2));
        }
        weight[i][i] = inf;
    }


    minE[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (v == -1 || minE[j] < minE[v]))
            {
                v = j;
            }
        }
        visited[v] = true;
        if (select[v] != -1)
            answer += weight[v][select[v]];
        for (int z = 0; z < n; z++) {
            if (weight[v][z] < minE[z])
            {
                minE[z] = weight[v][z];
                select[z] = v;
            }
        }             
            
    }

    fout << fixed << setprecision(20) << answer;
    fcin.close();
    fout.close();
    return 0;
}
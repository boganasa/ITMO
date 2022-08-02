#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ifstream fcin("input.txt");
    ofstream fout("output.txt");

    int m, n, x, y, answer = 0;
    fcin >> n >> m;
    
    int* weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        weight[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        fcin >> x >> y;
        weight[x - 1]++;
        weight[y - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        fout << weight[i] << " ";
    }
    
    fcin.close();
    fout.close();
    return 0;
}
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    int n;
    int rich = 0, poor = 1000001, middle = 0, rich_index, poor_index, middle_index, help;
    ifstream fcin ("sortland.in");
    fcin >> n;
    double* m = new double [n];
    int* index = new int [n];
    for (int i = 0; i < n; i++)
    {
        index[i] = i+1;
        fcin >> m[i];
        if (m[i] > rich)
        {
            rich = m[i];
            rich_index = i+1;
        }
        if (m[i] < poor)
        {
            poor = m[i];
            poor_index  = i+1;
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (m[i] > m[j])
            {
                help = m[i];
                m[i] = m[j];
                m[j] = help;
                help = index[i];
                index[i] = index[j];
                index[j] = help;
            }
        }
    }
    middle_index = index[n/2];   //Делим нацело на 2, без прибавления 1, потому что индексы идут с 0;
    ofstream fout ("sortland.out");
    fout << poor_index << " " << middle_index << " " << rich_index;
    fcin.close();
    fout.close();
    return 0;
}

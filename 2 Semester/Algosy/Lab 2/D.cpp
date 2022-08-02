#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int n, help;
    ifstream fcin ("antiqs.in");
    fcin >> n;
    long long* a = new long long [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i+1;
    }
    for (int i = 0; i < n; i++)
    {
        help = a[i];
        a[i] = a[i / 2];
        a[i / 2] = help;
    }
    ofstream fout ("antiqs.out");
    for (int i = 0; i < n; i++)
    {
        fout << a[i] << " ";
    }
    fcin.close();
    fout.close();
    return 0;
}

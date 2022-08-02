#include<iostream>
#include<stdio.h>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    int n, help;
    ifstream fcin ("smallsort.in");
    fcin >> n;
    int* mas = new int [n];
    for (int i = 0; i < n; i++)
        fcin >> mas[i];
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (mas[i] > mas[j])
            {
                help = mas[i];
                mas[i] = mas[j];
                mas[j] = help;
            }
        }
    }


    ofstream fout ("smallsort.out");
    for (int i = 0; i < n; i++)
        fout << mas[i] << " ";

}

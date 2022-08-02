#include<iostream>
#include<stdio.h>
#include<cmath>
#include<fstream>
using namespace std;
int maximum (int a, int b)
{
    if (a >= b)
        return a;
    else return b;
}
int main()
{
    int h, w;
    ifstream fcin ("turtle.in");
    ofstream fout ("turtle.out");
    fcin >> h >> w;
    int** pole_1 = new int* [h];
    int** pole_2 = new int* [h];
    for (int i = 0; i < h; i++)
    {
        pole_1[i]= new int [w];
        pole_2[i]= new int [w];
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fcin >> pole_1[i][j];
            pole_2[i][j] = pole_1[i][j];
        }
    }


    for (int j = 1; j <w; j++)
        pole_2[h-1][j] = pole_2[h-1][j-1] + pole_1[h-1][j];

    for (int i = h-2; i >= 0; i--)
        pole_2[i][0] = pole_2[i+1][0] + pole_1[i][0];

    for (int i = h-2; i >= 0; i--)
    {
        for (int j = 1; j < w; j++)
        {
            pole_2[i][j] = pole_2[i][j] + maximum(pole_2[i+1][j], pole_2[i][j-1]);
        }
    }
    fout << pole_2[0][w-1];
    fcin.close();
    fout.close();
}

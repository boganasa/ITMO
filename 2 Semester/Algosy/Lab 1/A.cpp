#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int main()
{
    int a, b;
    ifstream fcin ("aplusb.in");
    fcin >> a >> b;
    ofstream fout ("aplusb.out");
    fout << a+b;
    fcin.close();
    fout.close();
    return 0;
}

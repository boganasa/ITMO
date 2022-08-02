#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fcin("input.txt");
	ofstream fout("output.txt");

	int n, m, x, y;
	fcin >> n >> m;

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int [n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		fcin >> x >> y;
		matrix[x - 1][y - 1] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fout << matrix[i][j] << " ";
		}
		fout << endl;
	}

	fcin.close();
	fout.close();
}
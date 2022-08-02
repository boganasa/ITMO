#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fcin("input.txt");
	ofstream fout("output.txt");

	int n;
	fcin >> n;

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			fcin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if ((i == j) && (matrix[i][j] != 0))
			{
				fout << "NO";
				fcin.close();
				fout.close();
				return 0;
			}

			else if (matrix[i][j] != matrix[j][i])
			{
				fout << "NO";
				fcin.close();
				fout.close();
				return 0;
			}
		}
	}

	fout << "YES";


	fcin.close();
	fout.close();
	return 0;
}
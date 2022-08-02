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

	if (m > n * (n - 1))
	{
		fout << "YES";
		fcin.close();
		fout.close();
		return 0;
	}

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		fcin >> x >> y;
		if (matrix[x - 1][y - 1] == 1)
		{
			fout << "YES";
			fcin.close();
			fout.close();
			return 0;
		}
		matrix[x - 1][y - 1] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((i != j) && (matrix[i][j] == matrix[j][i]) && (matrix[i][j] == 1))
			{
				fout << "YES";
				fcin.close();
				fout.close();
				return 0;
			}
		}
	}

	fout << "NO";

	fcin.close();
	fout.close();
	return 0;
}
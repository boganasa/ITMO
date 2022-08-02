#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	ifstream fcin("knapsack.in");
	ofstream fout("knapsack.out");

	int s, n;
	fcin >> s >> n;
	int* a = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		fcin >> a[i];
	}
	int** A = new int*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		A[i] = new int[s + 1];
		A[i][0] = 0;
		for (int j = 0; j <= s; j++)
		{
			A[0][j] = 0;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int w = 1; w <= s; w++)
		{
			if (w >= a[k])
			{
				A[k][w] = max(A[k - 1][w], A[k - 1][w - a[k]] + a[k]);
			}
			else
			{
				A[k][w] = A[k - 1][w];
			}
		}
	}
	fout << A[n][s];

	fcin.close();
	fout.close();
	return 0;
}
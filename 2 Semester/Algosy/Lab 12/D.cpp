#include <iostream>
#include <fstream>

using namespace std;

void Tygydyk(int i, int j, int** board, int n, int m)
{
	if ((i - 1 >= 0) && (j + 2 < m))
	{
		board[i - 1][j + 2]++;
		Tygydyk(i - 1, j + 2, board, n, m);
	}
	if ((i + 1 < n) && (j + 2 < m))
	{
		board[i + 1][j + 2]++;
		Tygydyk(i + 1, j + 2, board, n, m);
	}
	if ((i + 2 < n) && (j + 1 < m))
	{
		board[i + 2][j + 1]++;
		Tygydyk(i + 2, j + 1, board, n, m);
	}
	if ((i + 2 < n) && (j - 1 >= 0))
	{
		board[i + 2][j - 1]++;
		Tygydyk(i + 2, j - 1, board, n, m);
	}
}

int main()
{
	ifstream fcin("knight2.in");
	ofstream fout("knight2.out");

	int n, m; 
	fcin >> n >> m;
	int** board = new int* [n];
	for (int i = 0; i < n; i++)
	{
		board[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			board[i][j] = 0;
		}
	}

	Tygydyk(0, 0, board, n, m);
	fout << board[n - 1][m - 1];

	fcin.close();
	fout.close();
	return 0;
}
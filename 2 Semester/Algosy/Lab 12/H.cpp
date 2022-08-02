#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;	

int main()
{
	ifstream fcin("knapsack.in");
	ofstream fout("knapsack.out");

	long long mod = 1000000000;
	int n;
	cin >> n;
	long long* a = new long long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] = a[i] % mod;
	}

	long long** L = new long long* [n];
	for (int i = 0; i < n; i++)
	{
		L[i] = new long long[n];
		for (int j = 0; j < n; j++)
		{
			L[i][j] = 0;
		}
		L[i][i] = 1;
	}
	for (int len = 1; len < n; len++)
	{
		for (int i = 0; i + len < n; i++)
		{
			int j = i + len;
			if (a[i] % mod == a[j] % mod)
			{
				L[i][j] = (L[i + 1][j] % mod + (L[i][j - 1] % mod + 1) % mod) % mod;

			}
			else
			{
				L[i][j] = ((L[i + 1][j] % mod + L[i][j - 1] % mod) % mod - L[i + 1][j - 1] % mod) % mod;
				if (L[i][j] < 0)
				{
					L[i][j] += mod;
				}
			}
		}
	}

	cout.setf(ios_base::fixed);
	cout << L[0][n - 1] % mod;

	fcin.close();
	fout.close();
	return 0;
}
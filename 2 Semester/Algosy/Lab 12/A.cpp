#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int inf = 1000000001;
	int n;
	cin >> n;
	int* a = new int[n];
	vector <int> d(n + 1, inf);
	int* pos = new int[n + 1];
	int* prev = new int[n + 1];
	int length = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		d[i] = inf;
	}
	d[n] = inf;
	d[0] = -inf;
	pos[0] = -1;

	for (int i = 0; i < n; i++)
	{
		int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());

		if (d[j - 1] < a[i] && a[i] < d[j])
		{
			d[j] = a[i];
			pos[j] = i;
			prev[i] = pos[j - 1];
			length = max(length, j);
		}
	}
	vector <int> answer;
	int p = pos[length];
	while (p != -1)
	{
		answer.push_back(a[p]);
		p = prev[p];
	}
	cout << (int)answer.size() << endl;
	for (int i = (int)answer.size() - 1; i >= 0; i--)
		cout << answer[i] << ' ';
}
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ifstream fcin("pathbgep.in");
	ofstream fout("pathbgep.out");
	long long n, m;
	long long inf = 100000000000000;

	fcin >> n >> m;
	vector < vector < pair<int, int> > > g(n);
	for (int i = 0; i < m; i++)
	{
		int beg, end, weight;
		fcin >> beg >> end >> weight;
		g[beg - 1].push_back({ end - 1, weight });
		g[end - 1].push_back({ beg - 1, weight });
	}
	

	vector<long long> len(n, inf);
	set < pair<long long, int> > queue;

	len[0] = 0;
	queue.insert(make_pair(len[0], 0));
	while (!queue.empty())
	{
		int v = queue.begin()->second;
		queue.erase(queue.begin());

		for (size_t j = 0; j < g[v].size(); j++) 
		{
			int ind = g[v][j].first;
			int	temp = g[v][j].second;
			if (len[v] + temp < len[ind])
			{
				queue.erase(make_pair(len[ind], ind));
				len[ind] = len[v] + temp;
				queue.insert(make_pair(len[ind], ind));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (len[i] == inf)
		{
			fout << 0 << " ";
		}
		else
		{
			fout << len[i] << " ";
		}
	}

	fcin.close();
	fout.close();
	return 0;
}
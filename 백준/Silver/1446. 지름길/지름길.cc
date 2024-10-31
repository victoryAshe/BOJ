#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAX = 10001;
long dist[MAX];
vector<pair<int, int>> adj[MAX];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, D;
	cin >> N >> D;
	dist[D] = D;
	for (int i = 1; i <= N; i++)
	{
		int start, end, distance;
		cin >> start >> end >> distance;
		adj[start].push_back(make_pair(end, distance));
	}
	
	for (int i = 0; i <= D; i++)
	{
		if (i > 0)
		{
			if (dist[i] == 0) dist[i] = dist[i - 1] + 1;
			else  dist[i] = min(dist[i], dist[i - 1] + 1); 
		}
		int size = adj[i].size();
		if (size == 0) continue;
		for(int j = 0; j<size; j++)
		{
			pair<int, int> cur = adj[i][j];
			if (cur.first > D) continue;
			long nextDist = dist[i] + cur.second;
			if (dist[cur.first] == 0) dist[cur.first] = nextDist;
			else dist[cur.first] = min(dist[cur.first], nextDist);
			dist[D] = min(dist[D], dist[cur.first] + D - cur.first);
		}
	}

	cout << dist[D];
	return 0;
}
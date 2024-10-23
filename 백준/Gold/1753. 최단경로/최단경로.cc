#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 20001;
int dist[MAX];
vector<pair<int, int>> adj[MAX];  // [start].(end, dist)

void Dijkstra(int start)
{
	priority_queue<pair<int, int>> PQ; // dist, end
	PQ.push(make_pair(0, start));
	while (PQ.empty() == 0)
	{
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		int size = adj[cur].size();
		for (int i = 0; i < size; i++)
		{
			int next = adj[cur][i].first;
			int nextCost = adj[cur][i].second;
			if (dist[next] == 0 || dist[next] > cost + nextCost)
			{
				dist[next] = cost + nextCost;
				PQ.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int V, E, K;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	Dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (i == K) cout << 0 << "\n";
		else if (dist[i] == 0) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}
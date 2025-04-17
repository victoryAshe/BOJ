#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long MAX = 987654321;

int N, E, v1, v2;
vector<pair<int, int>> adj[801]; //adj[start][i] = {end, cost}

long long Dijkstra(int S, int E)
{
	long long dist[801];
	fill(dist, dist + 801, MAX);
	priority_queue<pair<long long, int>> pq; // dist, end
	pq.push({ 0, S });
	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long cost = -pq.top().first;
		pq.pop();

		int size = adj[cur].size();
		for (int i = 0; i < size; i++)
		{
			int next = adj[cur][i].first;
			int nextCost = adj[cur][i].second;
			if (dist[next] > cost + nextCost)
			{
				dist[next] = cost + nextCost;
				pq.push({ -dist[next], next });
			}
		}
	}

	return dist[E];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	cin >> v1 >> v2;

	long long distBetween = Dijkstra(v1, v2);
	long long formerFirst = (v1!=1 ? Dijkstra(1, v1): 0) + distBetween + (v2!=N ? Dijkstra(v2, N) : 0);
	long long latterFirst = Dijkstra(1, v2) + distBetween + Dijkstra(v1, N);

	long long ans = min(formerFirst, latterFirst);
	if (min(formerFirst, latterFirst) >= MAX) cout << "-1";
	else cout << ans;
	
	return 0;
}
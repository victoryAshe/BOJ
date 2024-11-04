#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[1001];
vector<pair<int,int>> adj[1001]; // [start]: cost, end

void BFS(int start)
{
    bool visit[1001] = {false, };
	priority_queue<pair<long long, int>> pq;
	pq.push({0, start});
	visit[start] = true;
	while (!pq.empty())
	{
		int curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (curDist > dist[cur]) continue;
		int size = adj[cur].size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> next = adj[cur][i];
			int nextDist = curDist + next.first;
			if (!visit[next.second] || dist[next.second] >nextDist)
			{
				dist[next.second] = nextDist;
				visit[next.second] = true;
				pq.push({-dist[next.second], next.second});
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, start, end;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		adj[s].push_back(make_pair(cost, e));
	}
	cin >> start >> end;
	BFS(start);
	cout << dist[end];
	return 0;
}
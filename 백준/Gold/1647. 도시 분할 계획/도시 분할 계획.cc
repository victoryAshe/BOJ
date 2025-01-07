#include <iostream>
#include <queue>
using namespace std;

const int MAX = 10e6+1;
int parent[MAX];
int depth[MAX];
priority_queue<pair<int, pair<int, int>>> pq;

int find(int i)
{
	if (parent[i] == i) return i;
	return parent[i] = find(parent[i]);
}

void merge(int u, int v)
{
	int x = find(u);
	int y = find(v);
	if (depth[x] > depth[y]) swap(x, y);
	parent[x] = y;
	if (depth[x] == depth[y]) depth[y] ++;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		depth[i] = 1;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		pq.push({ -cost, {u,v} });
	}

	int dist = 0, lastCost = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		
		if (find(u) == find(v)) continue;
		
		merge(u, v);
		dist += cost;
		lastCost = cost;
	}

	cout << dist-lastCost;
	return 0;
}
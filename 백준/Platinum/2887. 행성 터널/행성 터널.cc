#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

const int MAX = 100'001;
using P = std::pair<int, int>;

int parent[MAX];
int depth[MAX];

P X[MAX];
P Y[MAX];
P Z[MAX];
std::priority_queue<std::pair<int, P>> edges;

long long answer = 0;

int Find(int i)
{
	if (parent[i] == i) return i;
	return parent[i] = Find(parent[i]);
}

void Merge(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u == v) return;

	if (depth[u] > depth[v]) std::swap(u, v);
	parent[u] = v;
	if (depth[u] == depth[v]) depth[v]++;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int x, y, z;
		std::cin >> x >> y >> z;

		X[i] = { x, i };
		Y[i] = { y, i };
		Z[i] = { z, i };

		parent[i] = i;
		depth[i] = 1;
	}

	sort(X + 1, X + N + 1);
	sort(Y + 1, Y + N + 1);
	sort(Z + 1, Z + N + 1);

	for (int i = 1; i < N; i++)
	{
		edges.push({ -abs(X[i + 1].first - X[i].first), {X[i].second , X[i + 1].second} });
		edges.push({ -abs(Y[i + 1].first - Y[i].first), {Y[i].second, Y[i + 1].second} });
		edges.push({ -abs(Z[i + 1].first - Z[i].first), {Z[i].second, Z[i + 1].second} });
	}

	while (!edges.empty())
	{
		int dist = -edges.top().first;
		int u = edges.top().second.first;
		int v = edges.top().second.second;
		edges.pop();
		if (Find(u) == Find(v)) continue;

		Merge(u, v);
		answer += dist;
	}

	std::cout << answer;

	return 0;
}
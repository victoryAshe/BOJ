#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100001;
int parent[MAX];
int depth[MAX];

pair<int, int> X[MAX];
pair<int, int> Y[MAX];
pair<int, int> Z[MAX]; 
priority_queue<pair<int, pair<int, int>>> edges;

long long answer = 0;

int find(int i)
{
	if (parent[i] == i) return i;
	return parent[i] = find(parent[i]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return;

	if (depth[u] > depth[v]) swap(u, v);
	parent[u] = v;
	if (depth[u] == depth[v]) depth[v]++;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N; 
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		
		X[i] = { x, i };
		Y[i] = { y, i };
		Z[i] = { z, i };

		parent[i] = i;
		depth[i] = 1;
	}

	sort(X+1, X + N + 1);
	sort(Y+1, Y + N + 1);
	sort(Z+1, Z + N + 1);

	for (int i = 1; i < N; i++)
	{
		edges.push({ -abs(X[i + 1].first - X[i].first), {X[i].second , X[i + 1].second} });
		edges.push({ -abs(Y[i + 1].first - Y[i].first), {Y[i].second, Y[i + 1].second} });
		edges.push({ -abs(Z[i + 1].first - Z[i].first), {Z[i].second, Z[i + 1].second} });
	}

	while (!edges.empty())
	{
		int dist = -edges.top().first;
		int a = edges.top().second.first;
		int b = edges.top().second.second;
		edges.pop();
		if (find(a) == find(b)) continue;

		merge(a, b);
		answer += dist;
	}

	cout << answer;

	return 0;
}
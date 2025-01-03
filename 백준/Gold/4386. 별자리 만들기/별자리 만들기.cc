#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 101;
int parent[MAX];
int depth[MAX];

pair<float, float> loc[MAX];
priority_queue <pair<float, pair<int, int>>> edges;
float answer = 0;

int find(int i)
{
	if (parent[i] == i) return i;
	return parent[i] = find(parent[i]);
}

void merge(int u, int v)
{
	int x = find(u);
	int y = find(v);

	if (x == y) return;
	if (depth[x] > depth[y]) swap(x, y);
	parent[x] = y;
	if (depth[x] == depth[y]) depth[y]++;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(2);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		float x, y;
		cin >> x >> y;
		loc[i] = { x,y };

		parent[i] = i;
		depth[i] = 1;
	}

	// make edges
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			edges.push({ -sqrtf(powf(loc[i].first - loc[j].first, 2) + powf(loc[i].second - loc[j].second, 2)), {i, j} });
		}
	}

	while (!edges.empty())
	{
		float dist = -edges.top().first;
		int a = edges.top().second.first;
		int b = edges.top().second.second;
		edges.pop();
		if (find(a) == find(b))continue;

		merge(a, b);
		answer += dist;
	}
	
	cout << answer;
	return 0;
}
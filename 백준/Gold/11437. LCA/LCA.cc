#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50'001;
const int MAXDEPTH = 17;
int N;

vector<vector<int>> adj;
int parent[MAX][MAXDEPTH];
int depth[MAX];

void DFS(int cur)
{
	for (int i = 0; i < adj[cur].size(); i++)
	{
		int next = adj[cur][i];
		if (depth[next] == -1)
		{
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			DFS(next);
		}
	}
}

int LCA(int u, int v)
{
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];
	
	for (int i = 0; diff != 0; i++)
	{
		if (diff % 2 == 1) u = parent[u][i];
		diff /= 2;
	}

	if (u != v)
	{
		for (int i = MAXDEPTH - 1; i >= 0; i--)
		{
			if (parent[u][i] != -1 && parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	return u;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	adj.resize(N+1);

	fill(depth, depth + N + 1, -1);
	depth[1] = 0;

	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DFS(1);
	for (int k = 1; k < MAXDEPTH; k++)
	{
		for (int cur = 1; cur <= N; cur++)
		{
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}

	return 0;
}
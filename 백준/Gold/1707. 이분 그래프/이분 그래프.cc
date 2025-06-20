#include <iostream>
#include <vector>
using namespace std;

bool visited[20'001];
bool color[20'001];
vector<int> adj[20'001];

bool DFS(int u, bool c)
{
	visited[u] = true;
	color[u] = c;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			if (!DFS(v, c ^ 1)) return false;
		}
		else if (color[v] == color[u]) return false;
	}
	return true;
}

void Solution()
{
	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		visited[i] = false;
		color[i] = 0;
		adj[i].clear();
	}

	for (int i = 0; i < E; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool isBipartite = true;
	for (int i = 1; i <= V; i++)
	{
		if (!visited[i] && !DFS(i, 0)) 
			isBipartite = false;
	}

	if (isBipartite) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K; cin >> K;
	for (int k = 0; k < K; k++)
	{
		Solution();
	}

	return 0;
}
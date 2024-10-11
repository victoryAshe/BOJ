#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100001;
bool visit[MAX];
vector<pair<int, int>> adj[MAX];

int startNode = 0, diameter = 0;

void DFS(int cur, int dist)
{
	visit[cur] = true;

	if (diameter < dist)
	{
		diameter = dist;
		startNode = cur;
	}

	for (auto& i : adj[cur])
	{
		if (!visit[i.first])
			DFS(i.first, dist + i.second);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N; cin >> N;

	for (int i = 0; i < N; i++)
	{
		int start; cin >> start;
		while (true)
		{
			int end, dist;  cin >> end;
			if (end == -1) break;
			cin >> dist;
			adj[start].push_back(make_pair(end, dist));
		}
	}

	DFS(1, 0);

	memset(visit, false, sizeof(visit));
	diameter = 0;
	DFS(startNode, 0);

	cout << diameter;
	return 0;
}
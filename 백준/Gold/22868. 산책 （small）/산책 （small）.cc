#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N, M;
int ans = 0;

vector<int> adj[10001];
bool visit[10001];

queue<int> Q;
int parent[10001];
int curDist[10001];

void BFS(int start, int end)
{
	visit[start] = false;
	visit[end] = false;
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			parent[i] = 0;
			curDist[i] = INF;
		}
	}
	curDist[start] = 0;
	curDist[end] = INF;

	Q.push(start);
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		if (cur == end) continue;

		for (int next : adj[cur])
		{
			int nextDist = curDist[cur] + 1;

			if (visit[next]) continue;
			if (curDist[next] <= nextDist) continue;
			parent[next] = cur;
			curDist[next] = nextDist;
			Q.push(next);
		}
	}

	ans += curDist[end];
	int cur = parent[end];
	while (cur!=0)
	{
		visit[cur] = true;
		cur = parent[cur];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A, B; cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());

	int S, E;
	cin >> S >> E;
	BFS(S, E);
	BFS(E, S);

	cout << ans;

	return 0;
}
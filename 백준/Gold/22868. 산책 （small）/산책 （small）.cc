#include <iostream>
#include <set>
#include <queue>
using namespace std;

const int INF = 1e9;

int N, M;
int ans = 0;

set<int> adj[10001];
bool visit[10001];

struct State {
	int cur = 0, prev = 0, dist = INF;
};

queue<State> Q;
State curVisit[10001];

void BFS(int start, int end)
{
	visit[start] = false;
	visit[end] = false;
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			curVisit[i].prev = 0;
			curVisit[i].dist = INF;
		}
	}
	curVisit[start] = { start,0,0 };
	curVisit[end] = { end, 0,INF };

	Q.push({ start, 0, 0 });
	while (!Q.empty())
	{
		State curState = Q.front();
		Q.pop();
		if (curState.cur == end) continue;

		for (auto it = adj[curState.cur].begin(); it != adj[curState.cur].end(); it++)
		{
			int next = *it;
			int nextDist = curState.dist + 1;

			if (visit[next]) continue;
			if (curVisit[next].dist <= nextDist) continue;
			curVisit[next] = { next, curState.cur, nextDist };
			Q.push({ next, curState.cur, nextDist });
		}
	}

	ans += curVisit[end].dist;
	State curState = curVisit[end];
	while (true)
	{
		visit[curState.cur] = true;

		if (curState.prev == 0) break;
		curState = curVisit[curState.prev];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) curVisit[i].cur = i;

	for (int i = 0; i < M; i++)
	{
		int A, B; cin >> A >> B;
		adj[A].insert(B);
		adj[B].insert(A);
	}

	int S, E;
	cin >> S >> E;
	BFS(S, E);
	BFS(E, S);

	cout << ans;

	return 0;
}
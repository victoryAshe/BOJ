#include <iostream>
using namespace std;

const long long INF = 987654321;

int N, M;
pair<pair<int, int>, int> edge[6000];
long long dist[501];

void Bellman_Ford()
{
	dist[1] = 0; // visit 처리
	// N-1번 돌아야 모든 정점에 들어가는 최소 비용 구하기 가능
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int from = edge[j].first.first;
			int to = edge[j].first.second;
			long long nextDist = dist[from] + edge[j].second;

			if (dist[from] == INF) continue;
			if (dist[to] > nextDist) dist[to] = nextDist;
		}
	}


	// 음의 사이클을 갖는지 판단하기 위해 한 번 더 탐색
	for (int i = 0; i < M; i++)
	{
		int from = edge[i].first.first;
		int to = edge[i].first.second;
		long long nextDist = dist[from] + edge[i].second;

		if (dist[from] == INF) continue;
		if (dist[to] > nextDist)
		{
			cout << "-1";
			return;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF) cout << "-1\n";
		else cout << dist[i] << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	
	cin >> N >> M;
	for (int i = 2; i <= N; i++) dist[i] = INF;
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		edge[i] = { {A,B},C };
	}

	Bellman_Ford();

	return 0;
}
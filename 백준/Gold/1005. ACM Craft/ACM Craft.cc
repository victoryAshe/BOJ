#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int N; // 정점의 개수
int inDegree[MAX]; // 각 정점의 진입차수(각 정점에 꽂히는 간선의 개수)를 저장
long long cost[MAX];
long long result[MAX];
int W;
vector<vector<int>> graph; // 인접리스트

void Input()
{
	int K;
	cin >> N >> K;

	memset(inDegree, 0, sizeof(inDegree));
	memset(cost, 0, sizeof(cost));
	memset(result, 0, sizeof(result));
	graph.assign(N + 1, vector<int>(0, 0));

	for (int i = 1; i <= N; i++) cin >> cost[i];

	for (int i = 1; i <= K; i++)
	{
		int start, end;
		cin >> start >> end;
		graph[start].emplace_back(end);
		inDegree[end]++; // 간선이 꽂히는 정점의 진입차수 올리기
	}

	cin >> W;
}

void TopologySort()
{
	queue<int> Q;

	// 진입 차수가 0인 정점들을 큐에 삽입
	for(int cur = 1; cur <= N; cur++)
	{
		if (inDegree[cur] == 0)
		{
			result[cur] = cost[cur];
			Q.push(cur);
		}
	}

	// 총 n번 실행
	for (int i = 0; i < N; i++)
	{
		// n번 실행 전 queue가 비면 사이클이 발생했다는 의미.
		if (Q.empty()) break;

		// queue에서 뽑아서 현재 방문 노드로 설정
		int cur = Q.front();
		Q.pop();
		
		int size = graph[cur].size();
		// 인접 노드들을 확인하며 진입 차수를 1씩 줄이고, 만일 진입 차수가 0이라면 push
		for (int k = 0; k < size; k++)
		{
			int next = graph[cur][k];
			result[next] = max(result[next], result[cur] + cost[next]);
			if (--inDegree[next] == 0) Q.push(next);
		}
	}
	
	cout << result[W] << "\n";
}
   
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		Input();
		TopologySort();
	}

	return 0;
}
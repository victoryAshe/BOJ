#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int inDegree[1001];
vector<int> graph[1001];
queue<int> Q;
vector<int> answer;

void TopologySort()
{
	for (int cur = 1; cur <= N; cur++)
	{
		if (inDegree[cur] == 0) Q.push(cur);
	}

	for (int i = 0; i < N; i++)
	{
		if (Q.empty())
		{
			cout << "0";
			return;
		}

		int cur = Q.front();
		answer[i] = cur;
		Q.pop();
		
		int size = graph[cur].size();
		for (int j = 0; j < size; j++)
		{
			int next = graph[cur][j];
			if (--inDegree[next] == 0) Q.push(next);
		}
	}

	for (int x : answer) cout << x << "\n";
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> N >> M;
	answer.resize(N);

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		int start = 0;
		for (int _ = 0; _ < num; _++)
		{
			int end;
			cin >> end;
			if (start != 0)
			{
				inDegree[end]++;
				graph[start].emplace_back(end);
			}

			start = end;
		}
	}

	TopologySort();
		
	return 0;
}
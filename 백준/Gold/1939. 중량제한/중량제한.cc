#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10001;
int maxCost = 0;
vector<pair<int,int>> adj[MAX];
int Start, End;

bool BFS(int curWeight)
{
	bool visit[MAX] = { false, };
	queue<int> Q;
	Q.push(Start);
	visit[Start] = true;

	while (!Q.empty())
	{
		int curFactory = Q.front();
		Q.pop();

		if (curFactory == End) return true; // 도달 O

		int size = adj[curFactory].size();
		for (int i = 0; i < size; i++)
		{
			int nextFactory = adj[curFactory][i].first;
			int nextWeight = adj[curFactory][i].second;
			if (!visit[nextFactory] && curWeight <= nextWeight)
			{
				visit[nextFactory] = true;
				Q.push(nextFactory);
			}
		}
	}
	return false; // 해당 weight를 기준으로 도달X
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		maxCost = max(maxCost, C);
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	cin >> Start >> End;

	int low = 0, high = maxCost;
	while (low <= high)
	{
		int mid = (high + low) / 2;
		if (BFS(mid)) low = mid + 1;
		else high = mid - 1;
	}

	cout << high;

	return 0;
}
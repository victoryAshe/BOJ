#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 20'001;

vector<int> adj[MAX];
int dist[MAX];

int ans = 0;
vector<int> ansArr;

void BFS()
{
	dist[1] = 0;
	priority_queue<pair<int, int>> pq; // dist, num
	pq.push(make_pair(0, 1));

	while (!pq.empty())
	{
		int curCost = -pq.top().first;
		int curNum = pq.top().second;
		pq.pop();

		int nextCost = curCost + 1;
		for (int next : adj[curNum])
		{
			if (dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push({ -nextCost, next });

				if (nextCost > ans)
				{
					ans = nextCost;
					ansArr = { next };
				}
				else if (nextCost == ans)
					ansArr.push_back(next);
			}
		}
	}

	sort(ansArr.begin(), ansArr.end());
	cout << ansArr[0] << " " << ans << " " << ansArr.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) dist[i] = INF;

	int A, B;
	for (int i = 0; i < M; i++) 
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	BFS();

	return 0;
}
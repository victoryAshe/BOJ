#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int prevNode[1001];
int dist[1001];
stack<int> returnNode;
vector<pair<int, int>> adj[1001]; // [start]: cost, end
void BFS(int start, int end)
{
	priority_queue<pair<long long, int>> pq;
	pq.push({ 0, start });
	prevNode[start] = -1;
	while (!pq.empty())
	{
		int curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (curDist > dist[cur]) continue;
		int size = adj[cur].size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> next = adj[cur][i];
			int nextDist = curDist + next.first;
			if (prevNode[next.second]==0 || dist[next.second] > nextDist)
			{
				dist[next.second] = nextDist;
				prevNode[next.second] = cur;
				pq.push({ -nextDist, next.second });
			}
		}
	}

	while (end != -1)
	{
		returnNode.push(end);
		end = prevNode[end];
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, start, end;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		adj[s].push_back(make_pair(cost, e));
	}
	cin >> start >> end;
	BFS(start, end);
	cout << dist[end] <<"\n";
	cout << returnNode.size() <<"\n";
	while (!returnNode.empty())
	{
		cout << returnNode.top() << " ";
		returnNode.pop();
	}
	return 0;
}
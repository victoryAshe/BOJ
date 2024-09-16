#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

# define MAX_SIZE 100001

int N, K;
bool visited[MAX_SIZE];

int main()
{
	cin >> N >> K;
	
	// BFS:: 내림차순 우선순위 큐
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,N });
	visited[N] = true;
	int time= 0 , x = 0;
	while (!q.empty())
	{
		time = q.top().first;
		x = q.top().second;
		q.pop();

		if (x == K) break;

		if (x * 2 < MAX_SIZE && !visited[x * 2])
		{
			q.push({ time, x * 2 });
			visited[x * 2] = true;
		}

		if (x + 1 < MAX_SIZE && !visited[x + 1])
		{
			q.push({ time + 1, x + 1 });
			visited[x + 1] = true;
		}

		if (x - 1 >= 0 && !visited[x - 1])
		{
			q.push({ time + 1, x - 1 });
			visited[x - 1] = true;
		}
	}

	cout << time;

	return 0;
}
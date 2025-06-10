#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int C, N; cin >> C >> N;

	vector<int> dp(C + 101);
	fill(dp.begin(), dp.end(), INF);
	dp[0] = 0;

	priority_queue<pair<int, int>> pq;

	int cost, customer;
	for (int i = 0; i < N; i++)
	{
		cin >> cost >> customer;
		pq.push({ customer, -cost });
	}

	while (!pq.empty())
	{
		customer = pq.top().first, cost = -pq.top().second;
		pq.pop();

		for (int cur = customer; cur <= C+100; cur++)
		{
			dp[cur] = min(dp[cur], dp[cur - customer] + cost);
			if (cur > C && dp[cur] < dp[C]) dp[C] = dp[cur];
		}
	}

	cout << dp[C];

	return 0;
}
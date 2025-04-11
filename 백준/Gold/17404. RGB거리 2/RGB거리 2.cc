#include <iostream>
using namespace std;

const int MAX = 987654321;

int cost[1001][3];
int dp[1001][3];
int ans = MAX;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int color = 0; color <= 2; color++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (i == color) dp[1][i] = cost[1][i];
			else dp[1][i] = MAX;
		}

		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
		}

		for (int i = 0; i <= 2; i++)
		{
			if (i == color) continue;
			else ans = min(ans, dp[N][i]);
		}
	}

	cout << ans;

	return 0;
}
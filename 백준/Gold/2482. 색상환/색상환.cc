#include <iostream>
using namespace std;

const int MOD = 1'000'000'003;
int dp[1002][1002];
int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < 1002; ++i)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i < N; ++i)
	{
		for (int j = 2; j <= K; ++j)
		{
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	int ans = ((dp[N - 3][K - 1] + dp[N - 1][K]) % MOD);
	cout << ans;

	return 0;
}
#include <iostream>
using namespace std;

const int MOD = 1'000'000'000;
int dp[101][10];

void DP(int n)
{
	dp[n][0] = dp[n - 1][1];
	dp[n][9] = dp[n - 1][8];
	for (int i = 1; i < 9; i++)
	{
		dp[n][i] = (dp[n - 1][i - 1] + dp[n - 1][i + 1]) % MOD;
	}
}

int main()
{
	int N; cin >> N;

	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) DP(i);

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + dp[N][i]) % MOD;
	}
	cout << sum;
	return 0;
}
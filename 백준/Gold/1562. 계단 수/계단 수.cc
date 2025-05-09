#include <iostream>
using namespace std;

const int BIT_MAX = 1 << 10;
const int MOD = 1'000'000'000;
int dp[101][10][BIT_MAX];

void DP(int n)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < BIT_MAX; j++)
		{
			int cur = j | 1 << i;
			int* p = &dp[n][i][cur];

			if (i < 9) *p = (*p + dp[n - 1][i + 1][j]) % MOD;
			if (i > 0) *p = (*p + dp[n - 1][i - 1][j]) % MOD;
		}
	}
}

int main()
{
	int N; cin >> N;

	for (int i = 1; i < 10; i++) dp[1][i][1 << i] = 1;
	for (int i = 2; i <= N; i++) DP(i);

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + dp[N][i][BIT_MAX - 1]) % MOD;
	}
	cout << sum;
	return 0;
}
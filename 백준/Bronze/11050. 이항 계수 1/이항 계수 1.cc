#include <iostream>
using namespace std;

int dp[11][11];
int DP(int n, int k)
{
	if (dp[n][k] != 0) return dp[n][k];
	if (k == 0 || k == n) return dp[n][k] = 1;
	return dp[n][k] = DP(n - 1, k - 1) + DP(n - 1, k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cout << DP(N, K);

	return 0;
}
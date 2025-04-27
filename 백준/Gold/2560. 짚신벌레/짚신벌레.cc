#include <iostream>
using namespace std;

const int MOD = 1000;
int a, b, d, N;
int dp[1'000'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> d >> N;

	for (int day = 0; day < a; day++) dp[day] = 1;
	for (int day = a; day <= N; day++)
	{
		dp[day] = (dp[day - 1] + dp[day - a]) % MOD;
		if (day >= b) dp[day] = (dp[day] - dp[day - b] + MOD) % MOD;
	}

	int answer = dp[N];
	if (N >= d) answer = (answer + MOD - dp[N - d]) % MOD;

	cout << answer;
	return 0;
}
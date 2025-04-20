#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 2001;

int n, m;
long long dp[MAX][11]; // 숫자 j개를 뽑는데 마지막 수가 i인 경우 
long long sum[MAX][11];
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i < MAX; i++) dp[i][1] = 1;

	for (int i = 1; i < MAX; i++)
	{
		for (int j = 2; j <= 10; j++)
		{
			if (i < pow(2, j - 1)) break;
			int maxK = i / 2;
			for (int k = 1; k <= maxK; k++) 
				dp[i][j] += dp[k][j - 1];
		}
	}

	int T;
	cin >> T;

	memset(sum, -1, sizeof(sum));
	for (int t = 0; t < T; t++)
	{
		cin >> n >> m;
		if (sum[m][n] == -1)
		{
			sum[m][n] = 0;
			for (int i = 1; i <= m; i++) 
				sum[m][n] += dp[i][n];
		}
		
		cout << sum[m][n] << "\n";
	}

	return 0;
}
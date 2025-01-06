#include <iostream>
#include <cmath>
using namespace std;

int dp[1001][1001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	a = "0" + a;
    b = "0" + b; // To avoid segmentation fault

	int aLen = a.length(), bLen = b.length();
	for (int i = 0; i < bLen; i++)
	{
		for (int j = 0; j < aLen; j++)
		{
			if (i == 0 || j == 0) continue;
			if (b[i] == a[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[bLen - 1][aLen - 1];
	
	return 0;
}
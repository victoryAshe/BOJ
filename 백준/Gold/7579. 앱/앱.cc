#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int dp[20000001]; // [curMemory]: curCost
pair<int, int> apps[101] = {make_pair(0,0),}; // memory, cost

bool comp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	int result = 100001;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> apps[i].first;
	for (int i = 1; i <= N; i++) cin >> apps[i].second;

	sort(apps+1, apps + N + 1, comp);

	for (int i = 1; i <= N; i++)
	{
		pair<int, int> curApp = apps[i];
		if (curApp.first < M)
		{
			int availableMemory = M - 1 + curApp.first;
			for (int j = availableMemory; j >= 1; j--)
			{
				if (dp[j] == -1) continue;
				int curMemory = j + curApp.first;
				if (dp[curMemory] == -1) dp[curMemory] = dp[j] + curApp.second;
				else dp[curMemory] = min(dp[curMemory], dp[j] + curApp.second);
				if (curMemory >= M) result = min(result, dp[curMemory]);
			}
		}
		if (dp[curApp.first] == -1) dp[curApp.first] = curApp.second;
		else dp[curApp.first] = min(dp[curApp.first], curApp.second);
		if (curApp.first >= M) result = min(result, dp[curApp.first]);
	}
	cout << result;
	return 0;
}
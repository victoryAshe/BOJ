#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 10001;
int dp[MAX]; // [curCost]: curMemory
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
			int curMaxCost = MAX - 1 - curApp.second;
			for (int i = curMaxCost; i >= 0; i--)
			{
				if (dp[i] == -1) continue;
				int curCost = i + curApp.second;
				dp[curCost] = max(dp[curCost], dp[i] + curApp.first);
				if (dp[curCost] >= M) result = min(result, curCost);
			}
		}
		dp[curApp.second] = max(dp[curApp.second], curApp.first);
		if (dp[curApp.second] >= M) result = min(result, curApp.second);
	}
	cout << result;
	return 0;
}
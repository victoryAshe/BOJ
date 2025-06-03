#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 16;
const int BIT_MAX = 1 << MAX;
const int INF = 987654321;
int W[MAX][MAX];
int dp[MAX][BIT_MAX];

int DFS(int cur, int state, int& N)
{
	if (state == (1 << N) - 1) // 탐색 완료
	{
		if (W[cur][0] == 0) return INF; // 이동 불가능
		return W[cur][0];
	}

	int &ret = dp[cur][state];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < N; i++)
	{
		if (W[cur][i] == 0) continue; // 이동 불가
		if ((state & (1 << i)) == (1 << i)) continue; // 이미 방문

		ret = min(ret, 
			W[cur][i] + DFS(i, (state | (1 << i)), N));
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
	}

	cout << DFS(0, 1, N);


	return 0;
}
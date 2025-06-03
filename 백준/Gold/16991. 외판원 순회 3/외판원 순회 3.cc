#include <iostream>
#include <cmath>
using namespace std;

typedef long double LD;
const int MAX = 16;
const int BIT_MAX = 1 << MAX;
const LD INF = 987654321.98765421L;

LD point[MAX][2];
LD W[MAX][MAX];
LD dp[MAX][BIT_MAX];

LD DFS(int cur, int state, int& N)
{
	if (state == (1 << N) - 1) // 탐색 완료
	{
		if (W[cur][0] == 0) return INF; // 이동 불가능
		return W[cur][0];
	}

	LD &ret = dp[cur][state];
	if (ret != -1.0L) return ret;
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
	cout << fixed;
	cout.precision(13);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < BIT_MAX; j++)
			dp[i][j] = -1.0L;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> point[i][0] >> point[i][1];
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			W[i][j] = 
				hypotl(point[i][0] - point[j][0], point[i][1] - point[j][1]);
		}
	}
	
	cout << DFS(0, 1, N);

	return 0;
}
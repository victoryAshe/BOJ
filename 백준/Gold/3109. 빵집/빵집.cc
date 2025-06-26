#include <iostream>
#include <stack>
using namespace std;

char board[10'001][501];

int R, C;
bool DFS(int r, int c)
{
	board[r][c] = 'x';
	if (c == C - 1) return true;

	bool result = false;
	for (int i = -1; i <= 1; i++)
	{
		if (r + i < 0 || r + i >= R) continue;
		if (board[r+i][c+1] == 'x') continue;
		result = result || DFS(r + i, c + 1);
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		cnt += DFS(i, 0);
	}
	cout << cnt;
	return 0;
}
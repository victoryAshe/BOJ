#include <iostream>
#include <queue>

struct Node { int y, x; };

const int MAX = 501;
bool board[MAX][MAX];
bool visit[MAX][MAX];
int n, m;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int drawingCnt = 0, largestArea = 0;

int BFS(int i, int j)
{
	std::queue<Node> Q;
	Q.push({ i,j });
	visit[i][j] = true;
	int curArea = 0;
	
	while (!Q.empty())
	{
		Node cur = Q.front();
		Q.pop();
		curArea++;

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m ) continue;
			if (!board[ny][nx] || visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			Q.push({ ny,nx });
		}
	}

	return curArea;
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!board[i][j] || visit[i][j]) continue;

			largestArea = std::max(largestArea, BFS(i, j));
			drawingCnt++;
		}
	}

	std::cout << drawingCnt << "\n" << largestArea;
    return 0;
}